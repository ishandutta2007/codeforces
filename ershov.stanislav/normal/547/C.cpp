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

#ifdef WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int N = 2e5 + 100;
const int M = 5e5 + 100;

int n, q, a[N], meb[M];
vector<int> del[M];
ll cnt[M];
bool taken[N];
ll sum = 0;

int main()
{
#ifdef DEBUG
    freopen ("in.txt", "r", stdin);
#endif
    scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) {
        scanf("%d", a + i);
    }
    meb[1] = 1;
    for (int i = 1; i < M; i++) {
        for (int j = i * 2; j < M; j += i) {
            meb[j] -= meb[i];
        }
    }
    for (int i = 1; i < M; i++) {
        for (int j = i; j < M; j += i) {
            del[j].pb(i);
        }
    }
    for (int i = 1; i <= q; i++) {
        int x;
        scanf("%d", &x);
        int r = 1;
        if (taken[x]) {
            r = -1;
        }

        for (auto j : del[a[x]]) {
            sum -= meb[j] * cnt[j] * (cnt[j] - 1) / 2;
            cnt[j] += r;
            sum += meb[j] * cnt[j] * (cnt[j] - 1) / 2;
        }

        if (taken[x]) {
            taken[x] = false;
        } else {
            taken[x] = true;
        }

        printf(LLD"\n", sum);
    }
    return 0;
}