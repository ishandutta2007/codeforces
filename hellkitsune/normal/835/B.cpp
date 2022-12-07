#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;
char s[100005];
int a[100005];

int main() {
    scanf("%d%s", &k, s);
    n = strlen(s);
    forn(i, n) a[i] = s[i] - '0';
    forn(i, n) k -= a[i];
    int ans = 0;
    forn(i, 9) forn(j, n) {
        if (a[j] == i && k > 0) {
            k -= 9 - a[j];
            a[j] = 9;
            ++ans;
        }
    }
    assert(k <= 0);
    cout << ans << endl;
    return 0;
}