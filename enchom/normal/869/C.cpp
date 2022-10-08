#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long Int;

Int F[5011][5011];
const Int MOD=998244353LL;

Int Solve(int A,int B)
{
    if (A>B)
    return Solve(B,A);

    if (A==0 || B==0)
    return 1LL;

    if (F[A][B]!=0)
    return F[A][B];

    F[A][B]=Solve(A-1,B)+Solve(A-1,B-1)*(Int)B;
    if (F[A][B]>=MOD)
    F[A][B]%=MOD;

    return F[A][B];
}
int main()
{
    int a,b,c;

    scanf("%d %d %d",&a,&b,&c);

    printf("%lld\n",( ( ( Solve(a,b)*Solve(b,c) )%MOD )*Solve(a,c) ) %MOD );
    return 0;
}