#include <bits/stdc++.h>

using namespace std;

const int MAXN = 5007;

int a[MAXN];

vector <int> pr(int n) {
    int d = 2;
    vector <int> res;
    while (d * d <= n) {
        int p = 0;
        while (n % d == 0) {
            n /= d;
            ++p;
        }
        if (p % 2) res.push_back(d);
        ++d;
    }
    if (n != 1) res.push_back(n);
    return res;
}

vector <int> t[MAXN];
int num[MAXN];
int ans[MAXN];

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; ++i) cin >> a[i];

    for (int i = 0; i < n; ++i) if (a[i]) t[i] = pr(abs(a[i]));

    set <vector <int> > ms;
    for (int i = 0; i < n; ++i) {
        if (a[i]) ms.insert(t[i]);
    }
    
    map <vector <int>, int> dc;
    int cnt = 0;
    for (vector <int> elem : ms) {
        dc[elem] = cnt;
        ++cnt;
    }

    for (int i = 0; i < n; ++i) if (a[i]) num[i] = dc[t[i]];

    for (int l = 0; l < n; ++l) {
        bitset <MAXN> ms1;
        bitset <MAXN> ms2;
        int curr = 0;
        for (int r = l; r < n; ++r) {
            if (a[r] != 0) {
                if (0 < a[r]) {
                    curr += (!ms1[num[r]]);
                    ms1[num[r]] = true;
                }
                else {
                    curr += (!ms2[num[r]]);
                    ms2[num[r]] = true;
                }
            }
            ++ans[max(1, curr)];
        }
    }

    for (int i = 1; i <= n; ++i) cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}