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
typedef pair<LL, LL> PI;

const DB eps = 1e-8;
const int N = 1e6 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;



int l[N], a[N];

int main(){
    int n, x;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &x);
        a[x] = 1;
    }
    int m = 1000000;
    for (int i = 1; i <= m; i++)
    if (a[i]) l[i] = i; else l[i] = l[i - 1];
    int ans = 0;
    for (int i = 1; i <= m; i++)
    if (a[i]){
        for (int j = i; j <= m; j += i)
            ans = max(ans, l[min(j + i - 1, m)] - j);
    }
    printf("%d\n", ans);
}