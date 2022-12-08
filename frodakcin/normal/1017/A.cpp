#include <iostream>
#include <cstdio>

using namespace std;

int N, T, R;

int main() {
    scanf("%d", &N);
    
    int a, b, c, d;
    scanf("%d%d%d%d", &a, &b, &c, &d);
    T = a + b + c + d;
    R = 1;
    for(int i = 0;i < N-1;i++) {
        scanf("%d%d%d%d", &a, &b, &c, &d);
        if(a + b + c + d > T) R++;
    }
    printf("%d\n", R);
    
    return 0;
}