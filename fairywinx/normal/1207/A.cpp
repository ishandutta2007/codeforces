#include <bits/stdc++.h>

#define fi first
#define se second
#define INT int n; cin >> n;
#define INTT int n, m; cin >> n >> m;
#define itn int
#define ld long double
#define ll long long
#define pll pair<ll, ll>
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define fr(i) for(int i = 0; i < n; ++i)
#define ffor(i, j) for(int i = 0; i < n; ++i) { for(int j = 0; j < m; ++j)
#define con continue
#define all(x) x.begin(), x.end()

using namespace std;

int gcd(int a, int b) {
    if (a == 0) return b;
    return gcd(b % a, a);
}

void ct(vector<int> &a) {
    for (auto &i: a) cout << i << ' ';
    cout << '\n';
}

void ct(vector<vector<int>> &a) {
    for(auto &i: a) {
        ct(i);
    }
}

void cia(vector<int> a) {
    for(int i = 0; i < a.size(); ++i) cin >> a[i];
}

void cia(vector<vector<int>> a) {
    for(int i = 0; i < a.size(); ++i) cia(a[i]);
}

int main() {
    int t;
    cin >> t;
    for(itn i = 0; i < t; ++i) {
        int b, p, u, mx = 0;
        int h, f;
        cin >> b >> p >> u >> h >> f;
        for(int j = 0; j <= p; ++j) {
            if (j * 2 > b) break;
            mx = max(mx, h * j + min((b - 2 * j) / 2, u) * f);
        }
        cout << mx << '\n';
    }
}