#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
#include <queue>
#include <iomanip>

using namespace std;

#pragma GCC optimize("Ofast,inline,fast-math,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,avx,avx2,abm,mmx,popcnt")

#include <algorithm>
#define int long long
// #define _GLIBCXX_DEBUG
#define SOLVE int t; cin >> t; while(t--) solve();

void setup() {
	#ifdef LOCAL
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#else
		ios_base::sync_with_stdio(0);
		cin.tie(0);
		cout.tie(0);
	#endif

	srand(time(0));
}

void ct(vector<int> &a) {
	for(auto i: a)
		cout << i << ' ';
	cout << '\n';
}

void ct(pair<int, int> &a) {
	cout << a.first << ':' << a.second << ' ';
}

void ct(vector<pair<int, int>> &a) {
	for(auto i: a)
		ct(i);
}

signed main() {
	setup();
	// SOLVE;

	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; ++i)
		cin >> a[i];
	vector<int> ans_r(n, -1);
	vector<int> b;
    for(int i = 0; i < n; ++i) {
        while(true) {
            if (!b.size()) 
            	break;
            if (a[b.back()] >= a[i]) {
                ans_r[b.back()] = i;
                b.pop_back();
            }
            else 
            	break;
        }
        b.push_back(i);
    }
    vector<int> ans_l(n, -1);
    b.clear();
    for(int i = n - 1; i >= 0; --i) {
    	while(true) {
    		if (!b.size())
    			break;
    		if (a[b.back()] >= a[i]) {
    			ans_l[b.back()] = i;
    			b.pop_back();
    		}
    		else 
    			break;
    	}
    	b.push_back(i);
    	// ct(b);
    }
    // ct(ans_l);
    // ct(ans_r);
    vector<int> dp_l(n);
    dp_l[0] = a[0];
    for(int i = 1; i < n; ++i) {
    	if (ans_l[i] == -1) {
    		dp_l[i] = a[i] * (i + 1);
    	}
    	else {
    		dp_l[i] = (i - ans_l[i]) * a[i] + dp_l[ans_l[i]];
    	}
    }
    vector<int> dp_r(n);
    dp_r[n - 1] = a[n - 1];
    for(int i = n - 2; i >= 0; --i) {
    	if (ans_r[i] == -1) {
    		dp_r[i] = a[i] * (n - i);
    	}
    	else {
    		dp_r[i] = (ans_r[i] - i) * a[i] + dp_r[ans_r[i]];
    	}
    }
    int mx = 0;
    int mxi = 0;
    for(int i = 0; i < n; ++i) {
    	if (dp_r[i] + dp_l[i] - a[i] >= mx) {
    		mxi = i;
    		mx = dp_r[i] + dp_l[i] - a[i];
    	}
    }

    vector<int> res(n);
    int now = a[mxi];
    for(int i = mxi; i >= 0; --i) {
    	res[i] = min(now, a[i]);
    	now = min(now, a[i]);
    }
    now = a[mxi];
    for(int i = mxi; i < n; ++i) {
    	res[i] = min(now, a[i]);
    	now = min(a[i], now);
    }
    ct(res);
	
	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}