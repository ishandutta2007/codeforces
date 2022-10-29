#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e3 + 10;
int T;
int n;
int a[N];
int tag;
struct node{
    int bz;
    int sig, sum;
}f[N][N * 2];
void update(node&a, int sig, int sum) {
    if (sum > n / 2) return;
    if (a.bz != tag || a.sum > sum) {
        a.sum = sum;
        a.sig = sig;
        a.bz = tag;
    }
}
int main() {
    scanf("%d", &T);
    while (T --) {
        scanf("%d", &n);
        tag ++;
        f[0][N].bz = tag;
        f[0][N].sum = 0;
        for (int i = 1;i <= n; i ++) {
            scanf("%d", &a[i]);
            for (int j = -i; j <= i; j ++)
                if (f[i - 1][j + N].bz == tag) {
                    update(f[i][j+N], 0,f[i - 1][j+N].sum + 1);
                    update(f[i][a[i] - j + N], 1, f[i - 1][j+N].sum);
                }
        }
        int x = 0;
        vector<int> ans;
        for (int i = n; i >= 1; i --) {
            if (f[i][x + N].sig) {
                ans.push_back(a[i]);
                x = a[i] - x;
            } else {
            }
        }
        printf("%d\n", ans.size());
        reverse(ans.begin(), ans.end());
        for (auto u:ans)
        printf("%d ", u);
        puts("");
    }
    return 0;
}