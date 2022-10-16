#include <bits/stdc++.h>

typedef long long ll;
typedef long double ld;

#define all(x) x.begin(), x.end()
#define sz(x) x.size()
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define rep(i, a, b) for(int i = a; i < b; ++i)
#define endl '\n'

using namespace std;

int main()
{
	ios::sync_with_stdio(false); cin.tie(0);
	int m, s;
	cin >> m >> s;
	if (s < 1) {
		if (m == 1 && s == 0) puts("0 0");
		else puts("-1 -1");
		return 0;
	}       
	vector<int> first(m);
	first[0] = 1;
	int left = s - 1;
	for (int i = m-1; i >= 0; --i) {
		while (first[i] < 9 && left) {
			++first[i];
			--left;
		}
	}
	if (left > 0) {
		puts("-1 -1");
		return 0;
	}
	vector<int> second(m);
	second[0] = 1;
	left = s - 1;
	rep(i, 0, m) {
		while(second[i] < 9 && left) {
			++second[i];
			--left;
		}
	}
	for(int dig: first) cout << dig;
	cout << " ";
	for(int dig: second) cout << dig;
	return 0;
}