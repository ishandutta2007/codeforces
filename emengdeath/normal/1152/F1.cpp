#include<cmath>
#include<ctime>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<queue>
#include<set>
#include <cstdio>
using namespace std;
const int N = 1e5 + 2;
const int mod =  1e9 + 7;
int f[N][13][1<<4];
int n, k, m;
void update(int & a, int b)
{
    a += b;
    if (a >= mod)
        a -= mod;
}
int main(){
    scanf("%d %d %d", &n, &k, &m);
    f[n + 1][0][0] = 1;
    for (int i = n + 1; i > 1 ; i --)
        for (int cnt = 0; cnt <= k; cnt ++)
            for (int j = 0; j < (1 << m) ; j ++)
                if (f[i][cnt][j])
                {
                    update(f[i - 1][cnt][(j << 1) % (1 << m)], f[i][cnt][j]);
                    if (cnt != k) {
                        for (int l = 0; l < m; l++)
                            if ((1 << l) & j)
                                update(f[i - 1][cnt + 1][(j << 1) % (1 << m) + 1], f[i][cnt][j]);
                        update(f[i - 1][cnt + 1][(j << 1) % (1 << m) + 1], f[i][cnt][j]);
                    }
                }
    int ans = 0;
    for (int i = 0; i < (1 << m);  i ++)
        update(ans, f[1][k][i]);
    printf("%d\n", ans);
    return 0;
}