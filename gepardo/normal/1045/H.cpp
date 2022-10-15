#include <bits/stdc++.h>

using namespace std;

inline string dec(string a) {
    if (a == "1") {
        return "";
    }
    int p = (int)a.size() - 1;
    while (p >= 0 && a[p] == '0') {
        a[p] = '1';
        p--;
    }
    assert(p >= 0);
    a[p] = '0';
    if (p == 0) {
        a.erase(0, 1);
    }
    return a;
}

typedef long long i64;

const i64 mod = (i64)1e9 + 7;

inline i64 mulMod(i64 a, i64 b) {
    return (a*b) % mod;
}

inline i64 powMod(i64 a, i64 n) {
    i64 res = 1;
    while (n) {
        if (n & 1) {
            res = mulMod(res, a);
        }
        a = mulMod(a, a);
        n >>= 1;
    }
    return res;
}

inline i64 rev(i64 a) {
    return powMod(a, mod-2);
}

auto &qout = cout;

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
    #endif
    string a, b; cin >> a >> b;
    a = dec(a);
    const int mx = 500000;
    vector<i64> F(mx), R(mx);
    F[0] = 1;
    for (int i = 1; i < mx; i++) {
        F[i] = mulMod(F[i-1], i);
    }
    for (int i = 0; i < mx; i++) {
        R[i] = rev(F[i]);
    }

    auto C = [&](int n, int k) -> i64 {
        if (n == -1 && k == -1) {
            return 1;
        }
        if (!(0 <= k && k <= n)) {
            return 0;
        }
        return mulMod(F[n], mulMod(R[k], R[n-k]));
    };

    int c[2][2];
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            cin >> c[i][j];
        }
    }

    auto get = [&](const string &pref, int beg, int c[2][2], int len) -> i64 {
        //cout << "get " << pref << string(len, '*') << endl;
        //cout << "c :: " << c[0][0] << " " << c[0][1] << " " << c[1][0] << " " << c[1][1] << endl;
        int c00 = c[0][0], c01 = c[0][1], c10 = c[1][0], c11 = c[1][1];
        if (c00 < 0 || c01 < 0 || c10 < 0 || c11 < 0) {
            return 0;
        }
        int tlen = c00 + c01 + c10 + c11;
        if (tlen != len) {
            //cout << "bad len" << endl;
            return 0;
        }
        int gc = c01 + c10 + 1;
        int dif = c01 - c10;
        if (beg) {
            dif *= -1;
        }
        if (gc > tlen+1 || (dif != 0 && dif != 1)) {
            //cout << "groups " << gc << " " << tlen << " :: " << dif << endl;
            return 0;
        }
        int g0 = (gc+1) / 2, g1 = gc / 2;
        if (beg) {
            swap(g0, g1);
        }
        int k0 = c00 + g0, k1 = c11 + g1;
        //cout << g0 << " " << g1 << " :: " << gc << " :: " << k0 << " " << k1 << endl;
        i64 res = mulMod(C(k0-1, g0-1), C(k1-1, g1-1));
        //cout << "res = " << res << endl;
        return res;
    };

    auto calc = [&](string s) -> i64 {
        if (s.empty()) {
            return 0;
        }
        assert(s[0] == '1');
        i64 res = 0;
        int len = s.size();
        int d[2][2] = {c[0][0], c[0][1], c[1][0], c[1][1]};
        for (int i = 0; i+1 < len; i++) {
            res += get("1", 1, d, i);
            res %= mod;
        }
        string pref = "1";

        auto append = [&](char c) {
            d[pref.back() - '0'][c - '0']--;
            pref += c;
        };

        auto unappend = [&]() {
            char ccc = pref.back();
            pref.pop_back();
            d[pref.back() - '0'][ccc - '0']++;
        };

        for (int i = 1; i < len; i++) {
            if (s[i] == '1') {
                append('0');
                res += get(pref, pref.back() - '0', d, len-i-1);
                res %= mod;
                unappend();
            }
            append(s[i]);
        }

        res += get(pref, pref.back() - '0', d, 0);
        res %= mod;

        return res;
    };

    qout << (calc(b) - calc(a) + mod) % mod << endl;
    return 0;
}