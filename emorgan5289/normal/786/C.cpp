#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int N = 1e5+5, S = 500;
int a[N], f[S][N], l[N], r[N], v[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int s = sqrt(n);
    int x = 1;
    for (int k = 1; k < s; k++) {
        x = 1;
        int d = 0, p = 0;
        for (int i = 0; i < n; i++) {
            if (!f[0][a[i]]) d++;
            if (d > k) {
                l[x-1] = p, r[x-1] = i;
                x++, d = 1;
                while (p < i) f[0][a[p++]]--;
            }
            f[0][a[i]]++;
        }
        l[x-1] = p, r[x-1] = n;
        while (p < n) f[0][a[p++]]--;
        cout << x << " ";
    }
    for (int i = 0; i < x; i++)
        for (int j = l[i]; j < r[i]; j++)
            if (f[i][a[j]]++ == 0) v[i]++;
    for (int k = s; k <= n; k++) {
        for (int i = 0; i < x; i++) {
            if (i > 0)
                while (l[i] < r[i-1])
                    if (--f[i][a[l[i]++]] == 0) v[i]--;
            while (v[i]+(f[i][a[r[i]]] == 0) <= k && r[i] < n)
                if (f[i][a[r[i]++]]++ == 0) v[i]++;
        }
        while (l[x-1] == n) x--;
        cout << x << " \n"[k == n];
    }
}