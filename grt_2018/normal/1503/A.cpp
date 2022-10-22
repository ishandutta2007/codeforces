#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second

//#pragma GCC optimize ("O3")
//#pragma GCC target("tune=native")

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

int t, n;
string s;

bool check(string a) {
	int d = 0;
	for(int c : a) {
		if(c == '(') d++;
		else d--;
		if(d < 0) return false;
	}
	return d == 0;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n >> s;
		int cnt1 = 0, cnt0 = 0;
		for(int c : s) if(c == '1') cnt1++;
		if(cnt1 & 1) {
			cout << "NO\n";
			continue;
		}
		cnt0 = 0;
		cnt1 /= 2;
		string a = "", b = "";
		for(int c : s) {
			if(c == '1') {
				if(cnt1 > 0) {
					a += '(';
					b += '(';
					cnt1--;
				} else {
					a += ')';
					b += ')';
				}
			} else {
				if(cnt0&1) {
					a += '(';
					b += ')';
				} else {
					a += ')';
					b += '(';
				}
				cnt0++;
			}
		}
		if(check(a) && check(b)) {
			cout << "YES\n" << a << "\n" << b << "\n";
		} else {
			cout << "NO\n";
		}
					
	}
}