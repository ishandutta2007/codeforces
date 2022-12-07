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

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define foreach(e, x) for (__typeof(x.begin()) e = x.begin(); e != x.end(); e++)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
bool b[2000];
vector<int> p;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> k;
    for (int i = 2; i < 2000; ++i) b[i] = true;
    for (int i = 2; i < 2000; ++i) if (b[i]) {
        for (int j = i * i; j < 2000; j += i)
            b[j] = false;
    }
    for (int i = 2; i < 2000; ++i) if (b[i])
        p.pb(i);
    int cnt = 0;
    for (int i = 0; p[i] <= n; ++i) {
        int x = p[i] - 1;
        for (int j = 0; p[j] + p[j + 1] <= x; ++j)
            if (p[j] + p[j + 1] == x) {
                ++cnt;
                break;
            }
    }
    if (cnt >= k) cout << "YES\n";
    else cout << "NO\n";
    return 0;
}