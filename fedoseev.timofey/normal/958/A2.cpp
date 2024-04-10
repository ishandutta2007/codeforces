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

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 2007;

ull deg[N], h[N][N];
const ull P = 239;

ull get(int ind, int l, int len) {
    return h[ind][l + len] - h[ind][l] * deg[len];
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n, m;
    cin >> n >> m;
    vector <ull> a(n);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        ull ha = 0;
        for (int i = 0; i < s.size(); ++i) {
            ha *= P;
            ha += s[i];
        }
        a[i] = ha;
    }
    deg[0] = 1;
    for (int i = 0; i < n; ++i) {
        deg[i + 1] = deg[i] * P;
    }
    for (int i = 0; i < m; ++i) {
        string s;
        cin >> s;
        h[i][0] = 0;
        for (int j = 0; j < n; ++j) {
            h[i][j + 1] = h[i][j] * P + s[j];
        }
    }
    for (int rs = 0; rs + m <= n; ++rs) {
        for (int cs = 0; cs + m <= n; ++cs) {
            bool bad = false;
            for (int i = 0; i < m; ++i) {
                if (get(i, cs, m) != a[rs + i]) {
                    bad = true;
                    break;
                }
            }
            if (!bad) {
                cout << rs + 1 << " " << cs + 1 << "\n";
                return 0;
            }
        }
    }
}