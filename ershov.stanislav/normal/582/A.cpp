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

int n;
map<int, int> cnt;
map<int, int> cnt2;
map<int, int> cnt3;
set<int> s;

int main()
{
#ifdef DEBUG
    freopen("text.in", "r", stdin);
#endif
    scanf("%d", &n);
    for (int i = 0; i < n * n; i++) {
        int a;
        scanf("%d", &a);
        cnt[a]++;
    }
    for (auto i : cnt) {
        for (int j = 1; j * j <= i.fs; j++) {
            if (i.fs % j == 0) {
                cnt2[j] += i.sc;
                if (j * j != i.fs) {
                    cnt2[i.fs / j] += i.sc;
                }
            }
        }
    }
    for (auto i : cnt2) {
        cnt3[i.fs] = sqrt(i.sc);
        s.insert(i.fs);
    }
    int all = 0;
    for (; all < n; ) {
        int cur = *s.rbegin();
        s.erase(cur);
        if (cnt3[cur] == 0) {
            continue;
        } else {
            int c = cnt3[cur];
            for (int j = 0; j < c; j++) {
                printf("%d ", cur);
                all++;
            }
            for (int j = 1; j * j <= cur; j++) {
                if (cur % j == 0) {
                    cnt3[j] -= c;
                    if (j * j != cur) {
                        cnt3[cur / j] -= c;
                    }
                }
            }
        }
    }
    return 0;
}