#include <bits/stdc++.h>
#define ll long long
#define db long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

using namespace std;

string s;

void solve(){
	cin >> s >> s;
	vector<int> d;
	for (int c = 0; c <= 9; c++){
		bool stop = 0;
		for (int i = 0; i < s.size(); i++) if (s[i] - '0' == c){
			if (d.size() && d.back() > i){
				stop = 1;
			}
			else d.pb(i);
		}
		if (stop) break;
	}
	set<int> se;
	for (int x : d) se.insert(x);
	vector<int> f;
	for (int i = 0; i < s.size(); i++) if (se.find(i) == se.end()) f.pb(i);
	for (int i = 0; i  + 1 < f.size(); i++) if (s[f[i + 1]] - '0' < s[f[i]] - '0'){
		cout << "-\n";
		return;
	}
	for (int i = 0; i < s.size(); i++) if (se.find(i) != se.end()) cout << 1;
		else cout << 2;
	cout << "\n";
}

int main(){
#ifdef LOCAL
	freopen("A_input.txt", "r", stdin);
	//freopen("A_output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int tt;
	cin >> tt;
	while(tt--){
		solve();
	}

}