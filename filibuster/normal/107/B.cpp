#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;


int main() {
    int n, m, h;
    cin >> m >> n >> h;

    h--;

    vector<int> a(n);
    int s1 = 0, s2 = 0;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
        s1 += a[i];
    }

    s2 += a[h] - 1;
    s1 -= a[h];

    m--;

//    cout << s1 << ' ' << s2 << ' ' << m << endl;

    if(s1 + s2 < m) {
        cout << -1 << endl;
        return 0;
    }

    if(s1 < m) {
        cout << 1 << endl;
        return 0;
    }

    ld ans = 1;
    for(int i = 0; i < m; i++) {
//        cout << ld(s1 - i) / (s1 + s2 - i) << endl;
        ans *= ld(s1 - i) / (s1 + s2 - i);
    }

    cout << setprecision(20) << fixed << (1 - ans) << endl;
}