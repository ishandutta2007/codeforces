#include <bits/stdc++.h>

//#define int long long
#define fi first
#define se second
#define init int n; cin >> n;
#define iniit int n, m; cin >> n >> m;
#define itn int
#define ld long double
#define vpii vector<pii>
#define vvpii vector<vpii>
#define pii pair<int, int>
#define vi vector<int>
#define vvi vector<vi>
#define fr(i, n) for (int i = 0; i < n; ++i)
#define all(x) x.begin(), x.end()
#define pb push_back
#define mp make_pair
#define con continue
#define eb emplace_back
#define SOLVE int t; cin >> t; for(int i = 0; i < t; ++i) solve()

using namespace std;

int gcd (int a, int b) {
    while (b) {
        a %= b;
       swap (a, b);
    }
    return a;
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
    for(auto &i: a) ct(i);
}

void ct(vector<set<int>> &a) {
    for(auto &i: a) {
        for(auto &j: i) cout << j << ' ';
        cout << '\n';
    }
}

void ct(set<int> &a) {
    for(auto i: a) cout << i << ' ';
    cout << '\n';
}

void ct(set<pii> &a) {
    for(auto &i: a) cout << i.first << ':' << i.second << ' ';
    cout << '\n';
}

void ct(pii a) {
    cout << a.first << ':' << a.second << '\n';
}

void ct(pair<double, int> a) {
    cout << a.first << ':' << a.second << '\n';
}

void ct(vector<pair<double, int>> &a) {
    for (auto &i: a) cout << i.fi << ":" << i.se << ' ';
    cout << '\n';
}

void ct(map<int, int> &a) {
    for (auto i = a.begin(); i != a.end(); ++i) {
        cout << i->fi << ':' << i->se << ' ';
    }
    cout << '\n';
}

void ct(map<string, int> &a) {
    for (auto i = a.begin(); i != a.end(); ++i) {
        cout << i->fi << ':' << i->se << ' ';
    }
    cout << '\n';
}

void ci(vector<int> &a) {
    for(int i = 0; i < a.size(); ++i) cin >> a[i];
}

void ci(vector<vector<int>> &a) {
    for(int i = 0; i < a.size(); ++i) ci(a[i]);
}

void ci(pii &a) {
    cin >> a.fi >> a.se;
}


void setup() {
    #ifdef LOCAL
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #else
    ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
    #endif

    srand(time(NULL));
}

int m[3] = {0, -1, 1};

void solve() {
    string s;
    cin >> s;
    int a1 = 0;
    int a2 = 0;
    int a3 = 0;
    int a4 = 0;
    int n = s.size();
    for(auto i: s) {
        if (i == 'L')
            ++a1;
        if (i == 'R')
            ++a2;
        if (i == 'D')
            ++a3;
        if (i == 'U')
            ++a4;
    }

    int r = a1 - a2;
    int u = a4 - a3;
    string ans;
    if (r > 0) 
        a1 -= r;
    if (r < 0)
        a2 += r;
    if (u > 0)
        a4 -= u;
    if (u < 0)
        a3 += u;
    //cout << a1 << ' ' << a2 << ' ' << a3 << ' ' << a4 << '\n';
    if (a1 == 0) {
        cout << min(2, a3 + a4) << '\n';
        fr(i, min(1, a3)) ans += 'D';
        fr(i, min(1, a4)) ans += 'U';
    }
    else if (a3 == 0) {
        cout << min(2, a1 + a2) << '\n';
        fr(i, min(1, a1)) ans += 'L';
        fr(i, min(1, a2)) ans += 'R';
    }
    else {
        cout << a1 + a2 + a3 + a4 << '\n';
        fr(i, a1) ans += 'L';
        fr(i, a3) ans += 'D';
        fr(i, a2) ans += 'R';
        fr(i, a4) ans += 'U';
    }
    cout << ans << '\n';
    //cout << a1 << ' ' << a2 << ' ' << a3 << ' ' << a4 << '\n';
}

signed main() {
    setup();
    SOLVE;
}