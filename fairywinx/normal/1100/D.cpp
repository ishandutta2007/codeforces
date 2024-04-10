// #define _GLIBCXX_DEBUG

#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <ctime>
#include <queue>
#include <map>
#include <assert.h>
#include <math.h>
#include <iomanip>
#include <string>

// #include <algorithm>
// #define int long long

// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
// #pragma optimize("O3");

using namespace std;

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

bool ans = false;

bool check(vector<pair<int, int>> &a, pair<int, int> s) {
    for(auto i: a) {
        if (i.first == s.first || i.second == s.second)
            return true;
    }
    return false;
}

void go_to(pair<int, int> s, pair<int, int> f, vector<pair<int, int>> &a) {
    if (ans)
        return;
    while(s != f) {
        pair<int, int> to = s;
        if (s.first != f.first) {
            if (s.first > f.first)
                to.first--;
            else if (s.first < f.first)
                to.first++;
        }
        if (s.second != f.second) {
            if (s.second > f.second)
                to.second--;
            else if (s.second < f.second)
                to.second++;
        }
        for(auto i: a) {
            if (i == to) {
                for(int k = -1; k < 2; ++k) {
                    for(int j = -1; j < 2; ++j) {
                        pair<int, int> z = {s.first + k, s.second + j};
                        if (z.first > 0 && z.second > 0 && z.first < 1000 && z.second < 1000) {
                            if (i != z && (i.first == z.first || i.second == z.second)) {
                                to = z;
                                break;
                            }
                        }
                    }
                }
            }
        }
        cout << to.first << ' ' << to.second << endl;
        if (check(a, to)) {
            ans = true;
            return;
        }
        s = to;
        int k, x, y;
        cin >> k >> x >> y;
        a[k - 1] = {x, y};
    }
}

signed main() {
//	setup();

    pair<int, int> s;
    vector<pair<int, int>> a(666);
    cin >> s.first >> s.second;
    for(int i = 0; i < 666; ++i) {
        cin >> a[i].first >> a[i].second;
    }

    go_to(s, {500, 500}, a);
    int kol1 = 0, kol2 = 0, kol3 = 0, kol4 = 0;
    for(int i = 0; i < 666; ++i) {
        if (a[i].first >= 500 && a[i].second >= 500)
            ++kol4;
        if (a[i].first >= 500 && a[i].second < 500)
            ++kol1;
        if (a[i].first < 500 && a[i].second >= 500)
            ++kol3;
        if (a[i].first < 500 && a[i].second < 500)
            ++kol2;
    }
    int mx = 0;
    mx = min(min(kol1, kol2), min(kol3, kol4));
    if (mx == kol3)
        go_to({500, 500}, {999, 1}, a);
    else if (mx == kol4)
        go_to({500, 500}, {1, 1}, a);
    else if (mx == kol1)
        go_to({500, 500}, {1, 999}, a);
    else
        go_to({500, 500}, {1000, 999}, a);


	#ifdef LOCAL
		cerr << "processor time: " << 1.0 * clock() / CLOCKS_PER_SEC << "s    ";
	#endif
}