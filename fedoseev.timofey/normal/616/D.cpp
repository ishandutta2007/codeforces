#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int Maxn = 1e6 + 7;
int cnt[Maxn];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector <int> val(n);
    for (int i = 0; i < n; ++i) cin >> val[i];
    int l = 0;
    int bl, br, ans = 0, diff = 0;
    for (int r = 0; r < n; ++r) {
        if (++cnt[val[r]] == 1) ++diff;
        while (diff > k) {
            if (--cnt[val[l]] == 0) --diff;
            ++l;
        }
        if (r - l + 1 > ans) {
            br = r;
            bl = l;
            ans = r - l + 1;
        }
    }
    cout << bl + 1 << " " << br + 1 << endl;
}