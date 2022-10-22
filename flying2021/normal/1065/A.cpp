#pragma comment(linker,"/stack:200000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
#define int long long
#define N 100005
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

signed main()
{
	int t;
	read(t);
	while (t--)
	{
		int s,a,b,c;
		read(s,a,b,c);
		cout << s / c / a * b + s / c << endl;
	}
	return 0;
}