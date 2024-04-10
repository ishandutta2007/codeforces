#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <cmath>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <string>
#include <bitset>

typedef long long LL;
#define pb push_back
#define MPII make_pair<int, int>
#define PII pair<int, int>
#define sz(x) (int)x.size()

using namespace std;

template<class T> T abs(T x){if (x < 0) return -x; else return x;}

const int maxn = 111;
int sum[maxn][maxn];
char c[maxn][maxn];

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i)
        scanf("%s", c[i] + 1);
    memset(sum, 0, sizeof(sum));
    int ans = 0;
    for (int i = n; i >= 1; --i)
        for (int j = m; j >= 1; --j){
            sum[i][j] = sum[i + 1][j] + sum[i][j + 1] - sum[i + 1][j + 1];
            int t = 1;
            if (c[i][j] == 'W') t = -1;
            if (sum[i][j] != t){
                sum[i][j] += t - sum[i][j];
                ++ans;
            }
        }
    printf("%d\n", ans);
    return 0;
}