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

int h[N],a[N],sum[N];

signed main()
{
	int t = 1;
	while (t--)
	{
		memset(sum,0,sizeof(sum));
		memset(h,0,sizeof(h));
		int n,k,mini = 0x7f7f7f7f7f7f7f;
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			int x;
			cin >> x;
			h[x]++;
			mini = min(mini,x);
		}
		for (int i = 200000; i >= 1; i--)
			sum[i] = sum[i + 1] + h[i];
		int qaq = 0,ans = 0,cnt = 0;
		for (int i = 200000; i >= mini; i--)
		{
			qaq += h[i] * i;
			cnt += h[i];
			if (i != mini && qaq - cnt * (i - 1) > k)
			{
				// cout << i << ' ' << qaq << ' ' << cnt << endl;
				qaq = cnt * i;
				ans++;
			}
			else
			{
				if (i == mini && qaq > cnt * i) ans++;
			}
		}
		writeln(ans);
	}
	return 0;
}