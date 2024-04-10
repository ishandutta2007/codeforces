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

#define min3(x, y, z) min(x, min(y, z))

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, m; fin >> n >> m;
    vector<vector<bool>> a(n, vector<bool>(m));
    vector<vector<bool>> r(n, vector<bool>(m, 0));
    vector<vector<int>> sz(n, vector<int>(m));
    vector<vector<int>> w(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            char c; fin >> c; a[i][j] = c != 'X';
            sz[i][j] = a[i][j] ? 0 : (min(i, j) == 0 ? 1 : 1+min3(sz[i-1][j-1], sz[i-1][j], sz[i][j-1]));
        }
    deque<pair<int, int>> s;
    for (int i = n-1; i >= 0; i--) {
        s.clear();
        for (int j = m-1; j >= 0; j--) {
            while (!s.empty() && s.back().first <= sz[i][j])
                s.pop_back();
            s.push_back({sz[i][j], j-sz[i][j]});
            while (!s.empty() && s.front().second >= j)
                s.pop_front();
            w[i][j] = s.empty() ? 0 : s.front().first;
        }
    }
    int out = inf;
    for (int j = m-1; j >= 0; j--) {
        s.clear();
        for (int i = n-1; i >= 0; i--) {
            while (!s.empty() && s.back().first <= w[i][j])
                s.pop_back();
            s.push_back({w[i][j], i-w[i][j]});
            while (!s.empty() && s.front().second >= i)
                s.pop_front();
            if (!s.empty())
                out = min(out, s.front().first);
        }
    }
    out = (out-1)/2;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (sz[i][j] >= (2*out+1))
                r[i-out][j-out] = 1;
    cout << out << "\n";
    for (auto& y : r) {
        for (auto x : y) cout << (x ? 'X' : '.');
        cout << "\n";
    }
}