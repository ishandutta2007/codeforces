#include <iostream>
#include <cstdio>

using namespace std;

int N;

void solve(int n, int m = 1) {
    if(n == 1) {printf("%d\n", m); return;}
    if(n == 2) {printf("%d %d\n", m, m * 2); return;}
    if(n == 3) {printf("%d %d %d\n", m, m, m * 3); return;}
    for(int i = 0;i + i < n;i++) printf("%d ", m);
    solve(n/2, m << 1);
}

int main() {
    scanf("%d", &N);
    solve(N);
    return 0;
}