#include <bits/stdc++.h>

#define mp make_pair
#define pb push_back
#define eb emplace_back

#define all(s) (s).begin(), (s).end()
#define sz(s) ((int) ((s).size()))

#define fs first
#define sc second

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

const int maxn = 1e5 + 100;
int n, m;

map<int, int> cnt;
int bad = 0;
int a[maxn];
int b[maxn];

int main () {
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d", &n);
    int mx = 0;
    for (int i = 0; i < n; i++) {
        scanf("%d", a + i);
        b[i] = a[i];
    }
    sort(b, b + n);
    for (int i = 0; i < n; i++) {
        if (cnt[a[i]] == 0) {
            bad++;
        }
        if (cnt[a[i]] == -1) {
            bad--;
        }
        cnt[a[i]]++;
        if (cnt[b[i]] == 0) {
            bad++;
        }
        if (cnt[b[i]] == 1) {
            bad--;
        }
        cnt[b[i]]--;
        if (bad == 0) {
            mx++;
        }
    }
    cout << mx << endl;
    return 0;
}