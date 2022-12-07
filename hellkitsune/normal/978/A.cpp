#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[50];
vector<int> v;
set<int> se;

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    for (int i = n - 1; i >= 0; --i) {
        if (!se.count(a[i])) {
            v.pb(a[i]);
            se.insert(a[i]);
        }
    }
    reverse(v.begin(), v.end());
    printf("%d\n", (int)v.size());
    for (int x : v) {
        printf("%d ", x);
    }
    puts("");
    return 0;
}