#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

char s[200005];

vector<int> ans[200005];
int n, cnt, need;
set<int> z, o;

int main() {
    scanf("%s", s);
    n = strlen(s);
    forn(i, n) if (s[i] == '1') {
        --need;
    } else {
        ++need;
    }
    if (need <= 0) {
        cout << -1 << endl;
        return 0;
    }
    forn(i, n) {
        int val = s[i] - '0';
        if (val == 0) {
            if (cnt < need) {
                ans[cnt].pb(i);
                z.insert(cnt);
                ++cnt;
            } else {
                if (o.empty()) {
                    cout << -1 << endl;
                    return 0;
                }
                int ind = *o.begin();
                o.erase(o.begin());
                ans[ind].pb(i);
                z.insert(ind);
            }
        } else {
            if (z.empty()) {
                cout << -1 << endl;
                return 0;
            }
            int ind = *z.begin();
            z.erase(z.begin());
            ans[ind].pb(i);
            o.insert(ind);
        }
    }
    if (need != cnt) {
        cout << -1 << endl;
        return 0;
    }
    printf("%d\n", need);
    forn(i, need) {
        printf("%d", (int)ans[i].size());
        for (int x : ans[i]) {
            printf(" %d", x + 1);
        }
        puts("");
    }
    return 0;
}