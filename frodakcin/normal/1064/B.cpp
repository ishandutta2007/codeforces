#include <iostream>
#include <cstdio>

using namespace std;

int T, a;

int main() {
    scanf("%d", &T);
    for(int i = 0;i < T;i++) {
        scanf("%d", &a);
        int p = __builtin_popcount(a);
        printf("%d\n", (1 << p));
    }
    
    return 0;
}