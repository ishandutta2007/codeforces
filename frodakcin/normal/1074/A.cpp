#include <iostream>
#include <cstdio>

#include <cassert>
#include <algorithm>

using namespace std;

const int MAXV = 1e9;
const int MAXN = 1e5 + 1000;

int N, M, V, H;
int v[MAXN];
int h[MAXN];

int main() {
    scanf("%d%d", &N, &M);
    V = H = 0;
    int mina = 0;
    for(int i = 0, x;i < N;i++) {
        scanf("%d", &x);
        v[V++] = x;
    }
    v[V++] = MAXV + 100;
    
    for(int i = 0, x1, x2, y;i < M;i++) {
        scanf("%d%d%d", &x1, &x2, &y);
        assert(x1 <= x2);
        if(x1 > 1) continue;
        if(x2 >= MAXV) {mina++; continue;}
        h[H++] = x2;
    }
    
    sort(v, v + V);
    sort(h, h + H);
    
    int ans = 1e9;
    
    for(int i = 0, hc = 0, t;i < V;i++) {
        for(;hc < H and h[hc] < v[i];) hc++;
        if((t = mina + i + (H - hc)) < ans) ans = t;
    }
    
    assert(ans < 1e9);
    printf("%d\n", ans);
    
    return 0;
}