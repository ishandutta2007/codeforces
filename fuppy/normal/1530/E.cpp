/*
#pragma GCC target("avx2")
#pragma GCC optimize("O3")
#pragma GCC optimize("unroll-loops")
//*/

#include <bits/stdc++.h>

// #include <atcoder/all>

using namespace std;
// using namespace atcoder;

#define DEBUG(x) cerr << #x << ": " << x << endl;
#define DEBUG_VEC(v)                                        \
    cerr << #v << ":";                                      \
    for (int iiiiiiii = 0; iiiiiiii < v.size(); iiiiiiii++) \
        cerr << " " << v[iiiiiiii];                         \
    cerr << endl;
#define DEBUG_MAT(v)                            \
    cerr << #v << endl;                         \
    for (int i = 0; i < v.size(); i++) {        \
        for (int j = 0; j < v[i].size(); j++) { \
            cerr << v[i][j] << " ";             \
        }                                       \
        cerr << endl;                           \
    }
typedef long long ll;
// #define int ll

#define vi vector<int>
#define vl vector<ll>
#define vii vector<vector<int>>
#define vll vector<vector<ll>>
#define vs vector<string>
#define pii pair<int, int>
#define pis pair<int, string>
#define psi pair<string, int>
#define pll pair<ll, ll>
template <class S, class T>
pair<S, T> operator+(const pair<S, T> &s, const pair<S, T> &t) {
    return pair<S, T>(s.first + t.first, s.second + t.second);
}
template <class S, class T>
pair<S, T> operator-(const pair<S, T> &s, const pair<S, T> &t) { return pair<S, T>(s.first - t.first, s.second - t.second); }
template <class S, class T>
ostream &operator<<(ostream &os, pair<S, T> p) {
    os << "(" << p.first << ", " << p.second << ")";
    return os;
}
#define X first
#define Y second
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep1(i, n) for (int i = 1; i <= (int)(n); i++)
#define rrep(i, n) for (int i = (int)(n)-1; i >= 0; i--)
#define rrep1(i, n) for (int i = (int)(n); i > 0; i--)
#define REP(i, a, b) for (int i = a; i < b; i++)
#define in(x, a, b) (a <= x && x < b)
#define all(c) c.begin(), c.end()
void YES(bool t = true) {
    cout << (t ? "YES" : "NO") << endl;
}
void Yes(bool t = true) { cout << (t ? "Yes" : "No") << endl; }
void yes(bool t = true) { cout << (t ? "yes" : "no") << endl; }
void NO(bool t = true) { cout << (t ? "NO" : "YES") << endl; }
void No(bool t = true) { cout << (t ? "No" : "Yes") << endl; }
void no(bool t = true) { cout << (t ? "no" : "yes") << endl; }
template <class T>
bool chmax(T &a, const T &b) {
    if (a < b) {
        a = b;
        return 1;
    }
    return 0;
}
template <class T>
bool chmin(T &a, const T &b) {
    if (a > b) {
        a = b;
        return 1;
    }
    return 0;
}
#define UNIQUE(v) v.erase(std::unique(v.begin(), v.end()), v.end());
const ll inf = 1000000001;
const ll INF = (ll)1e18 + 1;
const long double pi = 3.1415926535897932384626433832795028841971L;
int popcount(ll t) { return __builtin_popcountll(t); }
// int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
// int dx2[8] = { 1,1,0,-1,-1,-1,0,1 }, dy2[8] = { 0,1,1,1,0,-1,-1,-1 };
vi dx = {0, 1, 0, -1}, dy = {-1, 0, 1, 0};
vi dx2 = {1, 1, 0, -1, -1, -1, 0, 1}, dy2 = {0, 1, 1, 1, 0, -1, -1, -1};
struct Setup_io {
    Setup_io() {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        cout << fixed << setprecision(25);
    }
} setup_io;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
// #define mp make_pair
//#define endl '\n'

string solve2(string s) {
    sort(all(s));
    map<char, int> mp;
    for (char c : s)
        mp[c]++;

    int cnt0 = mp[s[0]], cnt1 = mp[s.back()];

    string res;
    if (cnt0 >= 2 && cnt0 <= cnt1 + 2) {
        res += s[0];
        res += s[0];
        cnt0 -= 2;
        while (cnt0 > 0 || cnt1 > 0) {
            if (cnt1 > 0) {
                res += s.back();
                cnt1--;
            }
            if (cnt0 > 0) {
                res += s[0];
                cnt0--;
            }
        }
    } else {
        res += s[0];
        rep(i, cnt1) res += s.back();
        rep(i, cnt0 - 1) res += s[0];
    }
    return res;
}

string sub(string t1, string t2) {
    string res;
    rep(i, 2) {
        res.push_back(t1[0]);
        t1.pop_back();
    }
    reverse(all(t2));
    while (t1.size() > 0 || t2.size() > 0) {
        if (t2.size() > 0) {
            res += t2.back();
            t2.pop_back();
        }
        if (t1.size() > 0) {
            if (res.back() == t1.back()) return "";
            res += t1.back();
            t1.pop_back();
        }
    }
    return res;
}

string solve3(string s) {
    string t1, t2;
    sort(all(s));
    rep(i, s.size()) {
        if (s[i] == s[0])
            t1 += s[i];
        else
            t2 += s[i];
    }

    string res;
    if (t1.size() >= 2) {
        res = sub(t1, t2);
        if (res != "") return res;
    }

    res.clear();
    res.push_back(t1.back());
    t1.pop_back();
    char add = t2[0];
    res += t2[0];
    t2.erase(t2.begin());
    res += t1;
    rep(i, t2.size()) {
        if (t2[i] != add) {
            res += t2[i];
            t2.erase(t2.begin() + i);
            break;
        }
    }
    res += t2;
    return res;
}

string corner(string s, map<char, int> mp) {
    sort(all(s));
    char ini;
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        if (itr->second == 1) {
            ini = itr->first;
            break;
        }
    }
    string res;
    res += ini;
    rep(i, s.size()) {
        if (s[i] == ini) continue;
        res += s[i];
    }
    return res;
}

void solve() {
    string s;
    cin >> s;
    map<char, int> mp;
    for (char c : s)
        mp[c]++;

    string ans;

    int mi = inf;
    for (auto itr = mp.begin(); itr != mp.end(); itr++) {
        chmin(mi, itr->second);
    }

    if (mi == 1) {
        ans = corner(s, mp);
    } else {
        if (mp.size() == 1) {
            ans = s;
        } else if (mp.size() == 2) {
            ans = solve2(s);
        } else {
            ans = solve3(s);
        }
    }
    cout << ans << endl;
}

signed main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
}