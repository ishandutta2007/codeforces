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
        int n, m; fin >> n >> m;
        cout << 'W';
        for (int i = 0; i < m-1; i++)
            cout << 'B';
        cout << '\n';
        for (int i = 0; i < n-1; i++) {
            for (int j = 0; j < m; j++)
                cout << 'B';
            cout << '\n';
        }
    }
}