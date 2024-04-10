#include <iostream>
#include <cstdio>

using namespace std;

int N;

int main() {
    scanf("%d", &N);
    int x = 0, y = 0;
    for(int i = 0;i < N;i++) {
        int a;
        scanf("%d", &a);
        x += a;
    }
    for(int i = 0;i < N;i++) {
        int a;
        scanf("%d", &a);
        y += a;
    }
    if(x >= y) printf("Yes\n");
    else printf("No\n");
}