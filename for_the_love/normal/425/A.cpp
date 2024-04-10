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
const DB pi = acos(-1.0);
const int N = 1e5 + 7;
const int M = 10000;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;

int a[N], b[N], c[N];


int main(){
    int n, m, x;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    int ans = -INF;
    for (int i = 1; i <= n; i++)
    for (int j = i; j <= n; j++){
        int p = min(j - i + 1, m), cnt = 0, num = 0;
        for (int k = i; k <= j; k++) b[++cnt] = a[k];
        for (int k = 1; k < i; k++) c[++num] = a[k];
        for (int k = j + 1; k <= n; k++) c[++num] = a[k];
        sort(c + 1, c + num + 1);
        for (int k = num; k > num - p && k > 0; k--) b[++cnt] = c[k];
        sort(b + 1, b + cnt + 1);
        int t = 0;
        for (int k = cnt; k >= cnt - (j - i + 1) + 1; k--) t += b[k];
        ans = max(ans, t);
    }
    cout << ans << endl;

}