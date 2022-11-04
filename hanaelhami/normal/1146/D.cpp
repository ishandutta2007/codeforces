#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 2e5 + 20;

bool visited[maxn];

int n , a , b , tmp = 1;

void dfs(int v)
{
	tmp++;
	visited[v] = 1;
	for(auto val : {a , -b})
		if(0 <= v + val && v + val <= n && !visited[v + val])
			dfs(v + val);
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int m;
	cin >> m >> a >> b;

	ll res = 1;
	visited[0] = 1;
	for(int i = 1; i <= min(m , a + b); i++)
	{
		n = i;
		if(i >= a && visited[i - a])
			dfs(i);
		res += tmp;
	}
//	cout << res << endl;
//	return 0;

	if(m > a + b)
	{
		int st = a + b + 1 , g = __gcd(a , b);
		res += m - st + 1;
		for(int i = st; i / g == st / g && i <= m; i++)
			res += i / g;
		if(m / g != st / g)
		{
			for(int i = m; i / g == m / g && i >= st; i--)
				res += i / g;

			m = m / g * g - g;
			st = st / g * g + g;
			m /= g , st /= g;

			ll tmp = 1LL * m * (m + 1) / 2 - 1LL * st * (st - 1) / 2;
			res += tmp * g;
		}
	}

	cout << res << endl;
}