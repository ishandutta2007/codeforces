#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e5 + 7;

int n;
int a[MAXN], b[MAXN];

int dp[MAXN];
int pref[MAXN];

int mdiv(int a, int b) {
    int sp = 1;
    if (a < 0) {
        sp *= -1;
        a *= -1;
    }   
    if (b < 0) {
        sp *= -1;
        b *= -1;
    }   
    return ((a + b - 1) / b) * sp;
}   

int get(pair <int, int> a, pair <int, int> b) {
    //x * a.first + a.second = x * b.first + b.second
    //x * (a.first - b.first) = b.second - a.second
    //x = (b.second - a.second) / (a.first - b.first)
    return mdiv(b.second - a.second, a.first - b.first);
}

vector <pair <int, int> > v;

void add(pair <int, int> l) {
    //cout << "add " << l.first << ' ' << l.second << '\n';
    while (2 <= v.size() && get(v.back(), l) <= get(v[v.size() - 2], v.back())) {
        v.pop_back();
    }   
    v.push_back(l);
}   

int get(pair <int, int> l, int x) {
    //cout << "get " << l.first << ' ' << l.second << ' ' << x << '\n';
    return l.first * x + l.second;
}   

int get(int x) {
    int l = -1;
    int r = (int)v.size() - 1;
    while (l < r - 1) {
        int m = (l + r) >> 1;
        if (get(v[m], v[m + 1]) <= x) {
            l = m;
        }   
        else {
            r = m;
        }   
    }   
    return get(v[r], x);
}

signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }   

    for (int i = 0; i < n; ++i) {
        pref[i + 1] = pref[i] + a[i];
    }   

    add({b[0], dp[0]});
    for (int i = 1; i < n; ++i) {
        dp[i] = get(a[i]);
        add({b[i], dp[i]});
    }   

    cout << dp[n - 1] << '\n';
    return 0;
}