#include <bits/stdc++.h>

using namespace std;

int N, M;

int main()
{
    scanf("%d%d", &N, &M);
    if(N==1)
        printf("1\n");
    else if(M-1>=N-M)
        printf("%d\n", M-1);
    else
        printf("%d\n", M+1);
    return 0;
}