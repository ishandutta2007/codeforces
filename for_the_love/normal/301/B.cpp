#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 105;

int a[N], x[N], y[N], v[N], f[N], n, d;
queue <int> Q;
int main(){
    scanf("%d%d", &n, &d);
    for (int i = 2; i < n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%d%d", &x[i], &y[i]);
    Q.push(n);
    memset(f, 0x7f, sizeof(f));
    f[n] = 0; v[n] = 1;
    while (!Q.empty()){
        int now = Q.front(); Q.pop();
        for (int i = 1; i <= n; i++)
        if (i != now && f[i] > f[now] + (abs(x[i] - x[now]) + abs(y[i] - y[now])) * d - a[i]){
            f[i] = f[now] + (abs(x[i] - x[now]) + abs(y[i] - y[now])) * d - a[i];
            if (!v[i]){
                v[i] = 1;
                Q.push(i);
            }
        }
        v[now] = 0;
    }
    printf("%d\n", f[1]);

}