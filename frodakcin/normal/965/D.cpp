#include <iostream>
#include <cstdio>

#include <cassert>

using namespace std;

const int MAXW = 1e5 + 100;
const int INF = 1e9 + 1e6;

int L, W;
int a[MAXW], u[MAXW];
int main() {
    scanf("%d%d", &W, &L);
    assert(L < W);
    
    for(int i = 0;i < W - 1;i++) scanf("%d", a + i);
    a[W - 1] = INF;
    
    int ans = 0;
    for(int i = 0;i < L;i++) u[i] = a[i];
    for(int i = L;i < W;i++) u[i] = 0;
    for(int i = L, j = 0;i < W;i++) {
        if(i - j > L) j++;
        while(j < i) {
            if(u[j] > a[i] - u[i]) {
                u[j] -= (a[i] - u[i]);
                u[i] = a[i];
                break;
            } else {
                u[i] += u[j];
                u[j++] = 0;
            }
        }
    }
    printf("%d\n", u[W - 1]);
    return 0;
}