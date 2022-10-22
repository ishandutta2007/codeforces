// Problem: G. The Sum of Good Numbers
// Contest: Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
// URL: https://codeforces.com/problemset/problem/1598/G
// Memory Limit: 256 MB
// Time Limit: 2000 ms
// 
// Powered by CP Editor (https://cpeditor.org)

//And in that light,I find deliverance.
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
using namespace std;
#define int __int128
#define I signed
#define L uint64_t
inline int read(){
   int s=0,w=1;
   char ch=getchar();
   while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
   while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
   return s*w;
}
mt19937_64 rnd(chrono::steady_clock::now().time_since_epoch().count());
int qp(int x,int y,int p)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
const L G=5e17;
bool MR(int x,int p){
	for(int t,k=x-1; !(k&1);)
	{
		k>>=1,t=qp(p,k,x);
		if(t!=1&&t!=x-1) return 0;
		if(t==x-1) return 1;
	}
	return 1;
}
const int P[10]={2,3,5,7,11,13,19,61,2333,24251};
bool isp(int x){
	if(x<3) return (x==2);
	for(int i=0; i<10; ++i) 
	{
		if(x==P[i]) return 1;
		if(x%P[i]==0) return 0;
		if(qp(P[i]%x,x-1,x)!=1) return 0;
		if(!MR(x,P[i]%x)) return 0;
	}
	return 1;
}
int rndp()
{
	int res=rnd()%G+G;
	while(!isp(res)) res=rnd()%G+G;
	return res;
}
const int p=rndp();
int qp(int x,int y)
{
	int res=1;
	for(int t=x; y; y>>=1,t=t*t%p) if(y&1) res=res*t%p;
	return res;
}
const int b=10,ib=qp(b,p-2);
int ps[500003],pt[500003],pw[500003],ipw[500003];
char s[500003],t[500003];
struct custom_hash 
{
    static uint64_t splitmix64(uint64_t x) 
    {
        x+=0x9e3779b97f4a7c15;
        x=(x^(x>>30))*0xbf58476d1ce4e5b9;
        x=(x^(x>>27))*0x94d049bb133111eb;
        return x^(x>>31);
    }
    size_t operator()(uint64_t x)const 
    {
        static const uint64_t FIXED_RANDOM=chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x+FIXED_RANDOM);
    }
};
unordered_map<L,L,custom_hash> mp;
//H(l,r)=sum[r]-sum[l]*pw[r-l]
signed main() 
{
	// printf("%lld\n",(L)p);
    scanf("%s",s+1),scanf("%s",t+1);
    int n=strlen(s+1),m=strlen(t+1);
    pw[0]=ipw[0]=1;
    for(int i=1; i<=n; ++i) 
    	pw[i]=pw[i-1]*b%p,ipw[i]=ipw[i-1]*ib%p;
    for(int i=1; i<=n; ++i)
        ps[i]=(ps[i-1]*10+s[i]-48)%p;
    for(int i=1; i<=m; ++i)
        pt[i]=(pt[i-1]*10+t[i]-48)%p;
    int sum=pt[m];
    //second >= m-1
    for(int i=1; i<=n; ++i)
    {
        mp[(L)(ps[i-1]*ipw[i-1]%p)]=i;
        for(int j=max(i+m-1,i+1); j<=i+m&&j<=n; ++j)
        {
            int v=((p<<1)+ps[i]+ps[j]-sum-ps[i]*pw[j-i]%p)%p*ipw[i]%p;
            if(mp.find((L)v)!=mp.end()) 
            	printf("%d %d\n",(I)mp[v],(I)i),
            	printf("%d %d\n",(I)i+1,(I)j),exit(0);
        }
    }
    //first = m
    for(int i=1; i<=n-m+1; ++i)
    {
        int l=1,r=m,LCP=0;
        while(l<=r) 
        {
            int mid=(l+r)>>1;
            if((p+ps[i+mid-1]-ps[i-1]*pw[mid]%p)%p==pt[mid]) LCP=mid,l=mid+1;
            else r=mid-1;
        }
        int j=i+m-1,v=(sum+p-ps[j]+ps[i-1]*pw[m]%p)%p;
        for(int t=m-LCP-1; t<=m-LCP; ++t) 
        	if(t&&j+t<=n&&(p+ps[j+t]-ps[j]*pw[t]%p)%p==v)
            	printf("%d %d\n",(I)i,(I)j),
            	printf("%d %d\n",(I)j+1,(I)j+(I)t),exit(0);
    }
    return 0;
}