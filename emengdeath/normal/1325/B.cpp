#include <algorithm>
#include <cstdio>
#include <set>
using namespace std;
int main() {
    int t;
    scanf("%d", &t);
    while (t --) {
        int n;
        scanf("%d", &n);
        set<int>f;
        while (n --) {
            int x;
            scanf("%d", &x);
            f.insert(x);
        }
        int ans = 0;
        for (auto u:f)
            ans ++;
        printf("%d\n", ans);
    }
    return 0;
}