#include <bits/stdc++.h>

#define INF 1000000000

using namespace std;

int n, x, L, R, M;

int query(int X, int Y) { // black = 1 / white = 0
    printf("%d %d\n", X, Y);
    fflush(stdout);
    char resp[10];
    scanf("%s", resp);
    return resp[0] == 'b';
}

int main() {
    scanf("%d", &n);

    if(n == 1) {
        int a1 = query(0, 0);
        printf("%d %d %d %d\n", 0, 1, 1, 1);
        fflush(stdout);
        return 0;
    }

    int a1 = query(0, 0), a2 = query(INF, 0);

    if(a1 != a2) {
        L = 1, R = INF-1;
        for(int i = 2; i < n; i++) {
            M = (L+R)/2;
            int res = query(M, 0);
            if(res == a1) L = M + 1;
            else R = M - 1;
        }
        printf("%d %d %d %d\n", L, 0, L, 1);
    } else {
        L = 1, R = INF;
        for(int i = 2; i < n; i++) {
            M = (L+R)/2;
            int res = query(INF/2, M);
            if(res == a1) L = M + 1;
            else R = M - 1;
        }
        printf("%d %d %d %d\n", 0, L, 1, L);
    }


    fflush(stdout);
    return 0;
}