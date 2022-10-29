#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
#include<vector>
#include<set>
#include<map>
#include<bitset>
#include<cmath>
#include<string>

#define ls (t<<1)
#define rs ((t<<1)+1)
#define mid ((l+r)>>1)
#define fi first
#define se second
#define mk make_pair
#define pb push_back

#define N 1000005
#define M 200005
#define seed 23333

using namespace std;
int i,j,m,p,prime[N],vis[N];
long long n,k;
long long phi(long long n)
{
		int i; long long x;
		for (i=1,x=n;1ll*prime[i]*prime[i]<=x;++i)
				if (x%prime[i]==0)
				{
						n/=prime[i];
						n*=(prime[i]-1);
						while (x%prime[i]==0) x/=prime[i];
				}
		if (x>1) n/=x,n*=(x-1);
		return n; 
}
long long dfs(long long n,long long k)
{
		if (n==1) return 1;
		if (k==1) return phi(n);
		if (k%2==0) return dfs(n,k-1);
		return dfs(phi(n),k-1); 
}
int main()
{
		scanf("%I64d%I64d",&n,&k);
		for (i=2;i<N;++i)
		{
				if (!vis[i])	prime[++prime[0]]=i;
				for (j=1;i*prime[j]<N;++j)
				{
						vis[i*prime[j]]=1;
						if (i%prime[j]==0) break;
				}
		}
		printf("%I64d\n",dfs(n,k)%1000000007);
}