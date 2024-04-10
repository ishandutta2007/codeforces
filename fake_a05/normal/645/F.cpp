#include<bits/stdc++.h>

using namespace std;

#define loop(i, l, r) for(int i = (int) l; i <= (int) r; i++)
#define rloop(i, r, l) for(int i = (int) r; i >= (int) l; i--)

#define vi vector<int> 
#define ii pair<int, int> 
#define fi first
#define se second
#define eb push_back
#define all(x) begin(x), end(x)

#define rand rng
#define sp ' '
#define endl '\n'

#define int long long
const int maxN = 2e5 + 5, mod = 1e9 + 7, maxV = 2e6 + 5;

int N, K, Q;
int coef[maxV];
int cnt[maxV];
int fac[maxN];
int inv[maxN];
int ans;
int bp(int a, int b)
{
	int re = 1;
	while(b)
	{
		if(b & 1) re = (re * a) % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return re;
}
void init()
{
	loop(i, 0, maxN - 1)
	{
		if(!i) fac[i] = 1;
		else fac[i] = fac[i - 1] * i % mod;
		inv[i] = bp(fac[i], mod - 2);
//		cout << 
	}
	loop(i, 1, maxV - 1)
	{
		coef[i] = i;
	}
	loop(i, 1, maxV - 1)
	{
		for(int j = 2 * i; j < maxV - 1; j += i) coef[j] -= coef[i];
	}
}
int C(int k, int n)
{
	if(k > n) return 0;
	return fac[n] * inv[n - k] % mod * inv[k] % mod;
}
void add(int v)
{
	ans -= C(K, cnt[v]) * coef[v] % mod;
	assert(C(K, cnt[v]) >= 0);
//	cout << K << sp << cnt[v] << sp << C(K, cnt[v]) << endl;
	cnt[v]++;
	ans += C(K, cnt[v]) * coef[v] % mod;
	ans = (ans % mod + mod) % mod;
//	cout << v << sp << coef[v] << endl;
}
void insert(int x)
{
	for(int i = 1; i * i <= x; ++i)
	{
		if(x % i) continue;
		add(i);
		if(i * i != x) add(x / i);
	}
}
signed main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> N >> K >> Q;
	init();
	loop(i,1 , N) 
	{
		int t;
		cin >> t;
		insert(t);
	}
	loop(id, 1, Q)
	{
		int t;
		cin >> t;
		insert(t);
		cout << ans << endl;
	}
}