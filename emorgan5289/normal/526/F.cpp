#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

const int N = 3e5+5, S = 800;
int a[N];
int v[N];
int f[N/S+1][2*S+1];
int offset[N/S+1];

void reset_offset(int i) {
    fill(f[i], f[i]+(2*S+1), 0);
    for (int j = S*i; j < S*(i+1); j++) {
        v[j] += offset[i];
        if (abs(v[j]) <= S) f[i][S+v[j]]++;
    }
    offset[i] = 0;
}

void add_on_range(int l, int r, int x) {
    // debug(l, r, x);
    int ls = l/S, rs = r/S;

    if (ls == rs) {
        for (; r >= l; r--) {
            if (abs(v[r]) <= S) f[rs][S+v[r]]--;
            v[r] += x;
            if (abs(v[r]) <= S) f[rs][S+v[r]]++;
        }
        return;
    }

    for (; r >= 0 && r%S != S-1; r--) {
        if (abs(v[r]) <= S) f[rs][S+v[r]]--;
        v[r] += x;
        if (abs(v[r]) <= S) f[rs][S+v[r]]++;
    }
    for (; l%S != 0; l++) {
        if (abs(v[l]) <= S) f[ls][S+v[l]]--;
        v[l] += x;
        if (abs(v[l]) <= S) f[ls][S+v[l]]++;
    }
    if (l < r)
        for (int i = l/S; i <= r/S; i++) {
            offset[i] += x;
            if (abs(offset[i]) > S)
                reset_offset(i);
        }
}

int count_zero(int r) {
    // debug(r);
    int ans = 0;
    for (; r >= 0 && r%S != S-1; r--)
        ans += v[r]+offset[r/S] == 0;
    for (int i = 0; S*i < r; i++)
        ans += f[i][S-offset[i]];
    return ans;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        a[x-1] = y-1;
    }
    // debug(vector(a, a+n));
    for (int i = 0; i < N; i++)
        f[i/S][S]++;

    vector<int> min_stk, max_stk;
    ll ans = 0;
    for (int i = 0; i < n; i++) {
        map<int, int> upd;

        // max_stk
        int x = 0;
        while (!max_stk.empty() && a[i] > a[max_stk.back()]) {
            int y = a[max_stk.back()];
            upd[max_stk.back()+1] += y-x;
            upd[i] += x-y;
            max_stk.pop_back();
            x = y;
        }
        upd[max_stk.empty() ? 0 : max_stk.back()+1] += a[i]-x;
        upd[i] += x-a[i];
        max_stk.push_back(i);

        // min_stk
        x = n-1;
        while (!min_stk.empty() && a[i] < a[min_stk.back()]) {
            int y = a[min_stk.back()];
            upd[min_stk.back()+1] += x-y;
            upd[i] += y-x;
            min_stk.pop_back();
            x = y;
        }
        upd[min_stk.empty() ? 0 : min_stk.back()+1] += x-a[i];
        upd[i] += a[i]-x;
        min_stk.push_back(i);

        // subtract 1 from previous guys
        upd[0]--, upd[i]++;

        ll py = -1, s = 0;
        for (auto& [y, ds] : upd) {
            if (ds == 0) continue;
            if (s != 0) add_on_range(py, y-1, s);
            py = y, s += ds;
        }

        // debug(count_zero(i));
        ans += count_zero(i);

        if (i%1000 == 0) debug(i);
    }
    cout << ans << "\n";

    // for (int i = 0; i < N; i++) {
    //     int x = rand(), y = rand();
    //     if (x > y) swap(x, y);
    //     add_on_range(x, y, 1);
    //     count_zero(i);
    //     if (i%1000 == 0) debug(i);
    // }
    // cout << "done";
}

// 0 0 0 0 0
// 2 0 0 0 0
// 1 1 0 0 0
// 0 0 0 0 0
// 0 0 1 1 0