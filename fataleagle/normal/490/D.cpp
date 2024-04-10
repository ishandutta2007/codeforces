#include <bits/stdc++.h>

using namespace std;

long long S1, S2;
int A1, B1, A2, B2;
int F21, F22, F31, F32;
int R21, R22, R31, R32;

int main()
{
    scanf("%d%d%d%d", &A1, &B1, &A2, &B2);
    S1=1LL*A1*B1;
    S2=1LL*A2*B2;
    while(S1%2==0)
        F21++, S1/=2;
    while(S1%3==0)
        F31++, S1/=3;
    while(S2%2==0)
        F22++, S2/=2;
    while(S2%3==0)
        F32++, S2/=3;
    if(S1!=S2)
    {
        printf("-1\n");
        return 0;
    }
    while(F31>F32)
        F31--, R31++, F21++;
    while(F32>F31)
        F32--, R32++, F22++;
    while(F21>F22)
        F21--, R21++;
    while(F22>F21)
        F22--, R22++;
    printf("%d\n", R21+R31+R22+R32);
    while(R31 && A1%3==0)
        R31--, A1/=3, A1*=2;
    while(R31 && B1%3==0)
        R31--, B1/=3, B1*=2;
    while(R21 && A1%2==0)
        R21--, A1/=2;
    while(R21 && B1%2==0)
        R21--, B1/=2;
    while(R32 && A2%3==0)
        R32--, A2/=3, A2*=2;
    while(R32 && B2%3==0)
        R32--, B2/=3, B2*=2;
    while(R22 && A2%2==0)
        R22--, A2/=2;
    while(R22 && B2%2==0)
        R22--, B2/=2;
    printf("%d %d\n%d %d\n", A1, B1, A2, B2);
    return 0;
}