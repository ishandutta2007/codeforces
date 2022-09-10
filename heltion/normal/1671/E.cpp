#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    string s;
    cin >> n >> s;
    s = " " + s;
    vector<int> rk((1 << (n + 1)));
    auto f = [&](int x) {
        int a = rk[x * 2], b = rk[x * 2 + 1];
        if (a > b) swap(a, b);
        return make_tuple(s[x], a, b);
    };
    for (int i = n - 1; i >= 0; i -= 1) {
        vector<int> p;
        for (int j = (1 << i); j < (1 << (i + 1)); j += 1)
            p.push_back(j);
        sort(p.begin(), p.end(), [&](int x, int y){
            return f(x) < f(y);
        });
        int k = 0;
        for (int j = 0; j < p.size(); j += 1) {
            if (not j or f(p[j]) != f(p[j - 1]))
                k += 1;
            rk[p[j]] = k - 1;
        }
    }
    //for (int i = 1; i < (1 << n); i += 1) cout << rk[i] << " "; cout << "\n";
    function<LL(int)> DFS = [&](int u) {
        if (u * 2 >= (1 << n)) return 1LL;
        if (rk[u * 2] == rk[u * 2 + 1]) {
            LL res = DFS(u * 2);
            return res * res % mod;
        }
        return DFS(u * 2) * DFS(u * 2 + 1) * 2 % mod;
    };
    cout << DFS(1);
}