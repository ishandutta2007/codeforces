#include <bits/stdc++.h>

using namespace std;

int N, K;

int main()
{
    cin>>N>>K;
    if(N<2 || N/2>K)
    {
        if(N==1 && K==0)
            printf("1\n");
        else
            printf("-1\n");
        return 0;
    }
    int half=N/2, reserved1=K-(half-1), reserved2=reserved1*2;
    int cur=reserved2+1;
    for(int i=1; i<half; i++, cur+=2)
        printf("%d %d ", cur, cur+1);
    printf("%d %d", reserved1, reserved2);
    if(N&1)
        printf(" 999999999");
    printf("\n");

    return 0;
}