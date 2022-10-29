#include <map>
#include <cmath>
#include <queue>
#include <cstdio>
#include <string>
#include <vector>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

long long b[4][1005][1005], d;

int n, m, p, lx, rx, ly, ry;
inline int lowbit(int x){return x & -x;}

int Type(int x, int y){
    if ((x & 1) == 0 && (y & 1) == 0) return 0;
    if ((x & 1) == 0 && (y & 1)) return 1;
    if ((x & 1) && (y & 1) == 0) return 2;
    return 3;
}
void Xor(int x, int y, long long d){
    int p = Type(x, y);
    for (;x <= n; x += lowbit(x))
    for (int t = y; t <= n; t += lowbit(t))
        b[p][x][t] ^= d;
}
long long Query(int x, int y){
    long long ret = 0;
    int p = Type(x, y);
    for (;x; x -= lowbit(x))
    for (int t = y; t; t -= lowbit(t))
        ret ^= b[p][x][t];
    return ret;
}


int main(){
    scanf("%d%d", &n, &m);
    while (m--){
        scanf("%d%d%d%d%d", &p, &lx, &ly, &rx, &ry);
        if (p == 2){
            scanf("%I64d", &d);
            Xor(lx, ly, d);
            Xor(lx, ry + 1, d);
            Xor(rx + 1, ly, d);
            Xor(rx + 1, ry + 1, d);
        }else{
            long long res = Query(lx - 1, ly - 1);
            res ^= Query(lx - 1, ry);
            res ^= Query(rx, ly - 1);
            res ^= Query(rx, ry);
            printf("%I64d\n", res);
        }
    }
}