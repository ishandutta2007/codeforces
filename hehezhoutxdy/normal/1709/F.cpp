// Problem: F. Multiset of Strings
// Contest: Codeforces - Educational Codeforces Round 132 (Rated for Div. 2)
// URL: https://codeforces.com/contest/1709/problem/F
// Memory Limit: 512 MB
// Time Limit: 6000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int long long
#define ll long long
#define ull unsigned long long
inline ull calc(const ull&x){return x-(__uint128_t(x)*9920937979283557439ull>>93)*998244353;}
const int p=998244353;
inline long long qp(long long x,int y)
{
    long long res=1;
    for(long long now=x; y; now=calc(now*now),y>>=1) 
    if(y&1) res=calc(res*now);
    return res;
}
long long A[1<<19],B[1<<19];
int rev[1<<19],N=1<<19;
inline void init()
{
    rev[0]=0,rev[1]=N>>1;
    for(int i=2,d=N>>2; i<N; i<<=1,d>>=1)
        for(int j=0; j<i; ++j) rev[i+j]=rev[j]+d;
    return ;
}
inline void NTT(long long* F,int op)
{
    for(int i=0; i<N; ++i) if(rev[i]>i) F[i]^=F[rev[i]]^=F[i]^=F[rev[i]];
    for(int len=2,M=1; len<=N; len<<=1,M<<=1)
    {
        long long w=qp(op?3:332748118,998244352/len);
        //omega(m,1)
        for(int l=0; l<N; l+=len)
        {
            long long w0=1;
            for(int i=l; i<l+M; ++i)
            {
                long long x=F[i],y=calc(w0*F[i+M]);
                ((F[i]=x+y)>=p)&&(F[i]-=p),((F[i+M]=x-y)<0)&&(F[i+M]+=p),w0=calc(w0*w);
            }
        }
    }
}
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
signed main()
{
	int n=read(),k=read(),m=read(),inv=qp(N,p-2);
	init();
	for(int i=0; i<=k; ++i) A[i]=1; 
	for(int i=1; i<=n; ++i)
	{
		NTT(A,1);
		for(int j=0; j<N; ++j) A[j]=A[j]*A[j]%p;
		NTT(A,0);
		if(i<n)
		{		for(int j=0; j<=k; ++j) A[j]=A[j]*inv%p;
		for(int j=k+1; j<=k<<1; ++j) 
			(A[k]+=A[j]*inv)%=p;
		for(int j=k+1; j<N; ++j) A[j]=0;
			for(int j=k,s=0; j>=0; --j)
				s=(s+A[j])%p,
				A[j]=(A[j]*(k-j)+s)%p;
	}
	else
		for(int j=0; j<N; ++j) A[j]=A[j]*inv%p;
	}
	if(m<=k*2) printf("%lld\n",A[m]);
	else puts("0");
	return 0;
}
//g[i]=j: iroot<=j
//dp
//g[rt]f[l]+f[r]maxg[rt]