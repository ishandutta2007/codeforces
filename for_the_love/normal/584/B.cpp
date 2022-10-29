#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <bitset>
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
const int N = 1e2 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int main(){
    int n;
    scanf("%d", &n);
    LL A = 1, B = 1;
    for (int i = 1; i <= n; i++){
        A = A * 27 % MOD;
        B = B * 7 % MOD;
    }
    LL ans = A - B;
    ans = (ans % MOD + MOD) % MOD;
    printf("%I64d\n", ans);
}