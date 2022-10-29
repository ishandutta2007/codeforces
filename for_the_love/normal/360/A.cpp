
//#pragma comment(linker, "/STACK:102400000,102400000")
#include <set>
#include <cassert>
#include <map>
#include <cmath>
#include <ctime>
#include <queue>
#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int N = 5555;
const int INF = 1e9;

int n, m, p[N], l[N], r[N], d[N], ans[N], a[N], b[N];
int main(){
    //freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) ans[i] = INF;
    for (int i = 1; i <= m; i++){
        scanf("%d%d%d%d", &p[i], &l[i], &r[i], &d[i]);
        if (p[i] == 1){
            for (int j = l[i]; j <= r[i]; j++)
                a[j] += d[i];
        }else{
            for (int j = l[i]; j <= r[i]; j++)
            if (ans[j] + a[j] >= d[i]) ans[j] = min(ans[j], d[i] - a[j]);
        }
    }
    memcpy(b, ans, sizeof(ans));
    for (int i = 1; i <= m; i++){
        if (p[i] == 1){
            for (int j = l[i]; j <= r[i]; j++) b[j] += d[i];
        }else{
            int mx = -INF;
            for (int j = l[i]; j <= r[i]; j++) mx = max(b[j], mx);
            if (mx != d[i]){
                puts("NO");
                return 0;
            }
        }
    }
    puts("YES");
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);
}