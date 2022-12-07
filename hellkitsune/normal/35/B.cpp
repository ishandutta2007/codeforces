#include <cstdio>
#include <cmath>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <stack>
#include <vector>
#include <cassert>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); ++e)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, k;
int a[30][30];
map<string, int> ma;
string s, qt;
int mac = 0;

int getHash(string s) {
    auto it = ma.find(s);
    if (it == ma.end()) {
        ma[s] = mac;
        return mac++;
    }
    return it->second;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin >> n >> m >> k;
    REP(i, n) REP(j, m) a[i][j] = -1;
    REP(i, k) {
        cin >> qt;
        if (qt[0] == '+') {
            int x, y, id;
            cin >> x >> y >> s, --x, --y;
            id = getHash(s);
            bool flag = true;
            for (; x < n; ++x, y = 0) if (flag) {
                for (; y < m; ++y) if (a[x][y] == -1) {
                    a[x][y] = id;
                    flag = false;
                    break;
                }
            }
        } else {
            cin >> s;
            int id = getHash(s);
            bool flag = true;
            REP(i, n) if (flag) REP(j, m) if (a[i][j] == id) {
                a[i][j] = -1;
                cout << i + 1 << ' ' << j + 1 << '\n';
                flag = false;
                break;
            }
            if (flag) cout << "-1 -1" << '\n';
        }
    }
	return 0;
}