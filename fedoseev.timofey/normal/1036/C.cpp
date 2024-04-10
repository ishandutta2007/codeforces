#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <ctime>
#include <random>
#include <cmath>
#include <bitset>
#include <iomanip>
#include <list>
#include <unordered_set>
#include <unordered_map>
#include <cassert>

using namespace std;

typedef long long ll;
typedef long double ld;

vector <ll> ok;

void gen(string &cur, int cnt) {
	if (cur.size()) ok.push_back(stoll(cur));
	if (cur.size() >= 18) return;
	if (cnt == 3) {
		cur.push_back('0');
		gen(cur, cnt);
		cur.pop_back();
	}
	else {
		if (cur.size() != 0) {
			cur.push_back('0');
			gen(cur, cnt);
			cur.pop_back();
		}
		for (int i = 1; i <= 9; ++i) {
			cur.push_back('0' + i);
			gen(cur, cnt + 1);
			cur.pop_back();
		}
	}
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    string tmp = "";
    gen(tmp, 0);
    ok.push_back((ll)1e18);
    sort(ok.begin(), ok.end());
    int q;
    cin >> q;
    while (q--) {
    	ll l, r;
    	cin >> l >> r;
    	cout << upper_bound(ok.begin(), ok.end(), r) - lower_bound(ok.begin(), ok.end(), l) << '\n';
    }
}