#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int maxn = 100005;
int n, a[maxn];

int maxsum(int l, int r) {
    int x = 0, p = 0, m = 0;
    for (int i = l; i <= r; i++) {
        p += a[i];
        x = max(x, p-m);
        m = min(m, p);
    }
    return x;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int out = 0;
    for (int j = 0; j <= 30; j++) {
        int l = 0;
        for (int i = 0; i <= n; i++)
            if (i == n || a[i] > j) {
                out = max(out, maxsum(l, i-1)-j);
                // debug(l, i-1, maxsum(l, i-1), j);
                l = i+1;
            }
    }
    cout << out << "\n";
}