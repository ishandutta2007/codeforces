#include<bits/stdc++.h>
#define ll long long 
#define dd double
using namespace std;
char gc(){static char buf[1<<20],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc(x%10+'0',0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
#define u unsigned 
u ksm(u a,int b)
{
	u ans=1;
	while(b)
	{
		if(b&1)ans*=a;
		a*=a,b>>=1;
	}
	return ans;
}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
u C(int n,int m)
{
	if(m>n||m<0)return 0;
	vector<int>v;
	for(int i=1;i<=m;i++)v.push_back(n-i+1);
	for(int i=1;i<=m;i++)
	{
		int rem=i;
		for(auto &it:v)
		{
			int d=gcd(rem,it);
			it/=d,rem/=d;
		}
	}
	u ans=1;
//	for(auto it:v)cout<<it<<"!!\n";
	for(auto it:v)ans*=it;
	return ans;
}
int n,p,q;
const int xx=205;
u _C[xx];
int main(){
	n=read(),p=read(),q=read();
	p=min(p,n-1);
	for(int i=0;i<=p;i++)_C[i]=C(n,i);
//	,cerr<<_C[i]<<"!!\n";
	u ans=0;
	for(int i=1;i<=q;i++)
	{
		u res=0,pw=1;
		for(int d=0;d<=p;d++)
			res+=_C[d]*pw,pw*=i;
		ans^=(res*i);
	}
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}