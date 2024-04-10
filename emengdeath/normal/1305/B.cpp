#include <algorithm>
#include <cstdio>
#include <cstring>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <cmath>
#include <iostream>
using namespace std;
int n;
char s[10000];
bool bz[1100];
vector<int>ans;
vector<int>d;
int l[1100], r[1100];
int main() {
    scanf("%s", s +1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; i ++)
        if (s[i] == '(')
            d.push_back(0);
        else
            d.push_back(1);
    vector<vector<int> > ans;
    while (d.size()) {
        memset(l,0, sizeof(l));
        memset(r,0, sizeof(r));
        memset(bz, 0,sizeof(bz));
        for (int i = 0; i < d.size(); i ++)
            l[i + 1] = l[i] + (d[i] == 0);
        for (int i = d.size() - 1; i >= 0; i --)
            r[i + 1] = r[i + 2] + (d[i] == 1);
        int mx = 0;
        for (int i = 1; i <= d.size(); i ++)
            if (l[i] == r[i + 1])
                mx = max(l[i], mx);
        if (!mx) break;
        int sum = 0;
        vector<int>w;
        for (int i = 0;i < d.size() && sum < mx; i ++)
            if (!d[i])
                w.push_back(i + 1), sum ++, bz[i] = 1;
        sum = 0;
        for (int i = d.size()- 1; i >= 0 && sum < mx; i--)
            if (d[i])
                w.push_back(i + 1), sum ++, bz[i] = 1;
        sort(w.begin(), w.end());
        vector<int>dd;
        for (int i = 0; i < d.size(); i ++)
            if (!bz[i])
                dd.push_back(d[i]);
        d = dd;
        ans.push_back(w);
    }
    printf("%d\n", ans.size());
    for (auto u:ans) {
        printf("%d\n", u.size());
        for (auto v:u)
            printf("%d ", v);
        printf("\n");
    }
    return 0;
}