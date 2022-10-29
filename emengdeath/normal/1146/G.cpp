#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include <cstdio>
#include <string>
#include <unordered_map>
using namespace std;
const int N = 100;
long long f[N][N][N];
struct node
{
    int l, r, x, c;
}q[N];
int n, m, h;
bool in(int x, int l,int r)
{
    return l<=x && x <= r;
}
int main() {
    scanf("%d %d %d", &n, &h, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d %d %d %d", &q[i].l, &q[i].r, &q[i].x, &q[i].c);
    }
    for (int i = 1; i <= n ; i++)
        for (int l = 1; l + i - 1 <= n ; l ++ ) {
            int r = l + i - 1;
            for (int hmax = 0; hmax <= h; hmax++)
            {
                for (int mid = l ; mid <= r;  mid ++)
                {
                    long long v = f[l][mid -1][hmax] +  f[mid + 1][r][hmax] + hmax * hmax;
                    for (int j = 1; j <= m ; j ++)
                        if (q[j].x < hmax&& in(q[j].l, l, mid)  && in(q[j].r, mid, r))
                            v -= q[j].c;
                    f[l][r][hmax] = max(f[l][r][hmax], v);
                }
                if (hmax)
                    f[l][r][hmax] = max(f[l][r][hmax], f[l][r][hmax - 1]);
            }
        }
    long long ans = 0;
    for (int i = 0; i <= h ; i ++)
        ans = max(ans, f[1][n][i]);
    cout<<ans;
    return 0;
}