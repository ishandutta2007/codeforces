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
const int N = 1e6 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int a[N];
LL dp[N];

int main(){
    int n;
    scanf("%d", &n);
    dp[1] = 0;
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        if (i == 1) continue;
        if (i == 2) dp[i] = abs(a[i] - a[i - 1]);
        else{
            if (a[i] >= a[i - 1]){
                if (a[i - 1] >= a[i - 2]) dp[i] = max(dp[i - 1], dp[i - 1] + a[i] - a[i - 1]);
                else dp[i] = max(dp[i - 1], dp[i - 2] + a[i] - a[i - 1]);
            }else{
                if (a[i - 1] <= a[i - 2]) dp[i] = max(dp[i - 1], dp[i - 1] + a[i - 1] - a[i]);
                else dp[i] = max(dp[i - 1], dp[i - 2] + a[i - 1] - a[i]);
            }
        }
    }
    printf("%I64d\n", dp[n]);
}