#include <cstdio>
#include <iostream>

using namespace std;

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);

    if(a > b) swap(a, b);
    if(b > c) swap(b, c);
    
    int ans = c + 1 - (a + b);
    if(ans < 0) ans = 0;
    printf("%d\n", ans);
    
    return 0;
}