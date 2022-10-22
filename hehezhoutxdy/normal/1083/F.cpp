// Problem: F. The Fair Nut and Amusing Xor
// Contest: Codeforces - Codeforces Round #526 (Div. 1)
// URL: https://codeforces.com/problemset/problem/1083/F
// Memory Limit: 256 MB
// Time Limit: 4000 ms
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
int ta[200003],tb[200003],a[200003],z1,z2;
const int B=450;
int f[210003],cnt[450][1<<14],tag[450];
int lid[200003],id[200003],lst[200003],cc;
int n=read()+1,k=read(),m=read();
void add(int x,int v)
{
	int l=id[x],r=lid[x%k],bl=l/B,br=r/B;
	z1-=(lst[x%k]!=0),lst[x%k]^=v,z1+=(lst[x%k]!=0);
	if(bl==br)
	{
		for(int i=l; i<=r; ++i) 
			--cnt[bl][f[i]],z2-=(f[i]!=tag[bl]),
			++cnt[bl][f[i]^=v],z2+=(f[i]!=tag[bl]);
		return ;
	}
	for(int i=l,tr=(bl+1)*B; i<tr; ++i) 
		--cnt[bl][f[i]],z2-=(f[i]!=tag[bl]),
		++cnt[bl][f[i]^=v],z2+=(f[i]!=tag[bl]);
	for(int i=bl+1; i<br; ++i)
		z2+=cnt[i][tag[i]],z2-=cnt[i][tag[i]^=v];
	for(int i=br*B; i<=r; ++i) 
		--cnt[br][f[i]],z2-=(f[i]!=tag[br]),
		++cnt[br][f[i]^=v],z2+=(f[i]!=tag[br]);
	return ;
}
signed main()
{
	for(int i=1; i<n; ++i) ta[i]=read();
	for(int i=1; i<n; ++i) tb[i]=read();
	for(int i=1; i<=n; ++i) a[i]=ta[i]^ta[i-1]^tb[i]^tb[i-1];
	char op;
	for(int i=1,t; i<=k; ++i) 
	{
		for(t=i; t+k<=n; t+=k) f[++cc]=a[t],id[t]=cc,a[t+k]^=a[t];
		f[++cc]=a[t],lid[i%k]=cc,id[t]=cc,lst[i%k]=a[t],z1+=(a[t]>0);
	}
	for(int i=1; i<n/B; ++i)
		for(int j=i*B; j<(i+1)*B; ++j)
			++cnt[i][f[j]];
	for(int i=1; i<=n; ++i) z2+=(a[i]>0);
	if(z1) puts("-1"); else printf("%d\n",z2);
	for(int x,y; m--;)
	{
		op=getchar(),x=read(),y=read();
		if(op=='a') add(x+1,ta[x]^y),add(x,ta[x]^y),ta[x]=y;
		if(op=='b') add(x+1,tb[x]^y),add(x,tb[x]^y),tb[x]=y;
		if(z1) puts("-1"); else printf("%d\n",z2);
	}
	return 0;
}