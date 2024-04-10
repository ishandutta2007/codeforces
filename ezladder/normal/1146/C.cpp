#include <bits/stdc++.h>
#define pb push_back
#define all(a) a.begin(), a.end()
#define mp make_pair
#define x first
#define y second

using namespace std;

int tt;

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	//freopen("input.txt", "r", stdin);
	cin >> tt;
	while(tt--){
		int n;
		cin >> n;
		vector<int> t;
		for (int i = 2; i <= n; i++) t.pb(i);
		cout << "1 " << t.size() << ' ' << 1 << ' ';
		for (int x : t) cout << x << ' ';
		cout << endl;
		int val;
		cin >> val;
		while(t.size() > 1){
			cout << "1 " << t.size() / 2 << ' ' << 1 << ' ';
			for (int i = 0; i < t.size() / 2; i++) cout << t[i] << ' ';
			cout << endl;
			int now;
			cin >> now;
			vector<int> d;
			if (now == val){
				for (int i = 0; i < t.size() / 2; i++) d.pb(t[i]);
			} else {
				for (int i = t.size() / 2; i < t.size(); i++) d.pb(t[i]);
			}
			t = d;
		}
		cout << "1 " << n - 1 << ' ' << t[0] << ' ';
		for (int i = 1; i <= n; i++) if (i != t[0]) cout << i << ' ';
		cout << endl;
		int ans;
		cin >> ans;
		cout << "-1 " << ans << endl;
	}
}