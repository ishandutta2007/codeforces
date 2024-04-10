#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int n, a, b, adj[1100][1100], tp = 1;

void failt() {
    puts("NO");
    exit(0);
}

int main() {
    scanf("%d %d %d", &n, &a, &b);

    if(n == 2 && a == 1 && b == 1) {
        failt();
    }

    if(n == 3 && a == 1 && b == 1) {
        failt();
    }

    if(a > 1 && b > 1) {
        failt();
    }

    puts("YES");

    if(a == 1 && b > 1) {
        tp = 0;
        for(int i = 0; i < 1100; i++)
            for(int j = 0; j < 1100; j++)
                if(i != j) adj[i][j] = 1;
        swap(a, b);
    }

    for(int i = 0; i < n - a; i++) {
        adj[i][i+1] = tp;
        adj[i+1][i] = tp;
    }

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            printf("%d", adj[i][j]);
        } puts("");
    }

    return 0;
}