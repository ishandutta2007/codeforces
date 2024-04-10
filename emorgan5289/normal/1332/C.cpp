#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; fin >> t;
    while (t--) {
        int n, k; fin >> n >> k;
        string s; fin >> s;
        vector<vector<int>> f(k, vector<int>(26));
        vector<int> g(k), m(k, -1);
        for (int i = 0; i < n; i++) {
            f[min(i%k, (n-1-i)%k)][s[i]-'a']++;
            g[min(i%k, (n-1-i)%k)]++;
        }
        int out = 0;
        for (int i = 0; i < k; i++)
            for (int j = 0; j < 26; j++)
                m[i] = max(m[i], f[i][j]);
        for (int i = 0; i < k; i++)
            out += g[i]-m[i];
        cout << out << "\n";
    }
}