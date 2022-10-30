#include <bits/stdc++.h>

using namespace std;

int N;
int A[100000];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", A+i);
    for(int i=0; i<N; i++)
    {
        int mini=2147483647;
        if(i>0)
            mini=min(mini, abs(A[i]-A[i-1]));
        if(i+1<N)
            mini=min(mini, abs(A[i]-A[i+1]));
        int maxi=max(abs(A[i]-A[0]), abs(A[i]-A[N-1]));
        printf("%d %d\n", mini, maxi);
    }
    return 0;
}