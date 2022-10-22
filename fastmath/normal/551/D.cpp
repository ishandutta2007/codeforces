#include <bits/stdc++.h>

using namespace std;

#define int long long

int n, k, l, m;

int mod(int n) {
    return (n % m + m) % m;
}

int fp(int a, int b) {
    if (b == 0) return 1;
    int t = fp(a, b >> 1);
    if (b & 1) {
        return mod(mod(t * t) * a);
    }   
    else {
        return mod(t * t);
    }   
}

typedef vector <vector <int> > Matrix;

const int N = 2;

Matrix mult(Matrix a, Matrix b) {
    Matrix ans(N);
    for (int i = 0; i < N; ++i) {
        ans[i].resize(N);
    }
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            for (int k = 0; k < N; ++k) {
                ans[i][j] += a[i][k] * b[k][j];
                ans[i][j] = mod(ans[i][j]);
            }   
        }   
    }   
    return ans;
}   

Matrix fib = {{0, 1}, {1, 1}};

Matrix fp(Matrix a, int p) {
    if (p == 0) {
        return {{1, 0}, {0, 1}};
    }   
    auto t = fp(a, p >> 1);
    if (p & 1) {
        return mult(mult(t, t), a);
    }   
    else {
        return mult(t, t);
    }   
}   

int get(int n) {
    auto t = fp(fib, n + 1);
    return t[1][1];     
}   

signed main() {
    #ifdef HOME
        freopen("input.txt", "r", stdin);
    #endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> k >> l >> m;

    if (m == 1) {
        cout << "0\n";
        exit(0);
    }   

    if (l < 60 && k >= (1ll << l)) {
        cout << "0\n";
        exit(0);
    }

    int ans = mod(1);

    int x = get(n);
    int y = mod(fp(2, n) - x);

    for (int i = 0; i < l; ++i) {
        if ((k >> i) & 1) {
            ans = mod(ans * y);
        }   
        else {
            ans = mod(ans * x);
        }   
    }   

    cout << ans << '\n';
    return 0;
}