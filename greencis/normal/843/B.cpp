#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n, start, x, ans = 2e9, out[50005], t[50005];
mt19937 gen(416);

inline void upd(int x, int delta) {
    if (x < 0)
        return;
    if (delta == -1) {
        if (out[x])
            return;
        out[x] = 1;
    }
    for (; x < 50005; x |= x + 1)
        t[x] += delta;
}

inline int get(int x) {
    int ans = 0;
    for (; x >= 0; x = (x & (x + 1)) - 1)
        ans += t[x];
    return ans;
}

int find(int idx) {
    int L = 0, R = n - 1;
    while (L < R) {
        int mid = (L + R) >> 1;
        int cur = get(mid);
        if (cur < idx + 1)
            L = mid + 1;
        else
            R = mid;
    }
    return L;
}

int main()
{
    ios_base::sync_with_stdio(false);

    cin >> n >> start >> x;
    for (int i = 0; i < n; ++i)
        upd(i, 1);

    int best_lower_val = -1, best_lower_next = -1;
    int have = 0;
    int curvalue, curnext;
    for (int iter = 0; iter < 1700 && (have = get(n - 1)); ++iter) {
        int rnd = uniform_int_distribution<>(0, have - 1)(gen);
        int curidx = find(rnd);
        cout << "? " << curidx + 1 << endl;
        cin >> curvalue >> curnext;
        upd(curidx, -1);
        upd(curnext - 1, -1);
        if (curvalue >= x) {
            ans = min(ans, curvalue);
        } else {
            if (curvalue > best_lower_val) {
                best_lower_val = curvalue;
                best_lower_next = curnext;
            }
        }
    }

    cout << "? " << start << endl;
    cin >> curvalue >> curnext;
    if (curvalue >= x)
        ans = min(ans, curvalue);
    else if (curvalue > best_lower_val)
        best_lower_next = curnext;

    curnext = best_lower_next;
    for (int i = 0; i < 298 && curnext != -1; ++i) {
        cout << "? " << curnext << endl;
        cin >> curvalue >> curnext;
        if (curvalue >= x)
            ans = min(ans, curvalue);
    }

    if (ans == (int)2e9)
        ans = -1;
    cout << "! " << ans << endl;

    return 0;
}