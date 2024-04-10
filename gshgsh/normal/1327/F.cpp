#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 998244353
#define MAXN 600001
int N,K,M,l[MAXN],r[MAXN],x[MAXN],a[MAXN],p[MAXN],f[MAXN],ans=1;
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get(),K=get(),M=get();For(i,1,M)l[i]=get(),r[i]=get()+1,x[i]=get();
	For(t,0,K-1)
	{
		For(i,1,N+1)a[i]=0,p[i]=0;For(i,1,M)if(x[i]>>t&1)a[l[i]]++,a[r[i]]--;else p[r[i]]=max(p[r[i]],l[i]);
		For(i,1,N+1)a[i]+=a[i-1],p[i]=max(p[i],p[i-1]);For(i,0,N+1)f[i]=0;f[0]=1;int sum=1,l=0;
		For(i,1,N+1){while(l<p[i])sum=(sum-f[l++]+P)%P;f[i]=a[i]?0:sum;sum=(sum+f[i])%P;}ans=1ll*ans*f[N+1]%P;
	}
	cout<<ans<<'\n';
}