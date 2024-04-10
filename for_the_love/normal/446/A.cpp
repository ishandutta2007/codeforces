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
const int N = 1e5 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;


int a[N], l[N], r[N], n;
int main(){
    scanf("%d", &n);
    for (int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        if (a[i] > a[i - 1]) l[i] = l[i - 1] + 1; else l[i] = 1;
    }
    for (int i = n; i >= 1; i--)
    if (a[i] < a[i + 1]) r[i] = r[i + 1] + 1; else r[i] = 1;

    int ans = 0;
    for (int i = 1; i <= n; i++) ans = max(ans, l[i]), ans = max(ans, r[i]);
    ans = min(ans + 1, n);

    for (int i = 2; i <= n - 1; i++)
    if (a[i - 1] + 1 < a[i + 1]) ans = max(ans, l[i - 1] + r[i + 1] + 1);

    cout << ans << endl;
}