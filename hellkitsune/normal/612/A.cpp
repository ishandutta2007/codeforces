#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, p, q;
string s;

int main() {
    cin >> n >> p >> q >> s;
    REP(i, 101) REP(j, 101) if (i * p + j * q == n) {
        cout << i + j << endl;
        REP(k, i) {
            cout << s.substr(k * p, p) << endl;
        }
        REP(k, j) {
            cout << s.substr(i * p + k * q, q) << endl;
        }
        return 0;
    }
    cout << -1 << endl;
    return 0;
}