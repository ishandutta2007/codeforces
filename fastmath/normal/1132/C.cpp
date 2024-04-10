#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    vector <int> l(q), r(q);
    vector <vector <int> > a(n + 1);
    for (int i = 0; i < q; i++) {
        cin >> l[i] >> r[i];
        for (int x = l[i]; x <= r[i]; x++) a[x].push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < q; i++) {
        vector <int> cnt(n + 3);
        for (int j = 0; j < q; j++) {
            if (i != j) {
                cnt[l[j]]++;
                cnt[r[j] + 1]--;
            }
        }
        for (int i = 1; i <= n; i++) {
            cnt[i] += cnt[i - 1];
        }
        int sum = 0;
        int me = i;
        vector <int> ret(q);
        for (int i = 1; i <= n; i++) {
            if (cnt[i] > 1) {
                sum++;
            }
            if (cnt[i] == 1) {
                sum++;
                int x = -1;
                for (int y : a[i]) if (y != me) x = y;
                ret[x]++;        
            }
        }
        int pep = 1e9;
        for (int x= 0; x < q; x++) if (x != i) pep = min(pep, ret[x]);
        sum -= pep;
        ans = max(ans, sum);
    }
    cout << ans << endl;
}