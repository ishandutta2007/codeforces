#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
PII p[100000];
int a[100000];
bool used[100000];
vector<vector<int> > ans;
vector<int> cur;

int main() {
    scanf("%d", &n);
    forn(i, n) {
        scanf("%d", &p[i].first);
        p[i].second = i;
    }
    sort(p, p + n);
    forn(i, n) a[i] = p[i].second;
    forn(i, n) if (!used[i]) {
        cur.clear();
        for (int j = i; !used[j]; j = a[j]) {
            used[j] = true;
            cur.pb(j + 1);
        }
        ans.pb(cur);
    }
    printf("%d\n", (int)ans.size());
    for (auto &v : ans) {
        printf("%d", (int)v.size());
        for (int x : v) {
            printf(" %d", x);
        }
        puts("");
    }
    return 0;
}