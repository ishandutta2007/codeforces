#include <bits/stdc++.h>

using namespace std;

int N, M;

int main()
{
    scanf("%d%d", &N, &M);
    int lo=0, mid, hi=1000000000;
    while(lo<hi)
    {
        mid=(lo+hi)/2;
        int two=mid/2;
        int three=mid/3;
        int six=mid/6;
        int A=N, B=M;
        A=max(0, A-(two-six));
        B=max(0, B-(three-six));
        if(A+B<=six)
            hi=mid;
        else
            lo=mid+1;
    }
    printf("%d\n", lo);
    return 0;
}