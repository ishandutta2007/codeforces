#include <bits/stdc++.h>
using namespace std;

const int maxn = 100010, P = 1000000007;
int n, ans, a[maxn], pre[maxn], nxt[maxn], rmn[maxn], rmx[maxn];
int s1[maxn], s2[maxn], s3[maxn], s4[maxn];
map<int, int> mp;

int main() {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", &a[i]);
        pre[i] = mp[a[i]], mp[a[i]] = i;
    }
    mp.clear();
    for (int i = n; i; i--) {
        nxt[i] = mp.count(a[i]) ? mp[a[i]] : n + 1, mp[a[i]] = i;
    }
    function<void(int, int)> solve = [&](int l, int r) {
        if (l == r) {
            ans = (ans + 1LL * (l - pre[l] - 1) * (nxt[l] - l - 1)) % P; return;
        }
        int mid = (l + r) >> 1;
        solve(l, mid), solve(mid + 1, r);
        int mx = rmx[mid] = 0, mn = rmn[mid] = n + 1;
        s1[mid] = s2[mid] = s3[mid] = s4[mid] = 0;
        for (int i = mid + 1; i <= r; i++) {
            rmx[i] = max(rmx[i - 1], pre[i]);
            rmn[i] = min(rmn[i - 1], nxt[i]);
            s1[i] = (s1[i - 1] + rmx[i]) % P;
            s2[i] = (s2[i - 1] + 1LL * rmx[i] * (i + 1)) % P;
            s3[i] = (s3[i - 1] + max(0, rmn[i] - i - 1)) % P;
            s4[i] = (s4[i - 1] + 1LL * (P - rmx[i]) * max(0, rmn[i] - i - 1)) % P;
        }
        for (int i = mid, j = mid, k = mid, p = r; i >= l; i--) {
            mx = max(mx, pre[i]), mn = min(mn, nxt[i]);
            for (; j < r && pre[j + 1] <= mx; j++);
            for (; k < r && nxt[k + 1] >= mn; k++);
            for (; p > mid && (max(mx, rmx[p]) >= i || min(mn, rmn[p]) <= p); p--);
            if (p == mid) break;
            auto S1 = [&](int r) {
                if (r <= mid) return;
                int t = 1LL * (mn + mn - r - mid - 3) * (r - mid) / 2 % P;
                ans = (ans + 1LL * (i - 1 - mx) * t) % P;
            };
            auto S2 = [&](int l, int r) {
                if (l > r) return;
                if (j <= k) {
                    int t = 1LL * (l + r + 2) * (r - l + 1) / 2 % P;
                    ans = (ans + 1LL * (P - i + 1) * t) % P;
                    ans = (ans + 1LL * (i - 1) * mn % P * (r - l + 1)) % P;
                    ans = (ans + 1LL * (P - mn) * (s1[r] - s1[l - 1] + P)) % P;
                    ans = (1LL * ans + s2[r] - s2[l - 1] + P) % P;
                } else {
                    ans = (ans + 1LL * (i - 1 - mx) * (s3[r] - s3[l - 1] + P)) % P;
                }
            };
            auto S3 = [&](int l, int r) {
                if (l > r) return;
                ans = (ans + 1LL * (i - 1) * (s3[r] - s3[l - 1] + P)) % P;
                ans = (1LL * ans + s4[r] - s4[l - 1] + P) % P;
            };
            S1(min({j, k, p}));
            S2(min(j, k) + 1, min(max(j, k), p));
            S3(max(j, k) + 1, min(r, p));
        }
    };
    solve(1, n), printf("%d\n", ans);
    return 0;
}