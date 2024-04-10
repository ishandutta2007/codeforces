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
const int N = 5555;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;

int a[N], n;

LL Solve(int l, int r){
    int mn = INF;
    LL ret = r - l + 1;
    for (int i = l; i <= r; i++) mn = min(a[i], mn);
    for (int i = l; i <= r; i++) a[i] -= mn;
    LL s = mn;
    int cnt = 0;
    for (int i = l; i <= r; i++)
    if (!a[i]){
        if (cnt) s += Solve(i - cnt, i - 1);
        cnt = 0;
    }else cnt++;
    if (cnt) s += Solve(r - cnt + 1, r);
    return min(ret, s);
}

int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    printf("%I64d\n", Solve(1, n));
}