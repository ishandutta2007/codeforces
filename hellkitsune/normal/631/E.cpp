#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, LL> P;

int n;
int a[200000];
LL sum[200001];
vector<P> p;

bool earlier(LL a1, LL b1, LL a2, LL b2, LL a3, LL b3) {
    return (b1 - b3) * (a2 - a1) <= (b1 - b2) * (a3 - a1);
}

int main() {
    //freopen("input.txt", "r", stdin);
    scanf("%d", &n);
    REP(i, n) scanf("%d", a + i);
    LL score = 0, ans;
    REP(i, n) score += (LL)(i + 1) * a[i];
    ans = score;
    REP(times, 2) {
        sum[0] = a[0];
        for (int i = 1; i < n; ++i) {
            sum[i] = sum[i - 1] + a[i];
        }
        //y = r * a[l] - sum[r]
        p.clear();
        int sz = 0;
        REP(i, n) {
            while (sz > 1 && earlier(p[sz - 2].first, p[sz - 2].second, p.back().first, p.back().second, i, -sum[i])) {
                p.pop_back();
                --sz;
            }
            p.pb(mp(i, -sum[i]));
            ++sz;
        }
        //for (auto x : p) cout << x.first << ' ' << x.second << endl;
        REP(i, n) {
            int lo = 0, hi = (int)p.size() - 1, mid;
            while (lo < hi) {
                mid = (lo + hi) >> 1;
                if ((LL)p[mid].first * a[i] + p[mid].second < (LL)p[mid + 1].first * a[i] + p[mid + 1].second) {
                    lo = mid + 1;
                } else {
                    hi = mid;
                }
            }
            ans = max(ans, score + LL(p[lo].first - i) * a[i] + p[lo].second + sum[i]);
        }
        reverse(a, a + n);
        REP(i, n) a[i] = 1000005 - a[i];
    }
    cout << ans << endl;
    return 0;
}