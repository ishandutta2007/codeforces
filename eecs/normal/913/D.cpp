#include <bits/stdc++.h>
using namespace std;

const int maxn = 200010;
int n, T, a[maxn], t[maxn];
vector<int> cur, ans;
vector<pair<int, int> > num;

bool chk(int x) {
    cur.clear(), num.clear();
    for (int i = 1; i <= n; i++) {
        if (a[i] >= x) num.push_back({t[i], i});
    }
    if (num.size() < x) return 0;
    sort(num.begin(), num.end());
    int s = 0;
    for (int i = 0; i < x; i++) {
        s += num[i].first, cur.push_back(num[i].second);
    }
    return s <= T;
}

int main() {
    scanf("%d %d", &n, &T);
    for (int i = 1; i <= n; i++) {
        scanf("%d %d", &a[i], &t[i]);
    }
    int l = 0, r = n;
    while (l <= r) {
        int mid = (l + r) >> 1;
        if (!chk(mid)) r = mid - 1;
        else ans = cur, l = mid + 1;
    }
    printf("%d\n%d\n", ans.size(), ans.size());
    for (int x : ans) printf("%d ", x);
    return 0;
}