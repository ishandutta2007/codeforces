#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
// #include <algorithm>
#include <queue>

#define int long long
#define SOLVE int t; cin >> t; while(t--) solve();

using namespace std;

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(false);
		cin.tie(nullptr);
		cout.tie(nullptr);
	#endif
}

void ct(vector<int> &a) {
	for(auto i: a)
		cout << i << ' ';
}

void ct(pair<int, int> &a) {
	cout << a.first << ':' << a.second << ' ';
}

void ct(vector<pair<int, int>> &a) {
	for(auto i: a)
		ct(i);
}

void ci(vector<int> &a) {
	for(auto &i: a)
		cin >> i;
}

void solve() {
	//      
	string a, b, c;
	cin >> a >> b >> c;
	int n = a.size();
    for(int i = 0; i < a.size(); ++i) {
        if (a[i] == c[i])
        	swap(b[i], c[i]);
        else
        	swap(a[i], c[i]);
    }
    if (a == b)
        cout << "YES\n";
    else
        cout << "NO\n";
}

signed main() {
	setup();
	SOLVE;
	

	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}