#include <cstdio>
#include <algorithm>
#include <queue>
#include <cstring>
#include <iostream>
#include <unordered_map>
#include <map>
#include <numeric>
using namespace std;
const int N = 1e3 + 10;
int a[N], b[N];
struct node{
    int sig, l, r;
}q[N];
int n, m;
vector<pair<int,int> >g;
int sum, l;
bool bz[N];
int main() {
    scanf("%d %d", &n ,&m);
    for (int i = 1; i<= m ; i ++) {
        scanf("%d %d %d", &q[i].sig, &q[i].l, &q[i].r);
        if (q[i].sig)
            g.push_back(make_pair(q[i].l, 1)), g.push_back(make_pair(q[i].r + 1, 0));
    }
    sort(g.begin(), g.end());
    sum = 0;
    l = n;
    for (auto u:g) {
        if (u.second == 1) {
            l = min(l, u.first);
            sum++;
        } else {
            if (sum == 1) {
                int x = -l;
                while (l != u.first) {
                    b[l] = x;
                    bz[l] = 1;
                    l++;
                    x++;
                }
                l = n;
            }
            sum--;
        }
    }
    if (sum) {
        int x = -l;
        while (l >= n) {
            b[l] = x;
            bz[l] = 1;
            x++;
            l++;
        }
    }
    for (int i = 1; i <= n ; i ++)
        if (!bz[i]) b[i] = - i;
    for (int i = 1; i <= m ; i ++)
        if (!q[i].sig) {
            bool sig =0;
            for (int j = q[i].l + 1; j <= q[i].r; j ++)
                if (b[j] < b[j - 1]) {
                    sig = 1;
                    break;
                }
            if (!sig) {
                printf("NO");
                return 0;
            }
        }
    printf("YES\n");
    for (int i = 1; i <= n ;  i++)printf("%d ", b[i] + n + 1);
    return 0;
}