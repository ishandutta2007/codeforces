#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 998244353
#define MAXN 51
#define MAXM 100001
int N,M,l[MAXN],r[MAXN],ans[MAXM];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int solve(int x)
{
	vector<int>L(N+1),R(N+1);For(i,1,N)L[i]=(l[i]+x-1)/x,R[i]=r[i]/x;int len=M/x+1;
	vector<int>f(len),sum(len);For(i,0,len-1)sum[i]=1;For(i,1,N){For(j,0,len-1)f[j]=0;For(j,L[i],len-1)f[j]=(sum[j-L[i]]-(j>R[i]?sum[j-R[i]-1]:0)+P)%P;sum[0]=0;For(j,1,len-1)sum[j]=(sum[j-1]+f[j])%P;}
	return sum[len-1];
}
int main()
{
	N=get(),M=get();For(i,1,N)l[i]=get(),r[i]=get();
	FOR(i,M,1){ans[i]=solve(i);for(int j=i*2;j<=M;j+=i)ans[i]=(ans[i]-ans[j]+P)%P;}
	cout<<ans[1]<<'\n';return 0;
}