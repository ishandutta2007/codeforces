#include <bits/stdc++.h>

using namespace std;

int M;
int H1, A1, X1, Y1;
int H2, A2, X2, Y2;

int main()
{
    scanf("%d", &M);
    scanf("%d%d%d%d", &H1, &A1, &X1, &Y1);
    scanf("%d%d%d%d", &H2, &A2, &X2, &Y2);
    int i;
    for(i=1; i<=M; i++)
    {
        H1=(1LL*H1*X1+Y1)%M;
        if(H1==A1)
            break;
    }
    if(i==M+1)
        return printf("-1\n"), 0;
    for(int j=0; j<i; j++)
        H2=(1LL*H2*X2+Y2)%M;
    if(H2==A2)
        return printf("%d\n", i), 0;
    int X3=1, Y3=0;
    int j;
    for(j=1; j<=M; j++)
    {
        H1=(1LL*H1*X1+Y1)%M;
        int X4=1LL*X2*X3%M, Y4=(1LL*X2*Y3+Y2)%M;
        X3=X4;
        Y3=Y4;
        if(H1==A1)
            break;
    }
    if(j==M+1)
        return printf("-1\n"), 0;
    int k;
    for(k=1; k<=M; k++)
    {
        H2=(1LL*H2*X3+Y3)%M;
        if(H2==A2)
            return printf("%lld\n", i+1LL*j*k), 0;
    }
    printf("-1\n");
    return 0;
}