#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath> 
#include <ctime>
#include <algorithm>
#include <set>
#include <map>
#include <queue>
#define maxn 105
#define ll long long
using namespace std;
const int mod = 1000000007;
int n;
ll ksm(ll a, ll b)
{
	if(!b) return 1;
	ll ns = ksm(a, b >> 1);
	ns = ns * ns % mod;
	if(b & 1) ns = ns * a % mod;
	return ns;
}
ll a[maxn][maxn];
ll ans[maxn]; 
bool work1(int n)
{	//1 ~ n - 1 
	for(int i = 1; i <= n - 1; i++)
	{
		bool flag = 0;
		for(int j = i; j <= n - 1; j++)
			if(a[j][i]) 
			{
				for(int k = 1; k <= n; k++)
					swap(a[i][k], a[j][k]);
				flag = 1;
				break;
			}
		if(!flag) return 0;
		ll nbk = ksm(a[i][i], mod - 2);
		for(int j = i + 1; j <= n - 1; j++)
		{
			ll ndv = a[j][i] * nbk % mod;
			for(int k = 1; k <= n; k++)
				a[j][k] = (a[j][k] - a[i][k] * ndv) % mod;
		}
	}
	return 1;
}
bool eg[maxn][maxn];
ll x[maxn];
void otp(int n)
{
	cout<<endl;
	for(int i = 1; i <= n; i++)
	{
		for(int j = 1; j <= n; j++)
			cout<<a[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}
void work2()
{
	memset(a, 0, sizeof(a));
	for(int i = 1; i <= n; i++)
	{
		ll ns = 1;
		for(int j = 1; j <= n + 1; j++)
		{
			if(j == n + 1) a[i][j] = -ans[i];
			else a[i][j] = ns;
			ns = ns * i % mod;
		}
	}
	if(!work1(n + 1)) cout<<"WA"<<endl;
	for(int j = n; j >= 1; j--)
	{
		x[j] = -a[j][n + 1] * ksm(a[j][j], mod - 2) % mod;
		for(int k = 1; k <= j - 1; k++)
		{
			a[k][n + 1] = (a[k][n + 1] + a[k][j] * x[j]) % mod;
		}
	}
}
int main()
{

	scanf("%d", &n);
	for(int i = 1; i < n; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		eg[u][v] = eg[v][u] = 1;
	}
	for(int i = 1; i <= n; i++)
	{
		// cal ans[i]
		for(int j = 1; j <= n; j++)
		{
			int nd = 0;
			for(int k = 1; k <= n; k++)
			{
				if(j == k) continue;
				else if(eg[j][k]) a[j][k] = -i;
				else a[j][k] = -1;
				nd -= a[j][k];
			}
			a[j][j] = nd;
		}
	//	otp(n);
		bool nf = work1(n);
	//	otp(n);
		if(nf) 
		{
			ans[i] = 1;
			for(int j = 1; j < n; j++)
				ans[i] = ans[i] * a[j][j] % mod;
		}
		else ans[i] = 0;
		ans[i] = (ans[i] + mod) % mod;
	//	cout<<i<<" "<<ans[i]<<endl;
	//	while(1);
	}
	work2();
	for(int i = 1; i <= n; i++)
		x[i] = (x[i] % mod + mod) % mod, 
		printf("%I64d ", x[i]);
	return 0;
}