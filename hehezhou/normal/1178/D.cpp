#include <bits/stdc++.h>
using namespace std;
int isp[2010];
int main() {
    int n;
    scanf("%d", &n);
    isp[1] = 0;
    for(int i = 2; i <= 2 * n; i++) isp[i] = 1;
    for(int i = 2; i <= 2 * n; i++) {
        for(int j = i + i; j <= 2 * n; j += i) isp[j] = 0;
    }
    vector<pair<int, int> > ans;
    for(int i = 1; i < n; i++) {
        ans.push_back(make_pair(i, i + 1));
    }
    ans.push_back(make_pair(n, 1));
    for(int i = 1; i <= n; i++) {
        if(isp[ans.size()]) break;
        int v = i + n / 2;
        if(v > n) v -= n;
        ans.push_back(make_pair(i, v));
    }
    printf("%d\n", ans.size());
    for(auto i : ans) printf("%d %d\n", i.first, i.second);
    return 0;
}