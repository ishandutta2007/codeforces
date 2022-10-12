#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ull 1000000000000000000
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()

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
    unordered_map<int, int> m;
    for (int i = 0; i < n; i++) {
        int x; fin >> x;
        m[x]++;
    }
    vector<int> a(n+1, 0);
    for (auto& p : m)
        for (int i = 0; i < p.second; i++)
            a[i]++;

    int r = 0, w = 0, h = 0;
    for (int i = 1; i <= ceil(sqrt(n)); i++) {
        r += a[i-1];
        for (int j = i; i*j <= r; j++)
            if (i*j > w*h) {
                w = j; h = i;
            }
    }
    cout << w*h << " " << h << " " << w << "\n";
    vector<pair<int, int>> b; b.reserve(m.size());
    for (auto& p : m)
        b.push_back({p.second, p.first});
    sort(all(b));
    vector<vector<int>> out(h, vector<int>(w));
    int j = 0;
    for (int q = b.size()-1; q >= 0; q--) {
        auto p = b[q];
        for (int i = 0; i < min(p.first, h); i++) {
            out[j%h][j/h] = p.second;
            j++;
            if (j >= w*h) break;
        }
        if (j >= w*h) break;
    }
    // if (w == 2 && h == 2 && out[0][1] == out[1][0]) {
    //     for (int i = 0; i < h; i++) {
    //         for (int j = 0; j < w; j++)
    //             cout << out[i][j] << " ";
    //         cout << "\n";
    //     }
    //     return 0;
    // }
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
            cout << out[i][(j-i+w)%w] << " ";
        cout << "\n";
    }
}