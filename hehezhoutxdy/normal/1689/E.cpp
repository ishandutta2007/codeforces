// Problem: E. ANDfinity
// Contest: Codeforces - Codeforces Round #798 (Div. 2)
// URL: https://codeforces.com/problemset/problem/1689/E
// Memory Limit: 256 MB
// Time Limit: 4000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[2003],n,ans,x,s;
bool vis[2003];
int fa[2003];
void dfs(int x)
{
	vis[x]=1,++s;
	for(int i=1; i<=n; ++i) 
		if((a[i]&a[x])&&!vis[i])
			dfs(i);
	return ;
}
int L(int x){return x&(-x);}
int find(int x){return fa[x]==x?x:(fa[x]=find(fa[x]));}
bool chk()
{
	for(int i=1; i<=n; ++i) fa[i]=i;
	for(int s=1; s<=536870912; s<<=1)
	{
		int fir=n;
		for(int i=1; fir==n&&i<n; ++i) if(a[i]&s) fir=i;
		int A=find(fir);
		for(int i=fir+1; i<=n; ++i) if(a[i]&s) fa[find(i)]=A;
	}
	for(int i=2; i<=n; ++i) if(find(i)!=find(1)) return 0;
	return 1;
}
signed main()
{
	for(int T=read();T--;)
	{
		n=read(),ans=x=s=0;
		for(int i=1; i<=n; ++i) vis[i]=0;
		for(int i=1; i<=n; ++i)
			(!(a[i]=read()))&&(++ans,a[i]=1),
			x=max(x,L(a[i]));
		dfs(1);
		if(s==n) 
		{
			printf("%d\n",ans);
			for(int i=1; i<=n; ++i) printf("%d ",a[i]);
			puts("");
		}
		else
		{
			int ovo=1;
			for(int i=1; i<=n; ++i)
			{
				//check: --a[i]
				--a[i];
				if(chk()){ovo=0;break;}
				//check: ++a[i]
				++a[i],++a[i];
				if(chk()){ovo=0;break;}
				--a[i];
			}
			if(!ovo)
			{
			printf("%d\n",ans+1);
			for(int i=1; i<=n; ++i) printf("%d ",a[i]);
			puts("");
			continue;
			}
			for(int i=1; i<=n; ++i) 
				if(L(a[i])==x)
				{
					if(ovo) 
						--a[i],ovo=0;
					else
					{
						++a[i];
						break;
					}
				}
			printf("%d\n",ans+2);
			for(int i=1; i<=n; ++i) printf("%d ",a[i]);
			puts("");
		}
	}
	return 0;
}