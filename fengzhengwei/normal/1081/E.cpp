#include<bits/stdc++.h>
#define ll long long
#define dd double
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
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
// 
const int xx=2e5+5;
int prim[xx],mn[xx];
void pre()
{
	int cnt=0;
	for(int i=2;i<xx;i++)
	{
		if(!mn[i])mn[i]=i,prim[++cnt]=i;
		for(int j=1;j<=cnt;j++)
		{
			if(prim[j]*i>=xx)break;
			mn[i*prim[j]]=prim[j];
			if(i%prim[j]==0)break;
		}
	}
}
void get(int n,vector<int>&v)
{
	v.clear();
	v.push_back(1);
	while(n!=1)
	{
		int x=mn[n],num=0;
		while(n%x==0)num++,n/=x;
		int R=1,sz=v.size();
		for(int j=1;j<=num;j++)
		{
			R*=x;
			for(int i=0;i<sz;i++)v.push_back(v[i]*R);
		}
	}
}
int n;
ll a[xx];
int main(){
	pre();
	n=read();
	for(int i=2;i<=n;i+=2)a[i]=read();//0 
	ll lst=0;//sum=lst^2 
	for(int i=2;i<=n;i+=2)
	{
		vector<int>num;
		get(a[i],num);
		ll now=1e9,b=-1;
		for(auto it:num)
		{
			if(((it&1)+((a[i]/it)&1))&1)continue;
			int mx=max(1ll*it,a[i]/it),mn=a[i]/mx;
			if(mx==mn)continue;// 
			if((mx-mn)/2>lst)
			{
				if(now>(mx+mn)/2)
				now=(mx+mn)/2,b=(mx-mn)/2;
			}
		}
		if(b==-1)puts("No"),exit(0);
		a[i-1]=b*b-lst*lst;
		lst=now;
	}
	for(int i=1;i<=n;i++)
		if(a[i]>10000000000000ll)puts("No"),exit(0);
	puts("Yes");
	for(int i=1;i<=n;i++)cout<<a[i]<<" ";puts("");
	pc('1',1);
	return 0;
}