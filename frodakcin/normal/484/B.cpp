#include <iostream>
#include <cstdio>

#include <algorithm>

using namespace std;

const int MAXN = 2e5 + 100;
const int MAXA = 1e6 + 100;

bool ex[MAXA];
int ub[MAXA];
int N, a[MAXN];

int gub(int v) {
    if(not (v < MAXA)) return a[N-1];
    else return ub[v];
}

int main() {
    scanf("%d", &N);
    for(int i = 0;i < MAXA;i++) ex[i] = false;
    for(int i = 0;i < N;i++) {
        scanf("%d", a + i);
        ex[a[i]] = true;
    }
    sort(a, a + N);
    
    ub[0] = -1;
    for(int i = 1;i < MAXA;i++) {
        ub[i] = ub[i-1];
        if(ex[i-1]) ub[i] = i - 1;
    }
    
    int ans = 0;
    for(int i = 0, j;i < N;i = j) {
        int v = a[i];
        for(int j = 2, r;j*v < 2*MAXA;j++) {
            if((r = gub(j*v) - v*(j - 1)) < v and not (r < 0)) if(r > ans) ans = r;
        }
        for(j = i + 1;j < N and a[i] == a[j];j++);
    }
    
    printf("%d\n", ans);
    
    return 0;
}