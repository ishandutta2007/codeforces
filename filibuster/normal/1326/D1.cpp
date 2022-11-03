//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>

#define f first
#define s second
#define forn(i, n) for(int i = 0; i < n; i++)

using namespace std;
using li = long long;
using ld = long double;
using pii = pair<int, int>;

const int M = 998244353;

mt19937 rnd(0);

struct Hash {
    int n;
    string s;

    int M = 1e9 + 9;
    int p;

    vector<int> pw, h;

    Hash(string s, int p) : s(s), n(s.size()), p(p) {
//        p = rnd() % 1000 + 41;
        pw.resize(n + 3, 1);
        for(int i = 1; i < pw.size(); i++)
            pw[i] = pw[i - 1] * 1ll * p % M;
//        exit(0);

        h.resize(n + 1, 0);
        for(int i = 1; i <= n; i++)
            h[i] = (h[i - 1] * 1ll * p % M + s[i - 1] - 'a' + 1) % M;
    }

    int get(int l, int r) {
        return (h[r] - h[l] * 1ll * pw[r - l] % M + M) % M;
    }
};

void solve() {
    string s;
    cin >> s;

    string r = s;
    reverse(r.begin(), r.end());

    int pp1 = rnd() % 1000 + 41;
    Hash hs(s, pp1);//exit(0);
    Hash hr(r, pp1);
//cout << "fs" << endl;
    int n = s.length();

    int x = 0;
    for(int i = 0; i < n / 2; i++) {
        if(s[i] != s[n - i - 1]) {
            x = i;
            break;
        }
    }

//cout << "fs" << endl;
    int y = 0;
    for(int i = 0; i * 2 + x * 2 <= n; i++) {//cout << "fs" << endl;
        if(hs.get(x, x + i) == hr.get(n - x - i * 2, n - x - i)) {
            y = i * 2;
        }

        if(i * 2 + 1 + x * 2 <= n) {
            if(hs.get(x, x + i) == hr.get(n - x - i * 2 - 1, n - x - i - 1)) {
                y = i * 2 + 1;
            }
        }
    }

    int z = 0;
    for(int i = 0; i * 2 + x * 2 <= n; i++) {//cout << "fs" << endl;
        if(hr.get(x, x + i) == hs.get(n - x - i * 2, n - x - i)) {
            z = i * 2;
        }

        if(i * 2 + 1 + x * 2 <= n) {
            if(hr.get(x, x + i) == hs.get(n - x - i * 2 - 1, n - x - i - 1)) {
                z = i * 2 + 1;
            }
        }
    }

    string t = "";
    for(int i = 0; i < x; i++)
        t += s[i];
    if(y > z) {
        for(int i = x; i < x + y; i++)
            t += s[i];
    } else {
        for(int i = x; i < x + z; i++)
            t += r[i];
    }

//    cout << x << ' ' << y << ' ' << z << endl;

//    for(int i = n - 1; i >= n - x; i--)
//        t += s[i];
    for(int i = x - 1; i >= 0; i--)
        t += s[i];

    cout << t << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);



    int t = 1;
    cin >> t;

    while(t--)
        solve();
}