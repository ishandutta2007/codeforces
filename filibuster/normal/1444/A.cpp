#include <bits/stdc++.h>

#define f first
#define s second

using namespace std;
using li = long long;
using ld = long double;
using pii= pair<int, int>;

const int INF = 1e9 + 13;
const int M = 1e9 + 7;
const int N = 2e5 + 13;
const int B = 350;

void solve() {
    li p, q;
    cin >> p >> q;

    if(p % q != 0) {
        cout << p << endl;
        return;
    }

    vector<pii> a;
    for(int i = 2; i * i <= q; i++) {
        if(q % i == 0) {
            a.emplace_back(i, 0);
            while(q % i == 0) {
                q /= i;
                a.back().s++;
            }
        }
    }

    if(q > 1) {
        a.emplace_back(q, 1);
    }

    li ans = 1;
    for(int i = 0; i < a.size(); i++) {
        int cnt = 0;
        li p1 = p;
        while(p1 % a[i].f == 0) {
            cnt++;
            p1 /= a[i].f;
        }

        p1 = p;
        for(int j = 0; j < cnt - a[i].s + 1; j++) {
            p1 /= a[i].f;
        }

//        cout << a[i].f << ' ' << a[i].s << ' ' << cnt << ' ' << p1 << endl;

        ans = max(ans, p1);

    }

    cout << ans << endl;
}

int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
    cin >> t;

    while(t--)
        solve();
}