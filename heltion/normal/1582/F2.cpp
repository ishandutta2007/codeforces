#pragma GCC Optmize("Ofast")
#pragma GCC target("avx2")
#include <bits/stdc++.h>
using namespace std;
using LL = long long;
using ULL = unsigned long long;
ULL BIT[5001][128];
ULL mask[6] = {};
ULL cur[128], ans[128];
int main() {
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    for (int i = 1; i <= 5000; i += i & -i) BIT[i][0] = 1ULL;
    for (int i = 0; i < 6; i += 1)
        for (int j = 0; j < 64; j += (2 << i)) 
            mask[i] |= ((1ULL << (1 << i)) - 1) << j;
    ans[0] = 1ULL;
    int c = 1;
    set<int> s;
    for (int i = 0, a; i < n; i += 1) {
        cin >> a;
        if (not a) continue;
        if (s.count(a)) continue;
        fill(cur, cur + 128, 0ULL);
        for (int j = a; j; j -= j & -j) for (int k = 0; k < 128; k += 1) cur[k] |= BIT[j][k];
        for (int i = 0; i < 6; i += 1) if ((a >> i) & 1)
            for (int k = 0; k < 128; k += 1) if (cur[k])
                cur[k] = ((cur[k] & mask[i]) << (1 << i)) | ((cur[k] >> (1 << i)) & mask[i]);
        for (int i = 0; i < 7; i += 1) if ((a >> (6 + i)) & 1)
            for (int k = 0; k < 128; k += 1) if (k & (1 << i)) swap(cur[k], cur[k ^ (1 << i)]);
        for (int j = a; j <= 5000; j += j & -j) for (int k = 0; k < 128; k += 1) BIT[j][k] |= cur[k];
        int oc = c;
        c = 0;
        for (int k = 0; k < 128; k += 1) {
            ans[k] |= cur[k];
            c += __builtin_popcountll(ans[k]);
        }
        if (c == 8192) break;
        if (c == oc) s.insert(a);
        else s.clear();
    }
    int m = 0;
    for (int i = 0; i < 8192; i += 1) m += (ans[i >> 6] >> (i & 63)) & 1;
    cout << m << "\n";
    for (int i = 0; i < 8192; i += 1) if ((ans[i >> 6] >> (i & 63)) & 1) cout << i << " ";
    return 0;
}