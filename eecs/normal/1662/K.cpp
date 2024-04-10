// test
#include <bits/stdc++.h>
using namespace std;

template <typename T> istream &operator>>(istream &is, vector<T> &v) {
    for (auto &i : v)
        is >> i;
    return is;
}
template <typename T> ostream &operator<<(ostream &os, vector<T> v) {
    for (auto &i : v)
        os << i << ' ';
    return os;
}
template <typename T1, typename T2>
istream &operator>>(istream &is, pair<T1, T2> &p) {
    is >> p.first >> p.second;
    return is;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &os, pair<T1, T2> &p) {
    os << p.first << ' ' << p.second;
    return os;
}
template <typename T1, typename T2>
pair<T1, T2> operator-(pair<T1, T2> &a, pair<T1, T2> &b) {
    return make_pair(a.first - b.first, a.second - b.second);
}
template <typename T1, typename T2>
pair<T1, T2> operator+(pair<T1, T2> &a, pair<T1, T2> &b) {
    return make_pair(a.first + b.first, a.second + b.second);
}

int main(int argc, char **argv) {
    cin.tie(nullptr)->sync_with_stdio(false);
    vector<array<double, 2>> p(3);
    for (auto &i : p) {
        cin >> i[0] >> i[1];
    }

    array<double, 2> ret;

    auto dis = [&](array<double, 2> a, array<double, 2> b) {
        return (a[0] - b[0]) * (a[0] - b[0]) + (a[1] - b[1]) * (a[1] - b[1]);
    };

    auto dot = [&](array<double, 2> a, array<double, 2> b) {
        return a[0] * b[1] - a[1] * b[0];
    };

    auto area = [&](array<double, 2> a, array<double, 2> b, array<double, 2> c) {
        double ret = dot(a, b) + dot(b, c) + dot(c, a);
        return fabs(ret) / 2;
    };

    auto fermat_dis = [&](array<double, 2> a, array<double, 2> b, array<double, 2> c) {
        double A = dis(b, c), B = dis(a, c), C = dis(b, a);
        if (A + B + sqrt(A * B) < C) {
            return sqrt(A) + sqrt(B);
        }
        if (C + B + sqrt(C * B) < A) {
            return sqrt(C) + sqrt(B);
        }
        if (A + C + sqrt(A * C) < B) {
            return sqrt(A) + sqrt(C);
        }
        double d = A + B + C + 4 * sqrt(3) * area(a, b, c);
        return sqrt(d / 2);
    };
    auto chk = [&]() {
        return max({fermat_dis(p[0], p[1], ret), fermat_dis(p[0], p[2], ret), fermat_dis(p[2], p[1], ret)});
    };
    function<double(int)> ternary_search = [&](int x) {
        if (x == 2) {
            return chk();
        }
        double l = -1e4, r = 1e4, midl = (l * 2 + r) / 3,
               midr = (l + r * 2) / 3, retl, retr, ans = 1e12;
        int T = 80;
        while (T--) {
            ret[x] = midl;
            retl = ternary_search(x + 1);
            ret[x] = midr;
            retr = ternary_search(x + 1);
            ans = min({ans, retl, retr});
            if (retl < retr) {
                r = midr;
            } else {
                l = midl;
            }
            midl = (l * 2 + r) / 3, midr = (l + r * 2) / 3;
        }
        return ans;
    };
    cout << setprecision(10) << fixed << ternary_search(0) << endl;
    return 0;
}