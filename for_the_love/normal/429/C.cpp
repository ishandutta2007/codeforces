#include <set>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

#define PB push_back
#define MP make_pair

typedef double DB;
typedef long long LL;
typedef pair<int,int> PI;

const DB eps = 1e-6;
const int N = 1e3 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;

int a[N], b[N], c[N], n, cnt, sum, found = 0;


bool cmp(int a, int b){return a > b;}

void Dfs(int x){
    if (x == n){
        if (sum == cnt) found = 1;
        return;
    }
    for (int i = 0; i < x; i++)
    if (a[i] > b[x] && b[i] != b[x] + 1){
        a[i] -= b[x];
        sum -= b[x];
        c[i]++;
        Dfs(x + 1);
        sum += b[x];
        c[i]--;
        a[i] += b[x];
    }
}

int main(){
    scanf("%d", &n);
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    if (n == 1 && a[0] == 1){
        puts("YES");
        return 0;
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++) b[i] = a[i];
    for (int i = n - 1; i >= 0; i--){
        if (a[i] != 1) break;
        cnt++;
    }
    for (int i = 0; i < n; i++) if (a[i] == 2){
        puts("NO");
        return 0;
    }
    if (cnt * 2 <= n){
        puts("NO");
        return 0;
    }
    n -= cnt;
    for (int i = 0; i < n; i++) sum += a[i] - 1;
    Dfs(1);
    if (found) puts("YES"); else puts("NO");
}