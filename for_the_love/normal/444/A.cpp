#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int,int> PI;

const DB eps = 1e-6;
const int N = 100;
const int MOD = 1e9 + 9;
const int INF = 1e9 + 7;


int n, m, a[555];
int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    DB ans = 0;
    for (int i = 1; i <= m; i++){
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        ans = max(ans, double(a[x] + a[y]) / z);
    }
    printf("%.10lf\n", ans);
}