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

const int maxn = 8005;
int a[maxn], p[maxn], f[maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
            p[i] = a[i] + (i == 0 ? 0 : p[i-1]);
            f[a[i]] = 0;
        }
        for (int i = 0; i < n; i++)
            for (int j = i+1; j < n; j++) {
                int d = p[j] - (i == 0 ? 0 : p[i-1]);
                if (d <= n) f[d] = 1;
            }
        ll out = 0;
        for (int i = 0; i < n; i++) {
            out += f[a[i]];
        }
        cout << out << "\n";
    }
}