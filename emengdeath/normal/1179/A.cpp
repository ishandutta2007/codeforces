#include <string>
#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <cstring>
#include <algorithm>
#include <bitset>
#include <deque>
using namespace std;
const int N = 1e5 + 1;
vector<pair<int, int> >f;
deque<int>d;
int main()
{
    int n, m;
    int mx = 0;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n ; i ++) {
        int x;
        scanf("%d", &x);
        d.push_back(x);
        mx = max(mx, x);
    }
    while (d[0] != mx) {
        f.push_back(make_pair(d[0], d[1]));
        if (d[0] > d[1]) swap(d[0], d[1]);
        d.push_back(d[0]);
        d.pop_front();
    }
    while (m --) {
        long long x;
        scanf("%lld", &x);
        if (x <= f.size())
            printf("%d %d\n", f[x - 1].first, f[x - 1].second);
        else {
            x -= f.size();
            x %= (n - 1);
            if (!x) x = n - 1;
            printf("%d %d\n", mx, d[x]);
        }
    }
    return 0;
}