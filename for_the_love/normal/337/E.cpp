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
const int INF = 1e9 + 7;

int n, ans, v[10];
long long a[10], b[10], c[10], d[10];
int e[10][10];
map <long long, int> S;
int Gao(long long x){
    int ret = 0;
    for (long long i = 2; i * i <= x; i++)
    while (x % i == 0){
        x /= i;
        ret++;
    }
    if (x != 1) ret++;
    return ret;
}

void Dfs(int x){
    if (x > n){
        int cnt = 0;
        for (int i = 1; i <= n; i++)
        if (!(c[i] == 1 && a[i] == b[i])) cnt += c[i];
        if (e[0][0] > 1) cnt++;
        ans = min(ans, cnt + n);
        return;
    }
    for (int i = 1; i <= n; i++)
    if (x != i && a[i] % b[x] == 0){
        a[i] /= b[x];
        e[i][++e[i][0]] = i;
        c[i] -= d[x];
        Dfs(x + 1);
        e[i][0]--;
        a[i] *= b[x];
        c[i] += d[x];
    }
    e[0][++e[0][0]] = x;
    Dfs(x + 1);
    e[0][0]--;
}



int main(){
    cin >> n;
    for (int i = 1; i <= n; i++){
        cin >> a[i];
        b[i] = a[i];
        c[i] = Gao(a[i]);
        d[i] = c[i];
    }
    ans = INF;
    Dfs(1);
    printf("%d\n", ans);
}