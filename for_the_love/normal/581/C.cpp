#include <bits/stdc++.h>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-8;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;


int cnt[10][11];
int n, k, x;

int main(){
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++){
        scanf("%d", &x);
        cnt[x % 10][x / 10]++;
    }
    while (1){
        int flag = 0;
        for (int i = 9; i >= 0; i--){
            for (int j = 0; j < 10; j++)
            if (cnt[i][j]){
                int t = min(cnt[i][j], k / (10 - i));
                cnt[i][j] -= t;
                cnt[0][j + 1] += t;
                k -= t * (10 - i);
                if (t) flag = 1;
            }
        }
        if (!flag) break;
    }
    int ans = 0;
    for (int i = 0; i < 10; i++)
    for (int j = 0; j <= 10; j++)
        ans += cnt[i][j] * j;
    printf("%d\n", ans);
}