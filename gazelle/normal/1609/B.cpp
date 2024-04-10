#include <bits/stdc++.h>
#define FOR(i, n, m) for(long long i = (n); i < (long long)(m); i++)
#define REP(i, n) FOR(i, 0, n)
#define ALL(v) v.begin(), v.end()
#define pb push_back
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
constexpr ll inf = 1000000000;
constexpr ll mod = 998244353;
constexpr ld eps = 1e-6;

template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> p) {
    os << to_string(p.first) << " " << to_string(p.second);
    return os;
}
template <typename T> ostream &operator<<(ostream &os, vector<T> &v) {
    REP(i, v.size()) {
        if(i)
            os << " ";
        os << v[i];
    }
    return os;
}
string s;
int abc(int i) {
    int n = s.size();
    if(i >= n - 2 || i < 0)
        return 0;
    if(s[i] == 'a' && s[i + 1] == 'b' && s[i + 2] == 'c')
        return 1;
    else
        return 0;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;
    cin >> s;
    int cnt = 0;
    REP(i, n - 2)
    cnt += abc(i);
    REP(i, q) {
        int x;
        char c;
        cin >> x >> c;
        x--;
        int old_c = abc(x - 2) + abc(x - 1) + abc(x);
        s[x] = c;
        int new_c = abc(x - 2) + abc(x - 1) + abc(x);
        cnt = cnt - old_c + new_c;
        cout << cnt << "\n";
    }
    return 0;
}