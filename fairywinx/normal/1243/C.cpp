#include <bits/stdc++.h>


#define int long long
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

ll gcd(ll a, ll b) {
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

void cia(vector<int> &a) {
    for(int i = 0; i < a.size(); ++i) cin >> a[i];
}

void cia(vector<vector<int>> &a) {
    for(int i = 0; i < a.size(); ++i) cia(a[i]);
}

ll nok(ll a, ll b) {
    return a * b / (gcd(a, b));
}

signed main() {
    ll n;
    cin >> n;
    vi a;
    ll m = n;
    for(ll i = 2; i * i <= m; ++i) {
        if (m % i == 0) {
            a.push_back(i);
            while(m % i == 0) {
                m /= i;
            }
            i = 2;
        }
    }
    if (m != 1) a.push_back(m);
    if (a.size() == 1) cout << a[0];
    else cout << 1;
}