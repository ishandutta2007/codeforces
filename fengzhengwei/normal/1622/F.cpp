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
	(op||((*s++=c)&&s==t))&&((fwrite(buf,1,s-buf,stdout)),s=buf);
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
const int xx=1e6+5;
ll hs[xx];//Cf32767 
ll g(){return rand()|(rand()<<15);}
ll G(){return g()|(g()<<30);}
int prim[xx],vis[xx];
void pre()
{
	int cnt=0;
	for(int i=2;i<xx;i++)
	{
		if(!vis[i])
		{
			prim[++cnt]=i;
			hs[i]=G();
		}
		for(int j=1;j<=cnt;j++)
		{
			if(prim[j]*i>=xx)break;
			vis[i*prim[j]]=1;
			hs[i*prim[j]]=hs[i]^hs[prim[j]];
		}
	}
}
int main(){
	pre();
	srand(time(0));
	int n=read();
	if(n==1)
	{
		cout<<1<<"\n";
		cout<<1<<"\n";
		exit(0);
	}
	for(int i=1;i<=n;i++)hs[i]^=hs[i-1];
	ll ans=0;
	for(int i=1;i<=n;i++)ans^=hs[i];
	for(int i=1;i<=n;i++)
	{
		if(ans==hs[i])
		{
			cout<<n-1<<'\n';
			for(int k=1;k<=n;k++)if(i!=k)cout<<k<<" ";
			puts("");exit(0);
		}
	}
	map<ll,int>mp;
	for(int i=1;i<=n;i++)mp[hs[i]]=i;
	for(int i=1;i<=n;i++)
	{
		if(mp.find(ans^hs[i])!=mp.end())
		{
			cout<<n-2<<'\n';
			int id=mp[ans^hs[i]];
//			cout<<i<<" "<<id<<" "<<ans<<" "<<(ans^hs[i]^hs[id])<<"QWE\n";
//			exit(0);
			for(int k=1;k<=n;k++)if(i!=k&&k!=id)cout<<k<<" ";
			puts("");exit(0);
		}
	}
	ans^=hs[n];
	n--;
	mp.clear();
	for(int i=1;i<=n;i++)
	{
		if(ans==hs[i])
		{
//			puts("QWETTRe");
			cout<<n-1<<'\n';
			for(int k=1;k<=n;k++)if(i!=k)cout<<k<<" ";
			puts("");exit(0);
		}
	}
	for(int i=1;i<=n;i++)mp[hs[i]]=i;
	for(int i=1;i<=n;i++)
	{
//		cout<<ans<<" "<<(ans^hs[i])<<"!!\n";
		if(mp.find(ans^hs[i])!=mp.end())
		{
			cout<<n-2<<'\n';
			int id=mp[ans^hs[i]];
			for(int k=1;k<=n;k++)if(i!=k&&k!=id)cout<<k<<" ";
			puts("");exit(0);
		}
	}
	
	pc('1',1);
	return 0;
}