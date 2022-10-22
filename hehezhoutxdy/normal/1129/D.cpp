// Problem: CF1129D Isolation
// Contest: Luogu
// URL: https://www.luogu.com.cn/problem/CF1129D
// Memory Limit: 250 MB
// Time Limit: 3000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
// #define int long long
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
const int B=320,p=998244353;
int mn[320],tag[320],v[100003],a[110003],f[320][320];
int llst[100003],lst[100003];
void remake(int x)
{
	int l=x*B,r=(x+1)*B-1;
	mn[x]=0x3f3f3f3f;
	for(int i=l; i<=r; ++i)
		(mn[x]>v[i])&&(mn[x]=v[i]);
	memset(f[x],0,sizeof(f[x]));
	for(int i=l; i<=r; ++i)
		// assert(v[i]-mn[x]<B),
		f[x][v[i]-mn[x]]=(f[x][v[i]-mn[x]]+a[i])%p;
	for(int i=1; i<B; ++i)
		f[x][i]=(f[x][i]+f[x][i-1])%p;
	return ;
}
void update(int l,int r,int k)
{
	// printf("%d %d %d\n",l,r,k);
	int bl=l/B+1,br=r/B;
	if(bl>br)
	{
		for(int i=l; i<=r; ++i) v[i]+=k;
		remake(br);
		return ;
	}
	for(int i=l,tr=bl*B; i<tr; ++i) v[i]+=k;
	for(int i=br*B; i<=r; ++i) v[i]+=k;
	for(int i=bl; i<br; ++i) tag[i]+=k; 
	remake(bl-1),remake(br);
	return ;
}
signed main()
{
	int n=read(),m=read();
	f[0][0]=a[0]=1;
	for(int i=1,x; i<=n; ++i) 
	{
		x=read();
		update(llst[x],lst[x]-1,-1),
		update(lst[x],i-1,1),
		llst[x]=lst[x],lst[x]=i;
		for(int j=0; j<=i/B; ++j)
			(m-mn[j]-tag[j]>=0)&&
			(a[i]=(a[i]+f[j][min(B-1,m-mn[j]-tag[j])])%p);
		remake(i/B);
	}
	printf("%d\n",a[n]);
	return 0;
}