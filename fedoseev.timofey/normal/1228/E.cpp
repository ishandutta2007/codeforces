#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const int md = 1e9 + 7;
 
int mul(int a, int b) {
    return ((ll)a * b) % md;
}
 
int power(int a, ll b) {
    int res = 1;
    while (b > 0) {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}

int add(int a, int b) {
    a += b;
    if (a >= md) a -= md;
    return a;
}

int sub(int &a, int b) {
    a -= b;
    if (a < 0) a += md;
    return a;
}

const int N = 1000;

int f[N], rf[N];

int pw1[N];
int pw2[N];

int C(int n, int k) {
    return mul(f[n], mul(rf[k], rf[n - k]));
}


int main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    f[0] = 1;
    for (int i = 1; i < N; ++i) f[i] = mul(i, f[i - 1]);
    for (int i = 0; i < N; ++i) rf[i] = power(f[i], md - 2);
    int n, k;
    cin >> n >> k;
    pw1[0] = 1;
    pw2[0] = 1;
    for (int i = 1; i < N; ++i) pw1[i] = mul(pw1[i - 1], k);
    for (int i = 1; i < N; ++i) pw2[i] = mul(pw2[i - 1], k - 1);
    int res = 0;
    for (int i = 0; i <= n; ++i) {
        int cur = mul(C(n, i), power(sub(pw1[n - i], pw2[n - i]), n));
        cur = mul(cur, power(pw2[i], n));
        if (i % 2 == 0) res = add(res, cur);
        else res = sub(res, cur);
    }
    cout << res << '\n';
}