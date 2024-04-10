#include <cstdio>

int main() {
    int n;
    scanf("%d", &n);
    int t;for (int i=1;i<=n;++i){
        scanf("%d", &t);
        if (t) {printf("HARD"); return 0;}
    } printf("EASY");
    
    
    return 0;
}