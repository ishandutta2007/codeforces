#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define y0 yy0
#define y1 yy1
#define next _next
#define prev _prev
#define link _link
#define hash _hash

#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-10;

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 5e5 + 100;

struct sum {
    int cnt[26];
    sum() {
        for (int i = 0; i < 26; i++) {
            cnt[i] = 0;
        }
    }
    sum(char c) {
        for (int i = 0; i < 26; i++) {
            cnt[i] = 0;
        }
        cnt[c - 'a'] = 1;
    }
};

int n, m, cur_t, t_in[N], t_out[N];
int p[N];
vector<int> tree[N];
char s[N];
vector<vector<int> > v;
vector<vector<sum> > dp;

void dfs(int vv, int depth) {
    t_in[vv] = cur_t++;
    while ((int) v.size() <= depth) {
        v.pb(vector<int>());
        dp.pb(vector<sum>());
    }
    v[depth].pb(cur_t - 1);
    dp[depth].pb(sum(s[vv]));
    for (auto i : tree[vv]) {
        dfs(i, depth + 1);
    }
    t_out[vv] = cur_t;
}

int main()
{
#ifdef DEBUG
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &m);
    for (int i = 2; i <= n; i++) {
        scanf("%d", &p[i]);
        tree[p[i]].pb(i);
    }
    scanf(" %s", s + 1);
    dfs(1, 1);
    for (auto & r : dp) {
        for (int i = 1; i < (int) r.size(); i++) {
            for (int j = 0; j < 26; j++) {
                r[i].cnt[j] += r[i - 1].cnt[j];
            }
        }
    }
    for (int i = 0; i < m; i++) {
        int vv, h;
        scanf("%d%d", &vv, &h);
        if (h >= (int) v.size()) {
            printf("Yes\n");
            continue;
        }
        int l = (int) (lower_bound(all(v[h]), t_in[vv]) - v[h].begin());
        int r = (int) (lower_bound(all(v[h]), t_out[vv]) - v[h].begin());
        sum sm;
        for (int j = 0; j < 26; j++) {
            if (r > 0) sm.cnt[j] = dp[h][r - 1].cnt[j];
            if (l > 0) sm.cnt[j] -= dp[h][l - 1].cnt[j];
        }
        int cnt_bad = 0;
        for (int j = 0; j < 26; j++) {
            if (sm.cnt[j] & 1) {
                cnt_bad++;
            }
        }
        if (cnt_bad > 1) {
            printf("No\n");
        } else {
            printf("Yes\n");
        }
    }
    return 0;
}