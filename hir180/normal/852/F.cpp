#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
ll mod;
#define SIZE 2100000
ll inv[SIZE + 1];
ll kai[SIZE + 1];
ll invkai[SIZE + 1];
void invinit()
{
	inv[1] = 1;
	for (int i = 2; i <= SIZE; i++)
	{
		inv[i] = mod - (mod / i)*inv[mod%i] % mod;
	}
	kai[0] = invkai[0] = 1;
	for (int i = 1; i <= SIZE; i++)
	{
		kai[i] = kai[i - 1] * i%mod;
		invkai[i] = invkai[i - 1] * inv[i] % mod;
	}
}
ll com(ll a, ll b)
{
	if (b < 0 || a < b)return 0;
	return (invkai[b] * invkai[a - b]) % mod*kai[a] % mod;
}
ll po(ll a, ll b, ll m)
{
	if (b == 0)return 1;
	ll t = po(a, b / 2, m);
	t = t*t%m;
	if (b & 1)t = t*a%m;
	return t;
}
ll ans[SIZE];
int main()
{
	int num, kai, st, m;
	scanf("%d%d%d%d", &num, &kai, &st, &m);
	int c = 0;
	ll now = 1;
	for (;;)
	{
		now = now*st%m;
		c++;
		if (now == 1)
		{
			mod = c;
			break;
		}
	}
	invinit();
	ans[0] = 1;
	for (int i = 1; i < num; i++)ans[i] = (ans[i - 1] + com(kai, i)) % mod;
	for (int i = num - 1; i >= 0; i--)
	{
		printf("%I64d ", po(st, ans[i], m));
	}
	printf("\n");
}