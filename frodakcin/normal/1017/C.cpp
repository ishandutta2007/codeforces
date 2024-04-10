#include <iostream>
#include <cstdio>

using namespace std;

int N;

int main() {
    scanf("%d", &N);
    int ctr = N;
    int sqrtN = 0;
    for(;sqrtN * sqrtN < N;sqrtN++);
    while(ctr > 0) {
        for(int i = 1;i <= sqrtN;i++) {
            if(ctr - sqrtN + i > 0) printf("%d ", ctr - sqrtN + i);
        }
        ctr -= sqrtN;
    }
    printf("\n");
    return 0;
}