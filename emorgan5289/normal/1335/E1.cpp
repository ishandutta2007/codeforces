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

const int A = 200;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; fin >> t;
    while (t--) {
        int n; fin >> n;
        vector<int> a(n);
        for (auto& x : a) {
            fin >> x; x--;
        }
        vector<vector<int>> b(A), p(A, vector<int>(n));
        for (int i = 0; i < n; i++)
            b[a[i]].pb(i);
        for (int i = 0; i < A; i++)
            for (int j = 0; j < n; j++)
                p[i][j] = (a[j] == i ? 1 : 0) + (j == 0 ? 0 : p[i][j-1]);

        int out = 1;
        for (int x = 0; x < A; x++)
            for (int y = 0; y < A; y++)
                for (int i = 0; i < b[x].size()/2; i++) {
                    int r = b[x][i], l = b[x][b[x].size()-1-i]-1;
                    out = max(out, 2*(i+1)+p[y][l]-p[y][r]);
                }
        cout << out << "\n";
    }
}