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
	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector <int> a(n);
		for (int i = 0; i < n; ++i)
			cin >> a[i];
		string ans = "NO";
		for (int i = 0; i < n; ++i)
			for (int j = i + 2; j < n; ++j)
				if (a[i] == a[j])
					ans = "YES";
		cout << ans << endl;
	}
}