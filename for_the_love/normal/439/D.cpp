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
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;


int n, m, a[N], b[N], c[N];

int main(){
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        c[i] = a[i];
    }
    int j = 1, k = 1;
    LL sa = 0, sb = 0;
    for (int i = 1; i <= m; i++){
        scanf("%d", &b[i]);
        c[i + n] = b[i];
        sb += b[i];
    }
    sort(c + 1, c + n + m + 1);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    LL ans = 1e18;
    for (int i = 1; i <= n + m; i++){
        while (a[j] < c[i] && j <= n){
            sa += a[j];
            j++;
        }
        while (b[k] < c[i] && k <= m){
            sb -= b[k];
            k++;
        }
        ans = min(ans, (LL)(j - 1) * c[i] - sa + sb - (LL)(m - k + 1) * c[i]);
    }
    cout << ans << endl;
}