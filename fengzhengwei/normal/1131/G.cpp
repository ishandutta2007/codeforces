#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return*s++;}
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
const int yy=250005;
const int xx=1e7+5;
char st;
int n,m,h[xx];
vector<int>hh[yy],vv[yy];
int qz[xx],hz[xx],stk[xx],top;//, 
ll f[xx],v[xx];//i 
char ed;
signed main(){
//	cerr<<abs(&st-&ed)/1024/1024<<"\n";
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		int k=read();
		for(int j=1;j<=k;j++)hh[i].push_back(read());
		for(int j=1;j<=k;j++)vv[i].push_back(read());
	}
	int q=read(),tt=0;
	while(q--)
	{
		int id=read(),mul=read();
		for(int j=0;j<hh[id].size();j++)
		{
			h[++tt]=hh[id][j];
			v[tt]=1ll*mul*vv[id][j];
		}
	}
	top=0;
	for(int i=1;i<=m;i++)
	{
		qz[i]=i;
		while(top&&stk[top]>=i-h[i]+1)qz[i]=min(qz[i],qz[stk[top--]]);
		stk[++top]=i;
	}
	top=0;
	for(int i=m;i>=1;i--)
	{
		hz[i]=i;
		while(top&&stk[top]<=i+h[i]-1)hz[i]=max(hz[i],hz[stk[top--]]);
		stk[++top]=i;
	}
	//stkq ai~ 
	for(int i=1;i<=m;i++)f[i]=8e18;
	top=0;
	stk[++top]=1;
	for(int i=1;i<=m;i++)
	{
		// 
		if(top)f[i]=min(f[i],f[stk[top]-1]+v[stk[top]]);
		// 
		f[i]=min(f[i],f[qz[i]-1]+v[i]);
		while(top&&hz[stk[top]]<=i)top--;// 
		if(i!=m)//i+1 
		{
			while(top&&hz[stk[top]]<=hz[i+1]&&f[stk[top]-1]+v[stk[top]]>=f[i]+v[i+1])top--;
			if(top&&f[stk[top]-1]+v[stk[top]]<=f[i]+v[i+1]);// 
			else stk[++top]=i+1;
		}
	}
	cout<<f[m]<<"\n";
	return 0;
}