#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cassert>
#include <iomanip>

using namespace std;

const int N = 5007;

int bad[26][N][26];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    string s;
    cin >> s;
    vector <string> a;
    int n = s.size();
    for (int shift = 0; shift < n; ++shift) {
        a.push_back(s.substr(shift, n - shift) + s.substr(0, shift));
    }
    for (int i = 0; i < n; ++i) {
        int c = a[i][0] - 'a';
        for (int j = 1; j < n; ++j) {
            ++bad[c][j][a[i][j] - 'a'];
        }
    }
    int res = 0;
    for (int i = 0; i < 26; ++i) {
        int cur = 0;
        for (int ind = 0; ind < n; ++ind) {
            int tmp = 0;
            for (int j = 0; j < 26; ++j) {
                if (bad[i][ind][j] == 1) ++tmp;
            }
            cur = max(cur, tmp);
        }
        res += cur;
    }
    cout << fixed << setprecision(16) << res / (double)n << endl;
}