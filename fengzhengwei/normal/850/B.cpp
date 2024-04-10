#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(ll x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(ll x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
int n,x,y;
const int xx=2e6+5;
ll sum1[xx],sumv[xx];
int a;
int main(){
	n=read(),x=read(),y=read();
	int num=x/y;//numy 
	for(int i=1;i<=n;i++)a=read(),sum1[a]++,sumv[a]+=a;
	for(int i=1;i<=2000000;i++)sum1[i]+=sum1[i-1],sumv[i]+=sumv[i-1];
	ll ans=1e18;
	for(int i=2;i<=1000000;i++)
	{
		int last=0;
		ll res=0;
		for(int j=i;j<=1000000+i;j+=i)
		{
			if(i<=num)
				res+=y*(j*(sum1[j]-sum1[last])-(sumv[j]-sumv[last]));//
			else 
			{
				res+=y*(j*(sum1[j]-sum1[j-num-1])-(sumv[j]-sumv[j-num-1]));
				res+=x*(sum1[j-num-1]-sum1[last]);//
			}
			last=j;
		}
		ans=min(ans,res);
	}
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}