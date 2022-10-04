#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define int long long

const int N = 5e5 + 7;

int cnt[N];
int nd[N];
int hv[N];
                                                         
signed main() {
    ios_base::sync_with_stdio(false); cin.tie(0); cout.setf(ios::fixed); cout.precision(20);
    #ifdef LOCAL
    freopen("input.txt", "r", stdin);
    #endif
    int m, k, n, s;
    cin >> m >> k >> n >> s;
    vector <int> a(m);
    for (int i = 0; i < m; ++i) cin >> a[i];
    vector <int> b(s);
    for (int i = 0; i < s; ++i) {
        cin >> b[i];
        ++nd[b[i]];
    }
    set <int> w;
    for (int i = 0; i < N; ++i){
        if (nd[i] > 0) w.insert(i);
    }
    int l = 0;
    for (int r = 0; r < m; ++r) {
        int x = a[r];
        ++hv[x];
        if (hv[x] >= nd[x]) w.erase(x);
        while (r - l + 1 > k && hv[a[l]] > nd[a[l]]) {
            --hv[a[l]];
            ++l;
        }
        if (!w.empty()) continue;
        int cl = (m - r - 1) / k;
        int cr = l / k + 1;
        if (cl + cr >= n) {
            //cout << l << ' ' << r << endl;
            vector <int> who;
            int lst = (l / k) * k;
            for (int i = lst; i < l; ++i) who.push_back(i);
            int sz = r - l + 1;
            for (int i = l; i <= r; ++i) {
                if (sz > k && hv[a[i]] > nd[a[i]]) {
                    who.push_back(i);
                    --hv[a[i]];
                    --sz;
                }
            }
            cout << (int)who.size() << '\n';
            for (auto x : who) {
                cout << x + 1 << ' ';
            } 
            return 0;
        }
    }
    cout << "-1\n";
}