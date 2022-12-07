#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
char buf[1000005];
vector<string> s;
vector<int> v[2000005];
string ans;

int main() {
    scanf("%d", &n);
    int len = 0;
    forn(i, n) {
        scanf("%s", buf);
        s.pb(string(buf));
        int cnt;
        scanf("%d", &cnt);
        forn(j, cnt) {
            int pos;
            scanf("%d", &pos), --pos;
            v[pos].pb(i);
            len = max(len, pos + (int)s[i].size());
        }
    }
    ans = string(len, 'a');
    int rem = 0;
    int ind = -1, pos = -1;
    forn(i, len) {
        for (int x : v[i]) {
            if ((int)s[x].length() > rem) {
                rem = (int)s[x].length();
                ind = x;
                pos = 0;
            }
        }
        if (rem > 0) {
            ans[i] = s[ind][pos];
            ++pos;
            --rem;
        }
    }
    printf("%s\n", ans.c_str());
    return 0;
}