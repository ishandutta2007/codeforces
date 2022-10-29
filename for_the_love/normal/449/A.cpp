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
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair <int, int> PI;

const DB eps = 1e-6;
const int N = 1e5 + 7;
const int INF = 1e9 + 7;
const int MOD = 1e9 + 7;

LL Calc(LL n, LL x){return n / (x + 1);}
LL a[N];

int main(){
    LL n, m, k;
    int cnt = 0;
    cin >> n >> m >> k;
    if (n + m - 2 < k){
        puts("-1");
        return 0;
    }
    LL ans = 0;
    for (int i = 1; i * i <= n; i++) a[++cnt] = i;
    for (int i = (int)sqrt(n); i >= 1; i--)
    if (i * i != n) a[++cnt] = n / i;

    for (int i = 1; i < cnt; i++){
        LL r = n / a[i] - 1, l = n / a[i + 1];
        if (l > k) continue;
        r = min(k, r);
        ans = max(ans, Calc(m, k - r) * a[i]);
    }
    ans = max(ans, n * Calc(m, k));
    ans = max(ans, m * Calc(n, k));
    cout << ans << endl;
}