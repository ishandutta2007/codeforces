#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
char s[5005];
vector<int> pos;
int ans = 0;
int cnt[26];

int main() {
    scanf("%s", s);
    n = strlen(s);
    for (char c = 'a'; c <= 'z'; ++c) {
        pos.clear();
        forn(i, n) if (s[i] == c) {
            pos.pb(i);
        }
        if (pos.empty()) {
            continue;
        }
        int mx = 0;
        forn(i, n) {
            forn(j, 26) cnt[j] = 0;
            for (int x : pos) {
                ++cnt[s[x] - 'a'];
            }
            int cur = 0;
            forn(j, 26) cur += cnt[j] == 1;
            mx = max(mx, cur);
            for (int &x : pos) if (++x == n) {
                x = 0;
            }
        }
        ans += mx;
    }
    printf("%.15f\n", (double)ans / n);
    return 0;
}