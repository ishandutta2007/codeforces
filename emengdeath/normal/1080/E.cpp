#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
const int N = 260;
int n, m;
bool bz[N][N][N];
char a[N][N];
int sum[26];
long long spv[N][N][N];
int cnt;
long long v[26];
long long S[N * 2];
int totS;
int k[N * 2];

long long ans = 0;
void work() {
    if (!totS) return;
    S[0]=-1;
    for (int i = totS; i >= 1; i --) {
        S[i * 2] = S[i];
        S[i * 2 - 1] = -2;
    }
    S[totS * 2 + 1] = -2;
    S[totS * 2 + 2] = -3;
    totS = (totS + 1) * 2;
    int x=0;
    for (int i=1;i<totS;i++){
        if (k[x]+x>=i)
            k[i]=min(k[x+x-i],k[x]+x-i);
        else
            k[i] = 0;
        while (S[k[i]+i+1]==S[i-k[i]-1])k[i]++;
        if (k[i]+i>x+k[x])x=i;
        ans += (k[i]+ 1)/ 2;
    }
    totS = 0;
}
int main() {
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++)
            scanf(" %c", &a[i][j]), a[i][j] -= 'a';
    v[0] = 1;
    for (int i = 1; i < 26; i ++) v[i] = v[i -1] * 251;
    for (int i = 1; i <= n; i ++)
        for (int j = 1; j <= m; j ++) {
            cnt = 0;
            memset(sum, 0, sizeof(sum));
            long long vv = 0;
            for (int r = j; r <= m; r++) {
                vv += v[a[i][r]];
                cnt += ((sum[a[i][r]] += 1) & 1) * 2 -1;
                spv[i][j][r] = vv;
                if (cnt <= 1) bz[i][j][r] = 1;
            }
        }
    for (int i = 1; i <= m; i ++)
        for (int j = i ; j <= m; j ++) {
            for (int l = 1; l <= n; l ++)
                if (bz[l][i][j]) {
                    S[++totS] = spv[l][i][j];
                } else {
                    work();
                }
            work();
        }
    printf("%d\n", ans);
    return 0;
}