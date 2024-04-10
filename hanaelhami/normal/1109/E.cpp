#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back
#define lb(a) ((a)&(-(a)))

const int maxn = 1e5 + 20;
int mod , phi;

vector<int> p;

int n , a[maxn] , fen[10][maxn] , sum[maxn * 4] , lazy[maxn * 4] , lazy1[maxn * 4];
ll sht[maxn];

void add(int p , int val , int id)
{
	for(p += 5; p < maxn; p += lb(p))
		fen[id][p] += val;
}

int get(int p , int id)
{
	int res = 0;
	for(p += 5; p > 0; p -= lb(p))
		res += fen[id][p];
	
	return res;
}

void f(int mod)
{
	phi = mod;
	for(ll i = 2; i * i <= mod; i++)
		if(mod % i == 0)
		{
			p.pb(i);
			phi -= phi / i;
			while(mod % i == 0)
				mod /= i;
		}

	if(mod > 1)
		p.pb(mod) , phi -= phi / mod;
}

int bpw(int a , int b)
{
	if(!b)
		return 1;
	int x = bpw(a , b / 2);
	x = 1LL * x * x % mod;
	if(b&1)
		x = 1LL * x * a % mod;
	return x;
}

int getshit(int val)
{
	int res = 1;
	for(int i = 0; i < (int)p.size(); i++)
		while(val % p[i] == 0)
		{
			res *= p[i];
			val /= p[i];
		}

	return res;
}

void shift(int s , int e , int v)
{
	if(e - s >= 2)
	{
		sum[2 * v] = 1LL * sum[2 * v] * lazy[v] % mod;
		sum[2 * v + 1] = 1LL * sum[2 * v + 1] * lazy[v] % mod;

		lazy[2 * v] = 1LL * lazy[2 * v] * lazy[v] % mod;
		lazy[2 * v + 1] = 1LL * lazy[2 * v + 1] * lazy[v] % mod;

		lazy1[2 * v] = 1LL * lazy1[2 * v] * lazy1[v] % mod;
		lazy1[2 * v + 1] = 1LL * lazy1[2 * v + 1] * lazy1[v] % mod;
		lazy[v] = lazy1[v] = 1;
	}
}

void Mul(int l , int r , int val , int tmp , int s , int e , int v)
{
	if(l <= s && e <= r)
	{
		sum[v] = 1LL * sum[v] * val % mod;
		lazy[v] = 1LL * lazy[v] * val % mod;
		lazy1[v] = 1LL * lazy1[v] * tmp % mod;
		return;
	}
	if(r <= s || e <= l)
		return;

	shift(s , e , v);
	int m = (s + e) / 2;
	Mul(l , r , val , tmp , s , m , 2 * v);
	Mul(l , r , val , tmp , m , e , 2 * v + 1);

	sum[v] = (sum[2 * v] + sum[2 * v + 1]) % mod;
}

void mul(int l , int r , int val)
{
	Mul(l , r , val , val / getshit(val) , 0 , n , 1);
	for(int i = 0; i < (int)p.size(); i++)
	{
		int tmp = 0;
		while(val % p[i] == 0)
			val /= p[i] , tmp++;

		add(l , tmp , i);
		add(r , -tmp , i);
	}
}

void prnt()
{
	for(int i = 0; i < n; i++)
		cout << sum[i] << " ";
	cout << endl;
}

void div(int pos , int val , int s , int e , int v)
{
	if(e - s < 2)
	{
		int k = getshit(val);
		val /= k;
		lazy1[v] = 1LL * lazy1[v] * bpw(val , phi - 1) % mod;
		sum[v] = lazy1[v];

		for(int i = 0; i < (int)p.size(); i++)
		{
			int tmp = get(pos , i) , xx = tmp;
			while(k % p[i] == 0)
				k /= p[i] , tmp--;

			assert(tmp >= 0);
			sum[v] = 1LL * sum[v] * bpw(p[i] , tmp) % mod;
			add(pos , tmp - xx , i);
			add(pos + 1 , -(tmp - xx) , i);
		}
		return;
	}

	shift(s , e , v);
	int m = (s + e) / 2;
	if(pos < m)
		div(pos , val , s , m , 2 * v);
	else
		div(pos , val , m , e , 2 * v + 1);

	sum[v] = (sum[2 * v] + sum[2 * v + 1]) % mod;
}

int getSum(int l , int r , int s , int e , int v)
{
	if(l <= s && e <= r)
		return sum[v];
	if(r <= s || e <= l)
		return 0;

	shift(s , e , v);
	int m = (s + e) / 2;

	return (getSum(l , r , s , m , 2 * v) + getSum(l , r , m , e , 2 * v + 1)) % mod;
}

void build(int s , int e , int v)
{
	sum[v] = (e - s) % mod;
	lazy[v] = lazy1[v] = 1;

	if(e - s < 2)
		return;

	int m = (s + e) / 2;
	build(s , m , 2 * v);
	build(m , e , 2 * v + 1);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> mod;
	build(0 , n , 1);
	f(mod);

	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		mul(i , i + 1 , a[i]);
	}

	int q;
	cin >> q;
	while(q--)
	{
		int type;
		cin >> type;
	//	prnt();
		if(type == 1)
		{
			int l , r , x;
			cin >> l >> r >> x;
			l--;
			mul(l , r , x);
		}
		if(type == 2)
		{
			int p , x;
			cin >> p >> x;
			p--;
			div(p , x , 0 , n , 1);
		}
		if(type == 3)
		{
			int l , r;
			cin >> l >> r;
			l--;
			cout << getSum(l , r , 0 , n , 1) << endl;
		}
	}
}