#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int n, k; cin >> n >> k;
    vector<int> m(n); for (auto& x : m) cin >> x;
    vector<int> c(k); for (auto& x : c) cin >> x;
    sort(all(m), greater<int>());
    int a = 1, b = n;
    while (a < b) {
        int r = (a+b)/2;
        bool v = 1;
        vector<int> w(r);
        for (int i = 0; i < n; i++) {
            w[i%r]++;
            v = v && w[i%r] <= c[m[i]-1];
        }
        if (v) b = r;
        else a = r+1;
    }

    vector<vector<int>> out(a);
    for (int i = 0; i < n; i++) {
        out[i%a].pb(m[i]);
    }
    cout << a << "\n";
    for (auto& row : out) {
        cout << row.size() << " ";
        for (int i = 0; i < row.size(); i++)
            cout << row[i] << " \n"[i == row.size()-1];
    }
}