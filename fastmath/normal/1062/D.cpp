#include <bits/stdc++.h>

using namespace std;

#define int long long

const int MAXN = 1e5 + 7;

map <int, vector <int> > g;

int get(int a, int b) {
    a = abs(a); b = abs(b);
    if (a % b == 0) {
        return a / b;
    }   
    else {
        return b / a;
    }   
}

signed main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    for (int i = 2; i <= n; ++i) {
        for (int t = 2; abs(i * t) <= n; ++t) {
            g[i].push_back(i * t);
        }   
        for (int t = -2; abs(i * t) <= n; --t) {
            g[i].push_back(i * t);
        }   
    }   

    for (int i = -2; i >= -n; --i) {
        for (int t = 2; abs(i * t) <= n; ++t) {
            g[i].push_back(i * t);
        }   
        for (int t = -2; abs(i * t) <= n; --t) {
            g[i].push_back(i * t);
        }   
    }                             
    
    int sum = 0;
    for (int u = -n; u <= n; ++u) {
        if (g.find(u) == g.end()) continue;
        for (int v : g[u]) {
            sum += get(u, v);        
        }   
    }   

    cout << sum << '\n';

    return 0;
}