#include <iostream>
#include <vector>
#define int long long

using namespace std;

main()
{
	ios_base::sync_with_stdio(0);
	int n; cin >> n;
	vector <int> v(n), p(n), s(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	p[0] = v[0]; for (int i = 1; i < n; i++) p[i] = p[i - 1] + v[i];
	s[n - 1] = v[n - 1]; for (int i = n - 2; i >= 0; i--) s[i] = s[i + 1] + v[i];
	int sum = s[0];
	if (sum % 3 != 0) { cout << 0; return 0; }
	sum /= 3;
	int cnt = 0, ans = 0;
	for (int i = n - 1; i >= 0; i--)
	{
		if (p[i] == sum) ans += cnt;
		if (i != n - 1)
		{
			if (s[i + 1] == sum) cnt++;
		}
		//cout << i << " " << sum << " " << cnt << endl;
	}
	cout << ans;	
}