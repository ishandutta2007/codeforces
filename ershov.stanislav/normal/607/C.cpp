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

const int INF = (int) 1e9 + 100;
const ll lINF = 1e18;
const double EPS = 1e-12;

#ifdef _WIN32
#define LLD "%I64d"
#else
#define LLD "%lld"
#endif

using namespace std;

const int maxn = 3e6 + 100;
int n;
char s1[maxn], s2[maxn], s[maxn];
int pr[maxn];

int main() {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d", &n);
    n--;
    scanf(" %s %s", s1, s2);
    int all = n * 2 + 1;
    s[n] = '#';
    for (int i = 0; i < n; i++) {
        s[i] = s1[i];
        if (s[i] == 'N') {
            s[i] = 'S';
        } else if (s[i] == 'S') {
            s[i] = 'N';
        } else if (s[i] == 'W') {
            s[i] = 'E';
        } else if (s[i] == 'E') {
            s[i] = 'W';
        }
        s[i + n + 1] = s2[i];
    }
    reverse(s, s + n);
    pr[0] = -1;
    for (int i = 1; i < all; i++) {
        pr[i + 1] = pr[i] + 1;
        while (pr[i + 1] > 0 && s[pr[i + 1] - 1] != s[i]) {
            pr[i + 1] = pr[pr[i + 1] - 1] + 1;
        }
    }
    if (pr[all]) {
        printf("NO\n");
    } else {
        printf("YES\n");
    }
    return 0;
}