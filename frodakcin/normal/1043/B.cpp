#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 1e3 + 10;
int N, a[MAXN], d[MAXN], x[MAXN];

int ans, ansv[MAXN];

int main() {
    scanf("%d", &N);
    a[0] = 0;
    for(int i = 1;i <= N;i++) scanf("%d", a + i);
    for(int i = 0;i < N;i++) d[i] = a[i + 1] - a[i];
    
    ans = 0;
    for(int k = 1;k < N;k++) {
        for(int i = 0;i < k;i++) x[i] = d[i];
        bool w = true;
        for(int i = k;i < N;i++) if(d[i] != x[i%k]) {w = false; break;}
        if(w) {
            ansv[ans++] = k;
        }
    }
    ansv[ans++] = N;
    
    printf("%d\n", ans);
    for(int i = 0;i < ans;i++) printf("%d ", ansv[i]);
    printf("\n");
    
    return 0;
}