#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k, x;
    int menor = 0x3f3f3f, maior = -0x3f3f3f;
    scanf("%d %d", &n, &k);
    scanf("%d", &menor);
    maior = menor;
    int ultimo, primeiro = menor;
    for(int i = 1; i < n; i++) {
        scanf("%d", &x);
        maior = max(x, maior);
        menor = min(x, menor);
        if(i == n - 1) {
            ultimo = x;
        }
    }
    if(k == 1) {
        printf("%d\n", menor);
    } else if(k == 2) {
        printf("%d\n", max(primeiro, ultimo));
    } else {
        printf("%d\n", maior);
    }
    return 0;
}