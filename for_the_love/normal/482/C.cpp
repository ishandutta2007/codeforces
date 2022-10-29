#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int, int> PI;

const DB eps = 1e-8;
const int N = 100 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int n, m, cnt[1 << 20], num[1 << 20];
char s[55][25];
LL mk[1 << 20];
DB f[1 << 20];

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%s", s[i]);
    m = strlen(s[0]);

    for (int i = 0; i < n; i++)
    for (int j = 0; j < n; j++)
    if (i != j){
        int tmp = 0;
        for (int k = 0; k < m; k++)
        if (s[i][k] == s[j][k]) tmp |= 1 << k;

        mk[tmp] |= 1LL << i;
    }

    for (int i = (1 << m) - 1; i >= 0; i--){
        for (int j = 0; j < m; j++)
        if (i >> j & 1){
            mk[i ^ (1 << j)] |= mk[i];
            num[i]++;
        }

        for (int j = 0; j < n; j++)
        if (mk[i] >> j & 1) cnt[i]++;
    }

    DB ans = 0;
    f[0] = 1;
    for (int i = 0; i < (1 << m); i++){
        if (!cnt[i]) continue;
        for (int j = 0; j < m; j++)
        if (!(i >> j & 1)){
            int x = i ^ (1 << j);
            f[x] += f[i] * cnt[x] / cnt[i] / (m - num[i]);
            ans += f[i] * (cnt[i] - cnt[x]) / cnt[i] * (num[i] + 1) / (m - num[i]);
        }
    }
    printf("%.15lf\n", ans);

}