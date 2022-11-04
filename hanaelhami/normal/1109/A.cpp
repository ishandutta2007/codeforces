#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = (1 << 20) + 20;

int a[maxn] , t[2][maxn];

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	for(int i = 1; i <= n; i++)
	{
		cin >> a[i];
		a[i] ^= a[i - 1];
	}

	t[0][0]++;

	ll res = 0;
	for(int i = 1; i <= n; i++)
	{
		res += t[(i % 2)][a[i]];
		t[i % 2][a[i]]++;
	}

	cout << res << endl;
}