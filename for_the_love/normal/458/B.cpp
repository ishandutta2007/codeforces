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

LL a[N], b[N];

LL Calc(LL a[], LL b[], int n, int m){
    LL mx = 0, p;
    for (int i = 1; i <= n; i++)
    if (a[i] > mx){
        mx = a[i];
        p = i;
    }
    LL sum = 0;
    for (int i = 1; i <= m; i++) sum += b[i];
    LL ret = sum;
    for (int i = 1; i <= n; i++)
    if (i != p) ret += min(sum, a[i]);
    return ret;
}

int main(){
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%I64d", &a[i]);
    for (int i = 1; i <= m; i++) scanf("%I64d", &b[i]);
    cout << min(Calc(a, b, n, m), Calc(b, a, m, n));

}