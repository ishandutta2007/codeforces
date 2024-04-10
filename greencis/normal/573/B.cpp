#include <bits/stdc++.h>
#define pii pair<int,int>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef unsigned long long ull;

int n,a[500005],ans[500005];
set< pii > s;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < n; ++i) {
        ans[i] = min(a[i], min(i + 1, n - i));
        s.insert(make_pair(ans[i], i));
    }

    while (s.size()) {
        pii qqq = *(s.begin());
        int idx = qqq.second;
        int val = qqq.first;
        s.erase(s.begin());
        if (idx != 0) {
            if (val + 1 < ans[idx - 1]) {
                s.erase(s.find(make_pair(ans[idx-1], idx-1)));
                ans[idx-1] = val + 1;
                s.insert(make_pair(val + 1, idx - 1));
            }
        }
        if (idx != n-1) {
            if (val + 1 < ans[idx + 1]) {
                s.erase(s.find(make_pair(ans[idx+1], idx+1)));
                ans[idx+1] = val + 1;
                s.insert(make_pair(val + 1, idx + 1));
            }
        }
    }

    int res = 0;
    for (int i = 0; i < n; ++i) res = max(res, ans[i]);
    printf("%d", res);

    return 0;
}