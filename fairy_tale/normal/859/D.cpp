//created by missever

#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int,int> P;

const int mod = 1e9 + 7;
const int maxn = 1e5 + 5;

int a[70][70];
double p[70][70],f[10][70],s[10][70];

int main() {
#ifdef CX_TEST
    freopen("E:\\program--GG\\test_in.txt", "r", stdin);
#endif
    int n,k,i,j,x,y;
    double ans = 0.0;
    scanf("%d",&k);
    n = 1 << k;
    for(i = 0;i < n; i++) {
        for(j = 0;j < n; j++) scanf("%d",&a[i][j]);
        p[0][i] = 1.0;
    }
    for(i = 1;i <= k; i++) {
        for(j = 0;j < (1 << (k - i)); j++) {
            for(x = 0;x < (1 << (i - 1)); x++) {
                for(y = 1 << (i - 1);y < (1 << i); y++) p[i][j << i | x] += p[i - 1][j << i | x] * p[i - 1][j << i | y] * (a[j << i | x][j << i | y] * 0.01);
            }
            for(x = 1 << (i - 1);x < (1 << i); x++) {
                for(y = 0;y < (1 << (i - 1)); y++) p[i][j << i | x] += p[i - 1][j << i | x] * p[i - 1][j << i | y] * (a[j << i | x][j << i | y] * 0.01);
            }
            for(x = j << i;x < ((j + 1) << i); x++) {
                for(y = 1;y < i; y++) f[i][x] += p[y][x] * (1 << (y - 1)) + s[y][(x >> y) ^ 1];
                f[i][x] += p[i][x] * (1 << (i - 1));
            }
            for(x = 0;x < (1 << i); x++) s[i][j] = max(f[i][j << i | x],s[i][j]);
        }
    }
    printf("%.10lf\n",s[k][0]);
    return 0;
}