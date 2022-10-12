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
    int n, k; fin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
        char c; fin >> c;
        a[i] = c == 'R' ? 1 : 0;
    }
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        p[i] = a[i] + (i == 0 ? 0 : p[i-1]);

    int inversions = 0;
    for (int i = 0; i < n; i++)
        if (a[i] == 0) inversions += p[i];
    if (inversions < k) {
        cout << "-1\n"; return 0;
    }

    vector<vector<int>> res; 
    res.reserve(k);

    for (int i = 0; i < n; i++) {
        if (inversions > k) {
            res.pb({}); k--;
        }
        for (int j = n-1; j >= 1; j--) {
            if (inversions == k) {
                goto next;
            }
            if (a[j] == 0 && a[j-1] == 1) {
                res.back().pb(j);
                swap(a[j], a[j-1]);
                inversions--;
                j--;
            }
        }
    }
    next:;

    if (k < 0) {
        cout << "-1\n"; return 0;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j < n; j++) {
            if (a[j] == 0 && a[j-1] == 1) {
                res.pb({j});
                swap(a[j], a[j-1]);
                k--;
            }
        }
    }

    if (k < 0) {
        cout << "-1\n"; return 0;
    }

    for (auto& row : res) {
        cout << row.size() << " ";
        for (auto& x : row) cout << x << " ";
        cout << "\n";
    }
}