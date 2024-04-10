// Problem: D./././././././. Treelabeling
// Contest: Codeforces
// URL: https://codeforces.com/contest/1605/problem/D
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
// #pragma GCC optimize("Ofast")
// #pragma GCC optimize("unroll-loops")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
vector<int> e[200003];
int p1[200003],p2[200003];
int v1[200003],v2[200003];
int a[200003];
int dep[200003];
int fa[2000003];
int tmp[103],ts,sdt[103];
signed main()
{
	for(int T=read();T--;)
	{
		int n=read();
		int c1=0,c2=0;
		for(int i=1; i<=n; ++i) e[i].clear();
		for(int i=1; i<n; ++i)
		{
			int x=read(),y=read();
			e[x].push_back(y);
			e[y].push_back(x);
		}
		queue<int> q;
		q.push(1);
		while(!q.empty())
		{
			int x=q.front();q.pop();
			dep[x]=dep[fa[x]]+1;
			if(dep[x]&1) p1[++c1]=x; else p2[++c2]=x;
			for(int y:e[x]) if(y!=fa[x])
				fa[y]=x,q.push(y);
		}
		int M=n;
		ts=0;
		for(int i=1,ss=1; M; ss+=i,i<<=1) if(i<M) 
			M-=i,tmp[++ts]=i,sdt[ts]=ss;
		else tmp[++ts]=M,sdt[ts]=ss,M=0;
		int cur=c1;
		for(int i=ts; i>=1; --i) if(cur>=tmp[i])
		{
			for(int q=1,qq=sdt[i]; q<=tmp[i]; ++q,++qq)
				a[p1[c1]]=qq,--c1;
			cur-=tmp[i];
		}
		else
		{
			for(int q=1,qq=sdt[i]; q<=tmp[i]; ++q,++qq)
				a[p2[c2]]=qq,--c2;
		}
		assert(c1==0),assert(c2==0);
		for(int i=1; i<=n; ++i) printf("%d ",a[i]);
		puts("");
	}
	return 0;
}