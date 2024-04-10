#include <iostream>
#include <vector>

using namespace std;

#define int long long

main()
{
	int n, d; cin >> n >> d;
	int ans = 0;
	vector <int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	for (int i = 1; i < n; i++)
	{
		if (v[i] > v[i - 1]) continue;
		int dif = v[i - 1] - v[i];
		dif = dif / d + 1;
		ans += dif;
		v[i] += (dif * d);
	}
	cout << ans;
}