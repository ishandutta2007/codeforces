#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, l[1005], r[1005], ans[1005], u[1005];

struct entry {
    int l, r, i;
};
vector<entry> v;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> l[i];
    for (int i = 1; i <= n; ++i) {
        cin >> r[i];
        v.push_back(entry{l[i], r[i], i});
    }

    for (int iter = 1; iter <= n && v.size(); ++iter) {
        vector<int> pos;
        for (int j = 0; j < (int)v.size(); ++j) {
            if (v[j].l == 0 && v[j].r == 0)
                pos.push_back(j), u[j] = iter;
        }
        if (pos.empty()) {
            cout << "NO" << endl;
            return 0;
        }
        for (int j = 0; j < (int)pos.size(); ++j) {
            int idx = pos[j];
            for (int z = idx - 1; z >= 0; --z) {
                if (!v[z].r-- && u[z] != iter) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
            for (int z = idx + 1; z < (int)v.size(); ++z) {
                if (!v[z].l-- && u[z] != iter) {
                    cout << "NO" << endl;
                    return 0;
                }
            }
            ans[v[idx].i] = n + 1 - iter;
        }
        while (pos.size()) {
            v.erase(v.begin() + pos.back());
            pos.pop_back();
        }
    }

    cout << "YES\n";
    for (int i = 1; i <= n; ++i)
        cout << (i == 1 ? "" : " ") << ans[i];
    cout << endl;
}