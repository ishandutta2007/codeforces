#include <bits/stdc++.h> 
 
using namespace std;
 
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define sz(x) (int) ((x).size()) 
#define forn(i, n) for (int i = 0; i < (n); ++i)
#define fornr(i, n) for (int i = (n) - 1; i >= 0; --i)
#define forab(i, a, b) for (int i = (a); i < (b); ++i)
#define all(c) (c).begin(), (c).end() 
 
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int n, k;
		cin >> n >> k;
		map<int, int> cnt;
		forn(i, n) {
			int x;
			cin >> x;
			cnt[x]++;
		}
		bool flag = false;
		for(auto [val, c] : cnt) {
			int other = val - k;
			int toFind = 1;
			if (other == val) toFind = 2;
			if (cnt[val - k] >= toFind) {
				cout << "YES\n";
				flag = 1;
				break;
			}
		}
		if (!flag) {
			cout << "NO\n";	
		}
	}
	return 0;
}