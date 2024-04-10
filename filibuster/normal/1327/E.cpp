#include <bits/stdc++.h>

#define f first
#define s second
#define forn(i, n) for(int i = 0; i < n; i++)

using namespace std;
using li = long long;
using pii = pair<int, int>;
using pli = pair<li, li>;
using vi = vector<int>;
using vli = vector<li>;
using vpli = vector<pli>;

istream& operator >>(istream& cin, vector<int>& a) {
    for(int i = 0; i < a.size(); i++)
        cin >> a[i];
    return cin;
}

ostream& operator <<(ostream& cout, vector<int>& a) {
    for(int i = 0; i < a.size(); i++)
        cout << a[i] << ' ';
    cout << endl;
    return cout;
}

const int M = 998244353;
const int INF = 1e9;

void solve() {
    int n;
    cin >> n;

    vector<int> p(n + 5, 1);
    for(int i  =1; i < p.size(); i++)
        p[i] = p[i - 1] * 1ll * 10 % M;

    vector<int> ans(n, 0);
    for(int i = 1; i < n; i++) {
        int res = 0;
        res = 810 * 1ll * p[n - i - 2] % M * 1ll * (n - i - 1) % M;
        res = (res + 180 * 1ll * p[n - i - 1] % M) % M;
        ans[i - 1] = res;
    }

    ans[n - 1] = 10;

    for(int i = 0; i < n; i++)
        cout << ans[i] << ' ';
}

int main() {
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int t = 1;
//    cin >> t;

    while(t--)
        solve();
}