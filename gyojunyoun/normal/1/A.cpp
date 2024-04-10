#include <iostream>
#include <stdio.h>

int N, M, A;

int main()
{
    scanf("%d%d%d", &N, &M, &A);
    
    printf("%lld", ((long long)(N%A==0 ? N/A : N/A+1) * (long long)(M%A==0 ? M/A : M/A+1)));
    
    return 0;
}