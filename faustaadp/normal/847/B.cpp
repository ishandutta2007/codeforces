#include <bits/stdc++.h>
using namespace std;
#define pb push_back

int N, a, last[200000], sz, ans;
vector <int> v[200000];

int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> N;
	cin >> a;
	v[0].pb(a);
	last[0] = a;
	sz = 1;
	N--;
	while (N--) {
		cin >> a;
		int L = 0;
		int R = sz-1;
		ans = sz;
		while (L <= R) {
			int md = (L+R)/2; //cout << a << " " << md << " aaa\n";
			if (last[md] < a) {
				R = md-1;
				ans = min(ans, md);
			} else L = md+1;
		}
		if (ans == sz) {
			v[sz].pb(a);
			sz++;
		} else v[ans].pb(a);
		last[ans] = a;
	}
	for (int i = 0; i < sz; i++) {
		for (int j = 0; j < v[i].size(); j++) {
			cout << v[i][j];
			if (j < v[i].size()-1) cout << " ";
		}
		cout << "\n";
	}
}