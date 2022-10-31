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

const int N = 5e5 + 100;
int a[N], n;
bool fix[N];

int main()
{
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
    }
    fix[0] = fix[n - 1] = 1;
    for (int i = 1; i < n - 1; i++) {
        if (a[i - 1] == a[i] || a[i + 1] == a[i]) {
            fix[i] = 1;
        }
    }
    int ans = 0;
    for (int i = 1, prev = 0; i < n; i++) {
        if (fix[i]) {
            if (prev < i - 1) {
                if (a[prev] == 0 && a[i] == 0) {
                    ans = max(ans, (i - prev) / 2);
                    for (int j = prev + 1; j < i; j++) {
                        a[j] = 0;
                    }
                }
                if (a[prev] == 1 && a[i] == 1) {
                    ans = max(ans, (i - prev) / 2);
                    for (int j = prev + 1; j < i; j++) {
                        a[j] = 1;
                    }
                }
                if (a[prev] == 0 && a[i] == 1) {
                    ans = max(ans, (i - prev) / 2);
                    int cnt = (i - prev) / 2;
                    for (int j = prev + 1; j < prev + cnt + 1; j++) {
                        a[j] = 0;
                    }
                    for (int j = prev + cnt + 1; j < i; j++) {
                        a[j] = 1;
                    }
                }
                if (a[prev] == 1 && a[i] == 0) {
                    ans = max(ans, (i - prev) / 2);
                    int cnt = (i - prev) / 2;
                    for (int j = prev + 1; j < prev + cnt + 1; j++) {
                        a[j] = 1;
                    }
                    for (int j = prev + cnt + 1; j < i; j++) {
                        a[j] = 0;
                    }
                }
            }
            prev = i;
        }
    }
    printf("%d\n", ans);
    for (int i = 0; i < n; i++) {
        printf("%d%c", a[i], " \n"[i == n - 1]);
    }
    return 0;
}