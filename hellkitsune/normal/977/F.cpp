#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[200005], d[200005], pre[200005];
map<int, int> ma;
vector<int> ans;

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    forn(i, n) {
        auto it = ma.find(a[i] - 1);
        if (it == ma.end()) {
            d[i] = 1;
            pre[i] = -1;
        } else {
            d[i] = d[it->second] + 1;
            pre[i] = it->second;
        }
        ma[a[i]] = i;
    }
    int best = 0;
    forn(i, n) if (d[i] > d[best]) {
        best = i;
    }
    for (int x = best; x != -1; x = pre[x]) {
        ans.pb(x);
    }
    reverse(ans.begin(), ans.end());
    printf("%d\n", (int)ans.size());
    for (int x : ans) printf("%d ", x + 1);
    puts("");
    return 0;
}