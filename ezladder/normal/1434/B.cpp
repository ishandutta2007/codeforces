#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

struct st {
	char c;
	int v;
} a[200007];

int n;

int main(){
#ifdef LOCAL
	freopen("B_input.txt", "r", stdin);
	//freopen("B_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);


	cin >> n;
	for (int i = 0; i < 2 * n; ++i) {
		cin >> a[i].c;
		if (a[i].c == '-') cin >> a[i].v;
	}

	n *= 2;
	reverse(a, a + n);

	vector<int> ans;
	vector<int> st;

	for (int i = 0; i < n; ++i) {
		if (a[i].c == '+' && st.size() == 0) cout << "NO\n", exit(0);
		if (a[i].c == '+') {
			ans.pb(st.back());
			st.pop_back();
		} else {
			if (st.size() > 0 && a[i].v > st.back()) cout << "NO\n", exit(0);
			st.pb(a[i].v);
		}
	}

	cout << "YES\n";
	reverse(all(ans));
	for (int x : ans) cout << x << ' ';
}