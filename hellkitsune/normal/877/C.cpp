#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
vector<int> ans;

int main() {
    scanf("%d", &n);
    for (int i = 2; i <= n; i += 2) {
        ans.pb(i);
    }
    for (int i = 1; i <= n; i += 2) {
        ans.pb(i);
    }
    for (int i = 2; i <= n; i += 2) {
        ans.pb(i);
    }
    printf("%d\n", (int)ans.size());
    for (int x : ans) printf("%d ", x);
    puts("");
    return 0;
}