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

#define sz(s) int((s).size())
#define len(s) int((s).size())
#define all(s) (s).begin(), (s).end()

typedef long long ll;
typedef long double ld;

const int INF = 1e9;
const ll lINF = 1e18;
const double EPS = 1e-12;

using namespace std;

const int N = 200200;

int n, a[N];
vector<int> cnt[N];
vector<int> ans;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        cnt[a[i]].pb(i + 1);
    }
    int cur = -1;
    bool flag = true;
    for (int i = 0; i < n; i++) {
        cur++;
        while (cur >= 0 && cnt[cur].size() == 0) {
            cur -= 3;
        }
        if (cur < 0) {
            flag = false;
        } else {
            ans.pb(cnt[cur].back());
            cnt[cur].pop_back();
        }
    }
    if (flag) {
        printf("Possible\n");
        for (int i = 0; i < n; i++) {
            printf("%d ", ans[i]);
        }
    } else {
        printf("Impossible");
    }
    return 0;
}