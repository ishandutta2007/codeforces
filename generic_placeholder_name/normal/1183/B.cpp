#include <bits/stdc++.h>

using namespace std;
int main () {
    int a[99];
    int q;
    cin >> q;
    for (int i=1; i<=q; i++) {
        int maxp=-1, maxn, n, k;
        cin >> n >> k;
        for (int j=0; j<n; j++) cin >> a[j];
        sort(a, a+n);
        for (int l=0; l<n; l++) {
            int p, x = a[l]+2*k, first = 0, last = n - 1;
            while (first <= last) {
                int mid = (first + last) / 2;
                if (a[mid] > x) last = mid - 1;
                else first = mid + 1;
            }
            p = first - 1 < 0 ? -1 : first - 1; p-=(l-1);
            if (maxp<p) {
                maxp=p;
                maxn=a[l]+k;
            }
        }
        if (maxp<n) cout << -1 << endl;
        else cout << maxn << endl;
    }
}