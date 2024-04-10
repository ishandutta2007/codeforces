#include <bits/stdc++.h>

#define mp make_pair
#define fs first
#define sc second
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 4400;
int n;
ll v[N], d[N], p[N];
int used[N];

int main()
{
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf(LLD " " LLD "" LLD, v + i, d + i, p + i);
    }
    queue<int> q;
    vector<int> ans;
    for (int l = 0; l < n; l++) {
        if (used[l]) {
            continue;
        }
        ans.pb(l);
        int cnt = 0;
        for (int i = l + 1; i < n; i++) {
            if (used[i]) {
                continue;
            }
            p[i] -= max(0ll, v[l] - cnt);
            cnt++;
            if (!used[i] && p[i] < 0) {
                used[i] = true;
                q.push(i);
            }
        }
        while (sz(q)) {
            int cur = q.front();
            q.pop();
            for (int i = cur + 1; i < n; i++) {
                p[i] -= max(0ll, d[cur]);
                if (!used[i] && p[i] < 0) {
                    used[i] = true;
                    q.push(i);
                }
            }
        }
    }
    printf("%d\n", sz(ans));
    for (int i = 0; i < sz(ans); i++) {
        printf("%d%c", ans[i] + 1, " \n"[i == sz(ans) - 1]);
    }
    return 0;
}