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
const int dx[] = {0, 1, 0, -1};
const int dy[] = {1, 0, -1, 0};
const DB eps = 1e-6;
const int N = 1e3 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;



int x[N], y[N], z[N], n;

int Calc(DB l){
    int ret = 0;
    for (int i = 0; i < n; i++)
    if (sqrt(DB(x[i] * x[i] + y[i] * y[i])) <= l) ret += z[i];
    return ret;
}

int main(){
    int s;
    scanf("%d%d", &n, &s);
    for (int i = 0; i < n; i++) scanf("%d%d%d", &x[i], &y[i], &z[i]);

    DB l = 0, r = 1e6;
    int found = 0;
    while (l + 1e-7 < r){
        DB mid = (l + r) / 2;
        if (Calc(mid) + s >= 1000000){
            found = 1;
            r = mid;
        }else l = mid;
    }
    if (!found) puts("-1"); else printf("%lf\n", r);

}