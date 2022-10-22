#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MOD = 1000 * 1000 + 3;
const int N = 11;
int mod(int n) {
    return (n % MOD + MOD) % MOD;
}   
int fp(int a, int p) {
    int ans = 1, cur = a;
    for (int i = 0; (1ll << i) <= p; ++i) {
        if ((p >> i) & 1) ans = mod(ans * cur);
        cur = mod(cur * cur);
    }
    return ans;
}
int mdiv(int a, int b) {
    return mod(a * fp(b, MOD - 2));
}   
vector <int> getl(vector <int> x, int i) {
    int z = 1;
    for (int j = 0; j < N; ++j) {
        if (j == i) continue;
        z = mod(z * (x[i] - x[j]));
    }   
    vector <int> ans(N);
    vector <int> a;
    for (int j = 0; j < N; ++j) {
        if (j == i) continue;
        a.push_back(-x[j]);
    }   
    for (int mask = 0; mask < (1 << a.size()); ++mask) {
        int f = 1;
        for (int t = 0; t < a.size(); ++t) {
            if ((mask >> t) & 1) f = mod(f * a[t]);
        }   
        int b = __builtin_popcount(mask);
        int px = a.size() - b;
        ans[px] = mod(ans[px] + f);
    }   
    for (int j = 0; j < N; ++j) {
        ans[j] = mdiv(ans[j], z);
    }   
    return ans;
}   
vector <int> interpolation(vector <int> x, vector <int> y) {
    vector <int> ans(N);
    for (int i = 0; i < N; ++i) {
        auto add = getl(x, i);
        for (auto &e : add) e = mod(e * y[i]);
        for (int j = 0; j < N; ++j) {
            ans[j] = mod(ans[j] + add[j]);
        }   
    }   
    return ans;
}   
vector <int> p = {MOD - 1, 0, 1}; 
int get(int x) {
    int ans = 0;
    int f = 1;
    for (int i = 0; i < N; ++i) {
        ans = mod(ans + f * p[i]);
        f = mod(f * x);
    }   
    return ans;
}   
signed main() {

    #ifdef HOME
    while (p.size() < N) p.push_back(0);
    #endif

    vector <int> x, y;
    for (int i = 0; i < N; ++i) {
        x.push_back(i);
        cout << "? " << i << '\n';
        fflush(stdout);
        int t;
        #ifdef HOME
        t = get(i);
        cout << get(i) << '\n';
        #else
        cin >> t;
        #endif
        y.push_back(t);
    }   
    vector <int> ans = interpolation(x, y);
    #ifdef HOME
    for (auto e : ans) cout << e << ' ';
    cout << '\n';
    #endif
    for (int i = 0; i < MOD; ++i) {
        int val = 0;
        int f = 1;
        for (int j = 0; j < (int)ans.size(); ++j) {
            val = mod(val + f * ans[j]);
            f = mod(f * i);
        }   
        if (val == 0) {
            cout << "! " << i << '\n';
            fflush(stdout);
            exit(0);
        }   
    }   
    cout << "! -1\n";
    fflush(stdout);
    exit(0);
}