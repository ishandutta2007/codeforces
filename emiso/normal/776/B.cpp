#include <bits/stdc++.h>

#define MN 100100
#define w1 while(1)

using namespace std;
typedef long long ll;

int n, a[MN], ans;

void crivo() {
    for(int i=2;i<MN;i++) a[i] = 1;
    for(int i=2; i * i < MN; i++) {
        if(a[i])
            for(int j = i * i; j < MN; j+= i)
                a[j] = 0;
    }

    //for(int i=2;i<20;i++) printf("%d %d\n", i, a[i]);
}

int main() {
    scanf("%d", &n);
    crivo();

    if(n == 1) printf("1\n1");
    else if(n == 2) printf("1\n1 1");
    else {
        printf("2\n");
        for(int i = 2; i < n + 2; i++) {
            if(a[i]) printf("1 ");
            else printf("2 ");
        }
    }

    printf("\n");

    return 0;
}