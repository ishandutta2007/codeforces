#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int get(int x) {
    int n = 1;
    while (n * (n - 1) / 2 < x) ++n;
    if (n * (n - 1) / 2 != x) {
        cout << "Impossible\n";
        exit(0);
    }
    return n;
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int zeroes = get(a);
    int ones = get(d);
    if (a == 0 && zeroes * ones != b + c) --zeroes;
    if (d == 0 && zeroes * ones != b + c) --ones;
    if (zeroes * ones != b + c) {
        cout << "Impossible\n";
        return 0;
    }   
    int num = 0;
    int cur = zeroes * ones;
    int need = -1;
    while (cur > c) {
        if (cur - ones >= c) {
            cur -= ones;
            ++num;
        } else {
            need = c - (cur - ones);
            cur = c;
        }
    }
    string res;
    for (int i = 0; i < num; ++i) res += '0';
    if (need == -1) {
        for (int i = 0; i < ones; ++i) res += '1';
        for (int i = 0; i < zeroes - num; ++i) res += '0';
    } else {
        for (int i = 0; i < need; ++i) res += '1';
        res += '0';
        for (int i = 0; i < ones - need; ++i) res += '1';
        for (int i = 0; i < zeroes - num - 1; ++i) res += '0';
    }
    cout << res << '\n';
}