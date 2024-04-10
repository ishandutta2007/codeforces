#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long long ll;
typedef long double ld;

int n,x,a,b,ans;
set<int> s;

int main()
{
    scanf("%d",&n);
    for (int i = 0; i < n; ++i) {
        scanf("%d", &x);
        s.insert(x);
    }
    scanf("%d%d",&a,&b);

    for (; ; ++ans) {
        if (a == b) break;
        int mx = 1;
        for (set<int>::iterator it = s.begin(); it != s.end(); ) {
            if (a % (*it) <= a - b) mx = max(mx, a % (*it));
            if (a - a % (*it) < b) {
                set<int>::iterator it2 = it; ++it2;
                if (it2 == s.end()) {
                    s.erase(it);
                    break;
                } else {
                    int curnum = *it2;
                    s.erase(it);
                    it = s.find(curnum);
                    continue;
                }
            }
            ++it;
        }
        a -= mx;
    }
    printf("%d",ans);

    return 0;
}