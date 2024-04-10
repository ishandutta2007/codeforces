#include <algorithm>
#include <cstdio>
#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int N = 5e5 + 10;
int n, m;
long long a[N];
struct node{
    int x, y;
    long long z;
    node(int x = 0, int y = 0, long long z =  0):x(x), y(y), z(z) {}
};
vector<node> ans;
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i ++) {
        int x, y, z;
        scanf("%d %d %d", &x, &y, &z);
        a[x] += z;
        a[y] -= z;
    }
    int l = 1;
    for (int i = 1 ; i<= n; i ++)
        if (a[i] > 0) {
            while (l <= n && a[i]) {
                if (a[l] >= 0) {
                    ++l;
                    continue;
                }
                long long t = min(a[i], - a[l]);
                a[i] -= t;
                a[l] += t;
                if (t) ans.push_back(node(i, l, t));
                if (!a[l]) ++l;
            }
        }
    printf("%d\n", ans.size());
    for (auto u:ans)
        printf("%d %d %lld\n", u.x, u.y, u.z);
    return 0;
}