#include <iostream>
#include <cstdio>

using namespace std;

const int MAXV = 2e5 + 100;
const int MAXK = 2e5 + 100;

int N, K;

int c[MAXV];

int t[MAXK];
bool solve(int v) {
    int a = 0;
    for(int i = 0;i < MAXV;i++) {
        for(int j = 1;v * j <= c[i];j++) {
            t[a++] = i;
            if(a >= K) return true;
        }
    }
    return false;
}

int main() {
    for(int i = 0;i < MAXV;i++) c[i] = 0;
    
    scanf("%d%d", &N, &K);
    
    for(int i = 0, x;i < N;i++) scanf("%d", &x), c[x]++;
    
    int l = 0, h = N + 1;
    while(h > l + 1) {
        int m = l + ((h - l)>>1);
        if(solve(m)) l = m;
        else h = m;
    }
    solve(l);
    
    for(int i = 0;i < K;i++) printf("%d ", t[i]);
    printf("\n");
    
    return 0;
}