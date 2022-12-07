#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
char s[55];

int main() {
    scanf("%d", &n);
    int ans = 0;
    forn(i, n) {
        scanf("%s", s);
        if (s[0] == 'T') ans += 4;
        else if (s[0] == 'C') ans += 6;
        else if (s[0] == 'O') ans += 8;
        else if (s[0] == 'D') ans += 12;
        else ans += 20;
    }
    cout << ans << endl;
    return 0;
}