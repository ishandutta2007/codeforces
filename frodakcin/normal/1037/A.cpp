#include <iostream>
#include <cstdio>

using namespace std;

int N;

int main() {
    scanf("%d", &N);
    
    int ans = 0;
    while((1 << (++ans)) <= N);
    
    printf("%d\n", ans);
    return 0;
}