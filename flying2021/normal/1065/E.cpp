#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define int long long
#define N 200005
using namespace std;

template <typename T>

void read(T &a)
{
	T x = 0,f = 1;
	char ch = getchar();
	while (ch < '0' || ch > '9')
	{
		if (ch == '-') f = -1;
		ch = getchar();
	}
	while (ch >= '0' && ch <= '9')
	{
		x = (x << 1) + (x << 3) + (ch ^ 48);
		ch = getchar();
	}
	a = x * f;
}

template <typename T>

void write(T x)
{
	if (x < 0) putchar('-'),x = -x;
	if (x < 10) return (void) putchar(x + '0');
	write(x / 10);
	putchar(x % 10 + '0');
}

template <typename T>

void writeln(T x)
{
	write(x);
	putchar('\n');
}

template <typename T>

void writes(T x)
{
	write(x);
	putchar(' ');
}

template <typename T,typename... Args>

void read(T &x,Args &... args)
{
	read(x);
	read(args...);
}

template <typename T,typename... Args>

void writes(T x,Args ... args)
{
	writes(x);
	writes(args...);
}

template <typename T,typename... Args>

void writeln(T x,Args ... args)
{
	writes(x);
	writes(args...);
	putchar('\n');
}

const int mod = 998244353;
int n,m,l,b[N];

int ksm(int a,int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = res * a % mod;
		a = a * a % mod;
		b >>= 1;
	}
	return res;
}

signed main()
{
	cin >> n >> m >> l;
	for (int i = 1; i <= m; i++)
		cin >> b[i];
	int ans = 1,inv = 499122177;
	for (int i = 1; i <= m; i++)
	{
		int tmp = ksm(l,b[i] - b[i - 1]);
		ans = ans * tmp % mod * (tmp + 1) % mod * inv % mod % mod;
		// cout << i << ' ' << ans << endl;
	}
	ans = ans * ksm(l,n - 2 * b[m]) % mod;
	writeln(ans);
	return 0;
}