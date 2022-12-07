#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
char s[10];
int mul[10];
vector<int> ans;

int main() {
    scanf("%d", &n);
    int pre = 0;
    forn(_, n) {
        scanf("%s", s);
        int len = strlen(s);
        mul[len - 1] = 1;
        for (int i = len - 2; i >= 0; --i) {
            mul[i] = mul[i + 1] * 10;
        }
        int cur = 0;
        forn(i, len) {
            cur += mul[i] * (s[i] == '?' ? 9 : (s[i] - '0'));
        }
        if (cur <= pre) {
            cout << "NO" << endl;
            return 0;
        }
        forn(i, len) if (s[i] == '?') {
            int times = (i == 0 ? 8 : 9);
            forn(__, times) {
                if (cur - mul[i] > pre) {
                    cur -= mul[i];
                }
            }
        }
        ans.pb(cur);
        pre = cur;
    }
    puts("YES");
    for (int x : ans) printf("%d\n", x);
    puts("");
    return 0;
}