#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int cnt[10] = {};
char s[100005];
int n;

int main() {
    scanf("%s", s);
    n = strlen(s);
    forn(i, n) {
        char c = s[i];
        if (c == 'B') {
            ++cnt[0];
        } else if (c == 'u') {
            ++cnt[1];
        } else if (c == 'l') {
            ++cnt[2];
        } else if (c == 'b') {
            ++cnt[3];
        } else if (c == 'a') {
            ++cnt[4];
        } else if (c == 's') {
            ++cnt[5];
        } else if (c == 'r') {
            ++cnt[6];
        }
    }
    int ans = min(cnt[0], cnt[1] / 2);
    ans = min(ans, min(cnt[2], cnt[3]));
    ans = min(ans, min(cnt[4] / 2, cnt[5]));
    ans = min(ans, cnt[6]);
    cout << ans << endl;
    return 0;
}