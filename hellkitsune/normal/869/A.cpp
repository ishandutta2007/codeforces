#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[2000], b[2000];
bool have[10000005];

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    forn(i, n) scanf("%d", b + i);
    forn(i, n) have[a[i]] = true;
    forn(i, n) have[b[i]] = true;
    int ans = 0;
    forn(i, n) forn(j, n) {
        if (have[a[i] ^ b[j]]) ++ans;
    }
//    cerr << ans << endl;
    if (ans % 2 == 0) cout << "Karen" << endl;
    else cout << "Koyomi" << endl;
    return 0;
}