#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ull 1000000000000000000
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#pragma GCC optimize ("O3")
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
ifstream fin("../../input.in");
#define cin fin
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n; fin >> n;
    vector<int> a(n-1);
    for (auto& x : a) {
        fin >> x; x--;
    }
    vector<vector<int>> adj(n);
    vector<int> c(n);
    for (auto& x : a) c[x]++;
    map<int, int> m;
    for (int i = 0; i < n; i++)
        if (c[i] == 0) m[i] = i;
    for (int i = n-2; i >= 0; i--) {
        int x = a[i];
        c[x]--;
        auto it = m.begin();
        adj[x].push_back(it->second);
        int w = max(x, it->first);
        m.erase(it);
        if (c[x] == 0) m[w] = x;
    }
    cout << m.begin()->second+1 << "\n";
    for (int i = 0; i < n; i++)
        for (int j : adj[i])
            cout << i+1 << " " << j+1 << "\n";
}