/*
name: Jacob Stankaitis
handle: jstankaitis
*/
#include <bits/stdc++.h>
using namespace std;

int main()
{
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(0);
	vector<int> vec;
	int n, s, temp, h, m;
	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> h >> m;
		temp = h * 60 + m;
		vec.push_back(temp);
	}

	if (vec[0] > s) {
		cout << 0 << " " << 0;
		return 0;
	}

	for (int i = 0; i < n - 1; i++) {
		int z = abs(vec[i] - vec[i + 1]);

		if (z / 2 >= s + 1) {
			int ats = (vec[i] + s + 1) / 60;
			m = (vec[i] + s + 1) % 60;
			cout << ats << " " << m << endl;
			return 0;
		}
	}

	cout << (vec[n - 1] + s + 1) / 60 << " " << (vec[n - 1] + s + 1) % 60 << endl;

	return 0;
}
/*input
1 58
0 1
*/