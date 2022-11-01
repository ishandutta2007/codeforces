#include <stdio.h>

int N[2],C[2],n;

int main(){
    scanf("%d",&n);
    N[0] = n/10;
    N[1] = n%10;
    for(int i=0;i<=1;i++) {
        if(N[i] == 0) C[i] += 2;
        if(N[i] == 1) C[i] += 7;
        if(N[i] == 2) C[i] += 2;
        if(N[i] == 3) C[i] += 3;
        if(N[i] == 4) C[i] += 3;
        if(N[i] == 5) C[i] += 4;
        if(N[i] == 6) C[i] += 2;
        if(N[i] == 7) C[i] += 5;
        if(N[i] == 8) C[i] += 1;
        if(N[i] == 9) C[i] += 2;
    }
    printf("%d\n",C[0]*C[1]);
    return 0;
}