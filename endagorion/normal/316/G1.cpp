#include <iostream>
#include <vector>
#include <cmath>
#include <cstdio>
#include <set>
#include <map>
#include <fstream>
#include <cstdlib>
#include <string>
#include <cstring>
#include <algorithm>

#define mp make_pair
#define pb push_back
#define all(x) (x).begin(), (x).end()

using namespace std;

const long long Q = 109, P = 10000000000000000 + 61;

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    string s;
    cin >> s;
    int N;
    cin >> N;
    vector<string> t(N);
    vector<int> l(N), r(N);
    for (int i = 0; i < N; ++i) {
        cin >> t[i] >> l[i] >> r[i];
    }

    vector< multiset<long long> > substrs(N);
    for (int i = 0; i < N; ++i) {
        for (size_t j = 0; j < t[i].size(); ++j) {
            long long h = 0;
            for (size_t k = j; k < t[i].size(); ++k) {
                h = (h * Q + t[i][k]) % P;
                substrs[i].insert(h);
            }
        }
    }

    set<long long> ans;
    for (size_t j = 0; j < s.size(); ++j) {
        long long h = 0;
        for (size_t k = j; k < s.size(); ++k) {
            h = (h * Q + s[k]) % P;
            bool ok = true;
            for (int i = 0; i < N; ++i) {
                size_t c = substrs[i].count(h);
                ok &= c >= l[i] && c <= r[i];
            }
            if (ok) {
                ans.insert(h);
            }
        }
    }

    cout << ans.size() << '\n';

	return 0;
}