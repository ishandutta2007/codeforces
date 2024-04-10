#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;



int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;
	int n;
	vector<int> a(200, 0);
	while (tt--) {
		cin >> n;
		for (int i = 0; i < n; ++i) cin >> a[i];
		int f = 0;
		int last = -1;

		while (1) {
			int now = -1;
			for (int i = 0; i < n; ++i) if (i != last && a[i] > 0) if (now == -1 || a[now] < a[i]) now = i;
			if (now == -1) break;
			--a[now];
			f ^= 1;
			last = now;
		}


		if (!f) cout << "HL\n"; else cout << "T\n";
	}

}