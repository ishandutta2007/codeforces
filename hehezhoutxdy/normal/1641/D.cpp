// Problem: D. Two Arrays
// URL: https://codeforces.com/contest/1641/problem/D
// Memory Limit: 512 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
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
bitset<100001> f[333];
struct node
{
	int v[6];
	bool operator<(const node&t)const
	{
		return v[0]<t.v[0];
	}
}a[100003];
int lsh[500003],cnt;
vector<int> v[500003];
signed main()
{
	int n=read(),m=read();

	for(int i=0; i<n; ++i)
	{
		for(int j=1; j<=m; ++j)
			lsh[++cnt]=a[i].v[j]=read();
		a[i].v[0]=read();
	}
	sort(lsh+1,lsh+cnt+1);
	int len=unique(lsh+1,lsh+cnt+1)-lsh-1;
	for(int i=0; i<n; ++i)
		for(int j=1; j<=m; ++j)
			a[i].v[j]=lower_bound(lsh+1,lsh+len+1,a[i].v[j])-lsh;
	sort(a,a+n);
	for(int i=0; i<n; ++i)
		for(int j=1; j<=m; ++j)
			v[a[i].v[j]].push_back(i);
	const int B=330;
	int ans=0x7f7f7f7f;
	for(int tl=0,tr=min(B-1,n-1); tl<n; tl+=B,tr=min(tr+B,n-1))
	{
		// printf("%d %d\n",tl,tr);fflush(stdout);
		for(int i=tl; i<=tr; ++i)
			f[i-tl].set(),f[i-tl][i]=0;
		for(int i=1; i<=len; ++i) if(v[i].size()<=300)
		{
			for(int X:v[i]) if(tl<=X&&X<=tr)
				for(int Y:v[i]) 
					f[X-tl][Y]=0;
		} 
		else
		{
			bitset<100001> q;
			q.set();
			for(int j:v[i]) q[j]=0;
			for(int j:v[i]) if(tl<=j&&j<=tr) f[j-tl]&=q; 
		}
		for(int i=tl; i<=tr; ++i)
		{
			int g=f[i-tl]._Find_next(i);
			// printf("%d %d\n",i,g);
			if(g!=n) ans=min(ans,a[i].v[0]+a[g].v[0]);
		}
	}
	if(ans==0x7f7f7f7f) puts("-1"),exit(0);
	else printf("%d\n",ans);
	return 0;
}