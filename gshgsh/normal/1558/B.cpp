#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 5000001
int N,P,f[MAXN],sum[MAXN];
int main()
{
	cin>>N>>P;f[N]=sum[N]=1;
	FOR(i,N-1,1)
	{
		f[i]=sum[i+1];
		for(int j=i;j<=N;j+=i)f[i]=(f[i]+1ll*(sum[max(j,i+1)]-sum[min(j+i,N+1)]+P)*(j/i))%P;
		for(int j=i+1;j<=N;j+=i+1)f[i]=(f[i]-1ll*(sum[j]-sum[min(j+i+1,N+1)]+P)*(j/(i+1))%P+P)%P;
		sum[i]=(sum[i+1]+f[i])%P;
	}
	cout<<f[1]<<'\n';return 0;
}