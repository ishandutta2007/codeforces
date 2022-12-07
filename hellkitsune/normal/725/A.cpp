#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
char s[200005];

int main() {
    scanf("%d%s", &n, s);
    int ans = 0;
    forn(i, n) {
        if (s[i] == '>') {
            break;
        }
        ++ans;
    }
    for (int i = n - 1; i >= 0; --i) {
        if (s[i] == '<') {
            break;
        }
        ++ans;
    }
    cout << ans << endl;
    return 0;
}