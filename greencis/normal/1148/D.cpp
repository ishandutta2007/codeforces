#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

struct entry {
    int a, b, idx;
    inline bool operator<(const entry& rhs) const {
        return b > rhs.b;
    }
} e[300105];

int n;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> e[i].a >> e[i].b;
        e[i].idx = i + 1;
    }
    vector<int> ans;
    for (int zzz = 0; zzz < 2; ++zzz) {
        sort(e, e + n);
        vector<int> curans;
        int prv = 1e9;
        for (int i = 0; i < n; ++i) {
            if (e[i].a > e[i].b) continue;
            if (e[i].a < prv) {
                prv = e[i].b;
                curans.push_back(e[i].idx);
            }
        }
        if (zzz == 1)
            reverse(curans.begin(), curans.end());
        if (curans.size() > ans.size())
            ans = curans;
        for (int i = 0; i < n; ++i)
            swap(e[i].a, e[i].b);
    }
    cout << ans.size() << endl;
    for (int x : ans)
        cout << x << " ";
}