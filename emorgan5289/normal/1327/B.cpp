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
    int t; fin >> t;
    while (t--) {
        int n; fin >> n;
        vector<vector<int>> a(n);
        for (int i = 0; i < n; i++) {
            int k; fin >> k;
            for (int j = 0; j < k; j++) {
                int x; fin >> x; a[i].push_back(x-1);
            }
        }

        vector<int> b(n, 0);
        int wait = -1;
        for (int i = 0; i < n; i++) {
            int sel = -1;
            for (auto& x : a[i])
                if (!b[x]) {
                    sel = x; break;
                }
            if (sel != -1)
                b[sel] = 1;
            else {
                wait = i;
                
            }
        }
        if (wait == -1)
            cout << "OPTIMAL\n";
        else {
            cout << "IMPROVE\n";
            for (int j = 0; j < n; j++) {
                if (!b[j]) {
                    cout << (wait+1) << " " << (j+1) << "\n";
                    break;
                }
            }
        }
    }
}