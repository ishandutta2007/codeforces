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

const int MOD = 1e9 + 7;
const int N = 1e5 + 100;

int n;
int p1[N], p2[N], inp2[N];

int main()
{
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) {
        scanf("%d", p1 + i);
    }
    for (int i = 1; i <= n; i++) {
        scanf("%d", p2 + i);
    }
    for (int i = 1; i <= n; i++) {
        inp2[p2[i]] = i;
    }
    vector<pair<int, int> > v;
    vector<int> right;
    while (true) {
        right.clear();
        bool flag = false;
        for (int i = 1; i <= n; i++) {
            if (p1[i] != p2[i]) {
                flag = true;
            }
        }
        if (!flag) {
            break;
        }
        for (int i = 1; i <= n; i++) {
            if (inp2[p1[i]] < i) {
                int cur = i;
                while (inp2[p1[cur]] < cur) {
                    swap(p1[cur], p1[right.back()]);
                    v.eb(cur, right.back());
                    cur = right.back();
                    right.pop_back();
                }
                i = cur;
            } else if (inp2[p1[i]] > i) {
                right.pb(i);
            }
        }
    }
    int sum = 0;
    for (auto i : v) {
        sum += abs(i.fs - i.sc);
    }
    printf("%d\n%d\n", sum, sz(v));
    for (int i = 0; i < sz(v); i++) {
        printf("%d %d\n", v[i].fs, v[i].sc);
    }
    return 0;
}