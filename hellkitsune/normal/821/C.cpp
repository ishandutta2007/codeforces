#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
char s[10];
int x;
set<int> se;
vector<int> v;

int main() {
    scanf("%d", &n);
    int need = 1;
    int ans = 0;
    forn(i, 2 * n) {
        scanf("%s", s);
        if (s[0] == 'a') {
            scanf("%d", &x);
            v.pb(x);
        } else {
            if (v.empty()) {
                assert(se.erase(need) == 1);
            } else if (v.back() == need) {
                v.pop_back();
            } else {
                ++ans;
                for (int x : v) {
                    se.insert(x);
                }
                v.clear();
                assert(se.erase(need) == 1);
            }
            ++need;
        }
    }
    cout << ans << endl;
    return 0;
}