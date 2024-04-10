#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int M = 100 * 2000;
int n;
int a[101];
pair<int, int> f[2][M * 2 + 1];
void upd(pair<int, int> & a, pair<int, int> v) {
    if (v.second > a.second) a = v;
}
int main() 
{
    scanf("%d", &n);
    f[0][M] = make_pair(0, 1);
    int sig = 0;
    bool bz = 0, bz1 = 1;
    for (int i = 1; i <= n; i ++, swap(bz, bz1)) {
        scanf("%d", &a[i]);
        if (a[i] & 1) sig = i;
        for (int j = -M; j <= M; j ++)
            if (f[bz][j + M].second) {
                upd(f[bz1][j + M], make_pair(0, f[bz][j + M].second));
                upd(f[bz1][j + M + a[i]], make_pair(-1, f[bz][j + M].second + 1));
                upd(f[bz1][j + M - a[i]], make_pair(+1, f[bz][j + M].second + 1));
                f[bz][j + M] = make_pair(0, 0);
            }
    }
    while (!sig) {
        for (int i = 1; i <= n; i ++) {
            a[i] /= 2;
            if (a[i] & 1) sig = i;
        }
    }
    if (f[bz][M].second == n + 1) {
        printf("1\n%d\n", sig);
    } else {
        puts("0");
    }
    return 0;
}