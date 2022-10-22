// Problem: E. Arithmetic Operations
// Contest: Codeforces Round #778 (Div. 1 + Div. 2, based on Technocup 2022 Final Round)
// URL: https://codeforces.com/contest/1654/problem/E
// Memory Limit: 1024 MB
// Time Limit: 5000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
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
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
const int B=320;
int a[100003],b[100003];
int vv[200003];
signed main()
{
	int n=read(),ans=n-1;
	for(int i=1; i<=n; ++i) a[i]=read();
	for(int d=-B; d<=B; ++d)
	{
		for(int i=1; i<=n; ++i) b[i]=a[i]+d*i;
		sort(b+1,b+n+1);
		for(int l=1,r; l<=n; l=r+1)
		{
			r=l;
			while(r<n&&b[r+1]==b[r]) ++r;
			ans=min(ans,n-(r-l+1));
		}
	}
	for(int i=1; i<=n; ++i) 
	{
		for(int j=max(1ll,i-320); j<=min(n,i+320); ++j) if(i!=j)
			if((a[i]-a[j])%abs(i-j)==0)
				++vv[100000+(a[i]-a[j])/(i-j)];
		for(int j=max(1ll,i-320); j<=min(n,i+320); ++j) if(i!=j)
			if((a[i]-a[j])%abs(i-j)==0)
				ans=min(ans,n-1-vv[100000+(a[i]-a[j])/(i-j)]),
				vv[100000+(a[i]-a[j])/(i-j)]=0;
	}
	printf("%lld\n",ans);
	return 0;
}/////////////////////