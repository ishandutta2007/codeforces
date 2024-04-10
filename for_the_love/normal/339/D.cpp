#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <sstream>
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1 << 20;
int a[N], next[N], fa[N], cnt;
void Build(int p, int l, int r){
    if (l == r) return;
    for (int i = l; i <= r; i += 2){
        fa[i] = fa[i + 1] = ++cnt;
        next[i] = i + 1;
        next[i + 1] = i;
        if (p) a[cnt] = a[i] ^ a[i + 1]; else a[cnt] = a[i] | a[i + 1];
    }
    Build(1 - p, r + 1, cnt);
}

int main(){
    int n, m, x, y;
    cin >> n >> m;
    for (int i = 1; i <= 1 << n; i++) cin >> a[i];
    cnt = 1 << n;
    Build(0, 1, 1 << n);
    for (int i = 1; i <= m; i++){
        cin >> x >> y;
        a[x] = y;
        for (int j = 1; j <= n; j++)
        if (j & 1){
            a[fa[x]] = a[next[x]] | a[x];
            x = fa[x];
        }else{
            a[fa[x]] = a[next[x]] ^ a[x];
            x = fa[x];
        }
        cout << a[x] << endl;
    }
}