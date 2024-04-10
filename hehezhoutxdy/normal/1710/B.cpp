// Problem: B. Rain
// Contest: Codeforces Round #810 (Div. 1)
// URL: https://codeforces.com/contest/1710/problem/B
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
#define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
int a[200003],b[200003],O[200003],cnt[200003];
pair<int,int> o[200003];
struct node
{
	int x,y,z;
}c[1000003];
int d[1000003],val[1000003];
signed main()
{
#define fi first
#define se second
#define mp make_pair
	for(int T=read();T--;)
	{
		int n=read(),m=read(),N=0,M=0;
		for(int i=1; i<=n; ++i) 
		{
			a[i]=read(),b[i]=read(),cnt[i]=0;
			int L=a[i]-b[i],R=a[i]+b[i];
			c[++M]=(node){L,1,-L},
			c[++M]=(node){a[i],-1,L},
			c[++M]=(node){a[i],-1,R},
			c[++M]=(node){R,1,-R},
			d[++N]=L,d[++N]=a[i],d[++N]=R;
		}	
		sort(o+1,o+n+1);
		sort(d+1,d+N+1);
		sort(c+1,c+M+1,[&](node x,node y){return x.x<y.x;});
		int sk=0,sb=0;
		for(int i=1,pos=1; i<=N; ++i)
		{
			while(pos<=M&&c[pos].x<=d[i]) 
				sk+=c[pos].y,sb+=c[pos].z,++pos;
			val[i]=sk*d[i]+sb;
		}
		for(int i=1; i<=n; ++i) o[i]=make_pair(b[i]+a[i],i);
		sort(o+1,o+n+1);
		for(int i=1; i<=n; ++i) O[i]=o[i].first;
		int tc=0;
		for(int i=1; i<=N; ++i) if(val[i]>m)
		{
			int r=val[i]-m+d[i];
			r=lower_bound(O+1,O+n+1,r)-O,tc=max(tc,r);
		}
		for(int i=1; i<tc; ++i) cnt[o[i].second]=1;
		for(int i=1; i<=n; ++i) o[i]=make_pair(b[i]-a[i],i);
		sort(o+1,o+n+1),tc=0;
		for(int i=1; i<=n; ++i) O[i]=o[i].first;
		for(int i=1; i<=N; ++i) if(val[i]>m)
		{
			int r=val[i]-m-d[i];
			r=lower_bound(O+1,O+n+1,r)-O,tc=max(tc,r);
		}
		for(int i=1; i<tc; ++i) cnt[o[i].second]=1;
		for(int i=1; i<=n; ++i) if(cnt[i]) putchar('0'); 
		else putchar('1');
		puts("");
	}
	return 0;
}