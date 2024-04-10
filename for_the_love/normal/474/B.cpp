#include <map>
#include <set>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
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
typedef pair<DB, DB> DPI;
const DB eps = 1e-8;
const int N = 1e6 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

int ans[N];
int main(){
//    scanf("%d%d", &cas, &k);
//    while (cas--){
//        scanf("%")
//
//    }
    int n, x, q;
    scanf("%d", &n);
    int sum = 0;
    for (int i = 1; i <= n; i++){
        scanf("%d", &x);
        for (int j = sum + 1; j <= sum + x; j++) ans[j] = i;
        sum += x;
    }
    scanf("%d", &q);
    while (q--){
        scanf("%d", &x);
        printf("%d\n", ans[x]);
    }
}