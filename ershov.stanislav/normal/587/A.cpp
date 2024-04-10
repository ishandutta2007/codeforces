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

const int N = 2e6 + 100;

int n;
int cnt[N];

int main()
{
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int b;
        scanf("%d", &b);
        cnt[b]++;
    }
    for (int r = 0, i = 0; i < N; i++) {
        cnt[i] += r;
        r = cnt[i] / 2;
        cnt[i] %= 2;
    }
    int ans = 0;
    for (int i = 0; i < N; i++) {
        if (cnt[i]) {
            ans++;
        }
    }
    printf("%d\n", ans);
    return 0;
}