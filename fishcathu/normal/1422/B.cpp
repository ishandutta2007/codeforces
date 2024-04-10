#include<iostream>
using namespace std;
typedef long long ll;
const int N = 100;
#define f(a,b) (a>b?a-b:b-a)
int a[N][N];
ll g(int b, int c, int d,int e)
{
	if (b < c) { int t = b; b = c, c = t; }
	if (c < d) { int t = c; c = d, d = t; }
	if (b < c) { int t = b; b = c, c = t; }
	return f(b, c) * 1ll + f(c, d) + f(c, e);
}
int main()
{
	int x;
	for (cin>>x; x--;)
	{
		int n, m;
		ll ans = 0;
		cin >> n >> m, n -= 1, m -= 1;
		for (int i = 0; i <=n; ++i)for (int j = 0; j <= m; ++j)
		{
			cin >> a[i][j];
			if (n - i <=i && m - j <= j)
			{
				if (n - i == i || m - j == j)ans += f(a[i][j], a[n - i][m - j]);
				else ans += g(a[i][j],a[n-i][m-j],a[i][m-j],a[n-i][j]);
			}
		}
		cout << ans << endl;
	}
	return 0;
}