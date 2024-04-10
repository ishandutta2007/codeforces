#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 998244353
#define MAXN 1000001
int N,f[MAXN],g[MAXN];
int main()
{
	cin>>N;For(i,1,N)for(int j=i;j<=N;j+=i)g[j]++;
	int sum=0;For(i,1,N)f[i]=(sum+g[i])%P,sum=(sum+f[i])%P;cout<<f[N]<<endl;return 0;
}