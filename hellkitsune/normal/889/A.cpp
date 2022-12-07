#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[200000];
set<int> se;

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    int ans = 0;
    forn(i, n) if (se.count(a[i])) {
        se.erase(a[i]);
        se.insert(i + 1);
    } else {
        ++ans;
        se.insert(i + 1);
    }
    cout << ans << endl;
    return 0;
}