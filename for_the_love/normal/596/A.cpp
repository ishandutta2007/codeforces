#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 7;
const int INF = 1e9 + 7;

int main(){
    int n, x, y;
    scanf("%d", &n);
    int ly = INF, lx = INF, ry = -INF, rx = -INF;
    for (int i = 0; i < n; i++){
        scanf("%d%d", &x, &y);
        lx = min(lx, x), rx = max(rx, x);
        ly = min(ly, y), ry = max(ry, y);
    }
    if (rx > lx && ry > ly){
        printf("%d\n", (rx - lx) * (ry - ly));
    }else puts("-1");
}