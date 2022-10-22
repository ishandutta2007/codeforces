// Problem: C. Maximize the Intersections
// Contest: Codeforces - Codeforces Global Round 15
// URL: https://codeforces.com/contest/1552/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int p=998244353;
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
bool vis[100003];
int x[100003],y[100003],c;
signed main()
{
	for(int T=read();T--;)
	{
		int n=read(),m=read();
		for(int i=1; i<=n*2; ++i) vis[i]=0;
		for(int i=1; i<=m; ++i)
		{
			x[i]=read(),y[i]=read(),vis[x[i]]=vis[y[i]]=1;
			if(x[i]>y[i]) swap(x[i],y[i]);
		}		
        int ans=(n-m)*(n-m-1)/2;
		for(int i=1; i<=m; ++i)
			for(int j=1; j<=m; ++j) if(i!=j)
			{
				if(x[i]<x[j]&&x[j]<y[i]&&y[i]<y[j]) ++ans;
			}	
        for(int i=1; i<=m; ++i){
            int cnt=0;
            for(int j=x[i]+1; j<y[i];++j) 
            	if(!vis[j]) ++cnt;
            ans+=min(cnt,2*(n-m)-cnt);
        }
        printf("%lld\n",ans);
	}
	return 0;
}