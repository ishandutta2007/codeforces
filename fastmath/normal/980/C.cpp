#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 7;
const int MAXK = 256;

int a[MAXN];
int l[MAXK];
int r[MAXK];

bool ch(int i, int j, int k) {
    int nl = min(l[i], l[j]);
    int nr = max(r[i], r[j]);
    return (nr - nl + 1 <= k);
}

void merge(int i, int j) {
    int nl = min(l[i], l[j]);
    int nr = max(r[i], r[j]);
    for (int p = nl; p <= nr; ++p) {
        l[p] = nl;
        r[p] = nr;
    }
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    for (int i = 0; i < MAXK; ++i) l[i] = r[i] = i;

    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < n; ++i) {
        int p = a[i];

        for (int j = max(0, p - k + 1); j <= p; ++j) {
            if (ch(j, p, k)) {
                merge(j, p);
                break;
            }
        }
    }

    for (int i = 0; i < n; ++i) cout << l[a[i]] << ' ';
    cout << '\n';
    return 0;
}