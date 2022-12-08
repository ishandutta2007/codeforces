#include <iostream>
#include <cstdio>

#include <algorithm>

#include <cassert>

using namespace std;

const int MAXN = 110;
const int MAXV = 110;
const int RV = 10;

int N, a[MAXN];
int tot;

int can[MAXN * MAXV][MAXN];

void work(int sw, int am) {
    for(int i = tot;i >= 0;i--) {
        for(int j = N;j >= 0;j--) {
            for(int k = 1;k <= am and k*sw <= i and k <= j;k++) {
                can[i][j] += can[i-(k*sw)][j-k];
                if(can[i][j] > RV) can[i][j] = RV;
            }
        }
    }
}

void test() {
    int groups = 1;
    for(int i = 1;i < N;i++) {
        if(a[i] != a[i+1]) {
            groups++;
        }
    }
    if(groups <= 2) {
        printf("%d\n", N);
        exit(0);
    }
}

int main() {
    scanf("%d", &N);
    
    tot = 0;
    for(int i = 1;i <= N;i++) scanf("%d", a + i), tot += a[i];
    
    sort(a + 1, a + N + 1);
    
    test();
    
    for(int i = 0;i <= tot;i++) for(int j = 0;j <= N;j++) can[i][j] = 0;
    can[0][0] = 1;
    
    for(int i = 1, j;i <= N;i=j) {
        for(j = i + 1;j <= N and a[i] == a[j];j++);
        work(a[i], j-i);
    }
    
    int ans = 0;
    for(int i = 1, j;i <= N;i=j) {
        for(j = i + 1;j <= N and a[i] == a[j];j++) {
            int tw = (j - i) * a[i];
            
            assert(can[tw][j - i] >= 1 and can[tot - tw][N - (j - i)] >= 1);
            if(can[tw][j - i] == 1 or can[tot - tw][N - (j - i)] == 1) if((j - i) > ans) ans = j - i;
        }
        int tw = (j - i) * a[i];
    
        assert(can[tw][j - i] >= 1 and can[tot - tw][N - (j - i)] >= 1);
        if(can[tw][j - i] == 1 or can[tot - tw][N - (j - i)] == 1) if((j - i) > ans) ans = j - i;
    }
    
    printf("%d\n", ans);
    
    return 0;
}