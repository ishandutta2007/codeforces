#include <bits/stdc++.h>

#define int ll
#define fi first
#define se second
#define init int n; cin >> n;
#define iniit int n, m; cin >> n >> m;
#define itn int
#define ld long double
#define ll long long
#define vpii vector<pii>
#define vvpii vector<vpii>
#define vpll vector<pll>
#define vvpll vector<vpll>
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define ffr(i, n, m) for (int i = n; i < m; ++i)
#define FR(i, n) for (int i = n - 1; i >= 0; --i
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair

using namespace std;

ll gcd(ll a, ll b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

void ct(vector<int> &a) {
    for (auto &i: a) cout << i << ' ';
    cout << '\n';
}

void ct(vpii &a) {
    for (auto &i: a) cout << i.fi << ":" << i.se << ' ';
    cout << '\n';
}

void ct(vvpii &a) {
    for (auto &i: a) ct(i);
}

void ct(vector<vector<int>> &a) {
    for(auto &i: a) {
        ct(i);
    }
}

void ci(vector<int> &a) {
    for(int i = 0; i < a.size(); ++i) cin >> a[i];
}

void ci(vector<vector<int>> &a) {
    for(int i = 0; i < a.size(); ++i) ci(a[i]);
}

signed main() {
    iniit;
    vi a(n);
    vi p(m);
    ci(a);
    ci(p);
    int s = a[0];
    int gc = a[1] - a[0];
    for(int i = 1; i < n; ++i) {
        gc = gcd(gc, a[i] - a[i - 1]);
    }
    for(int i = 0; i < m; ++i) {
        if (gc % p[i] == 0) {
            cout << "YES" << '\n' << s << ' ' << i + 1;
            return 0;
        }
    }
    cout << "NO";
}