#include <bits/stdc++.h>

using namespace std;

int N;

int main()
{
    scanf("%d", &N);
    if(N==1)
    {
        printf("1\n1\n");
        return 0;
    }
    if(N==2)
    {
        printf("1\n1\n");
        return 0;
    }
    if(N==3)
    {
        printf("2\n1 3\n");
        return 0;
    }
    if(N==4)
    {
        printf("4\n3 1 4 2\n");
        return 0;
    }
    printf("%d\n", N);
    int a=1, b=(N+1)/2+1;
    for(int i=0; i<N/2; i++)
        printf("%d %d ", a++, b++);
    if(N&1)
        printf("%d\n", a);
    else
        printf("\n");
    return 0;
}