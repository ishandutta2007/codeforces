#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	ll n , m , k;
	cin >> n >> m >> k;

	if(k <= n - 1)
		return cout << k + 1 << " " << 1 << endl , 0;

	k -= n;

	m--;
	ll tmp = k / (2 * m);

	k -= tmp * (2 * m);

	if(k <= m - 1)
		cout << n - 2 * tmp << " " << k + 2 << endl;
	else
		cout << n - 2 * tmp - 1 << " " << 2 * m - k + 1 << endl;

}