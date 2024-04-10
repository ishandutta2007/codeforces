#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long double ld;
typedef long long ll;

int n,q,x,y,z,cnt[26];
char a[100008],ans[100008];
set< pii > s[26];

int main()
{
    scanf("%d%d%s",&n,&q,a);
    char curc = a[0];
    int curci = 0;
    for (int i = 1; i <= n; ++i) {
        if (a[i] != curc) {
            s[curc - 97].insert(make_pair(i-1, curci));
            curc = a[i];
            curci = i;
        }
    }

    while (q--) {
        scanf("%d%d%d",&x,&y,&z);
        --x; --y;
        for (int i = 0; i < 26; ++i) {
            cnt[i] = 0;
            for (set< pii >::iterator it = s[i].lower_bound(make_pair(x,0)); it != s[i].end(); ) {
                int curl = it->second, curr = it->first;
                if (curl > y) break;
                if (curl >= x && curr <= y) {
                    cnt[i] += curr - curl + 1;
                    ++it;
                    if (it == s[i].end()) {
                        --it;
                        s[i].erase(it);
                        break;
                    } else {
                        pii qqq = *it;
                        --it;
                        s[i].erase(it);
                        it = s[i].find(qqq);
                    }
                } else {
                    cnt[i] += min(curr, y) - max(curl, x) + 1;
                    s[i].erase(make_pair(curr, curl));
                    if (curr > y && curl < x) {
                        s[i].insert(make_pair(x - 1, curl));
                        s[i].insert(make_pair(curr, y + 1));
                        it = s[i].find(make_pair(curr, y + 1));
                    } else if (curl < x) {
                        s[i].insert(make_pair(x - 1, curl));
                        it = s[i].find(make_pair(x - 1, curl));
                        ++it;
                    } else {
                        s[i].insert(make_pair(curr, y + 1));
                        break;
                    }
                }
            }
        }

        if (z) {
            for (int i = 0; i < 26; ++i) {
                if (cnt[i]) {
                    s[i].insert(make_pair(x + cnt[i] - 1, x));
                    x += cnt[i];
                }
            }
        } else {
            for (int i = 25; i >= 0; --i) {
                if (cnt[i]) {
                    s[i].insert(make_pair(x + cnt[i] - 1, x));
                    x += cnt[i];
                }
            }
        }
    }

    for (int i = 0; i < 26; ++i) {
        for (set< pii >::iterator it = s[i].begin(); it != s[i].end(); ++it) {
            for (int j = it->second; j <= it->first; ++j)
                ans[j] = 'a' + i;
        }
    }
    puts(ans);

    return 0;
}