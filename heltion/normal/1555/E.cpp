#include <bits/stdc++.h>
using namespace std;
using LL = long long;
#define ls (v << 1)
#define rs (ls | 1)
#define tm ((tl + tr) >> 1)
constexpr int maxn = 1000000;
int added[maxn << 2], minn[maxn << 2];
void add(int v, int add) {
    added[v] += add;
    minn[v] += add;
}
void push_down(int v) {
    add(ls, added[v]);
    add(rs, added[v]);
    added[v] = 0;
}
void add(int v, int tl, int tr, int L, int R, int x) {
    if (tl >= L and tr <= R) add(v, x);
    else {
        push_down(v);
        if (L <= tm) add(ls, tl, tm, L, R, x);
        if (R > tm) add(rs, tm + 1, tr, L, R, x);
        minn[v] = min(minn[ls], minn[rs]);
    }
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> s(n);
    for (int i = 0; i < n; i += 1) {
        s[i].resize(3);
        cin >> s[i][1] >> s[i][2] >> s[i][0];
    }
    sort(s.begin(), s.end());
    int ans = INT_MAX;
    for (int i = 0, j = 0; i < n; i += 1) {
        while(j < n and minn[1] == 0) {
            add(1, 1, m - 1, s[j][1], s[j][2] - 1, 1);
            j += 1;
        }
        if (minn[1])
            ans = min(ans, s[j - 1][0] - s[i][0]);
        add(1, 1, m - 1, s[i][1], s[i][2] - 1, -1);
    }
    cout << ans;
    return 0;
}