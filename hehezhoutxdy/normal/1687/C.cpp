// Problem: C. Sanae and Giant Robot
// Contest: Codeforces - Codeforces Round #796 (Div. 1)
// URL: https://codeforces.com/contest/1687/problem/C
// Memory Limit: 256 MB
// Time Limit: 1000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#define int long long
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[1000003];
int L[1000003],R[1000003];
vector<int> e[1000003];
int n,m,cnt;
bool vis[1000003];
bool flg[4000003];
bool pos[1000003];
void update(int nl,int nr,int l,int r,int x)
{
	if(flg[x]) return ;
	if(nr<l||r<nl) return ;
	if(nl==nr)
	{
		++cnt;
		flg[x]=1,pos[nl]=1;
		for(int i:e[nl])
			if(pos[L[i]]&&pos[R[i]]&&!vis[i])
				vis[i]=1,update(0,n,L[i],R[i],1);
		return ;
	}
	int mid=(nl+nr)>>1;
	update(nl,mid,l,r,x<<1),update(mid+1,nr,l,r,(x<<1)+1);
	flg[x]=flg[x<<1]&flg[(x<<1)+1];
	return ;
}
signed main()
{
	for(int T=read();T--;)
	{
		n=read(),m=read(),cnt=0;
		for(int i=1; i<=n; ++i) a[i]=read();
		for(int i=0; i<=m; ++i) vis[i]=0;
		for(int i=0; i<=n; ++i) pos[i]=0;
		for(int i=0; i<=n*4; ++i) flg[i]=0;
		for(int i=0; i<=n; ++i) e[i].clear();
		for(int i=1; i<=n; ++i) a[i]-=read();
		for(int i=1; i<=n; ++i) a[i]+=a[i-1];
		for(int i=1; i<=m; ++i)
			L[i]=read()-1,R[i]=read(),
			e[L[i]].push_back(i),e[R[i]].push_back(i);
		for(int i=0; i<=n; ++i) 
			if(!a[i]) update(0,n,i,i,1);
		if(cnt==n+1) puts("YES"); else puts("NO");
	}
	return 0;
}