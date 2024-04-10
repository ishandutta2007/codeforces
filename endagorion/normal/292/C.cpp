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

void rec(const string &s, int j, int len, int n, bool nl, vector<int> &ip, vector< vector<int> > &ans, int used, int usedc, const vector<int> &d) {
    if (d.size() - usedc > len - j) {
        return;
    }
    if (ip.size() < 4 && !nl) {
        ip.push_back(n);
        rec(s, j, len, 0, true, ip, ans, used, usedc, d);
        ip.pop_back();
    }
    if (j == len) {
        if (ip.size() == 4 && nl && usedc == d.size()) {
            ans.pb(ip);
        }
        return;
    }
    for (size_t i = 0; i < d.size(); ++i) {
        int x = d[i];
        if (j > len - 1 - j && x + '0' != s[len - 1 - j]) {
            continue;
        }
        if (10 * n + x < 256 && !(!nl && n == 0)) {
            rec(s + (char)(x + '0'), j + 1, len, 10 * n + x, false, ip, ans, used | (1 << i), usedc + 1 - ((used >> i) & 1), d);
        }
    }
}

int main() {
#ifdef LOCAL_DEFINE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    vector< vector<int> > ans;
    vector<int> d;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int x;
        cin >> x;
        d.pb(x);
    }
    if (N > 6) {
        cout << 0 << '\n';
        return 0;
    }

    vector<int> ip;
    string s = "";
    for (int i = 4; i <= 12; ++i) {
        //for (size_t j = 0; j < d.size(); ++j) {
          //  s.pb(j + '0');
            rec("", 0, i, 0, true, ip, ans, 0, 0, d);
            //s.pop_back();
        //}
    }

    printf("%d\n", (int)ans.size());
    for (size_t i = 0; i < ans.size(); ++i) {
        printf("%d.%d.%d.%d\n", ans[i][0], ans[i][1], ans[i][2], ans[i][3]);
    }

	return 0;
}