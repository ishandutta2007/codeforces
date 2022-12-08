#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN = 110;
const int MAXM = 110;

int N, M;
int psum[MAXM];
int ans[MAXM], ansl;

int main() {
    scanf("%d%d", &N, &M);
    
    for(int i = 0;i <= M + 1;i++) {
        psum[i] = 0;
    }
    
    for(int i = 0;i < N;i++) {
        int a, b;
        scanf("%d%d", &a, &b);
        psum[a]++;
        psum[b + 1]--;
    }
    
    ansl = 0;
    int cv = 0;
    for(int i = 1;i <= M;i++) {
        cv += psum[i];
        if(cv == 0) ans[ansl++] = i;
    }
    printf("%d\n", ansl);
    for(int i = 0;i < ansl;i++) printf("%d ", ans[i]);
    printf("\n");
    
    return 0;
}