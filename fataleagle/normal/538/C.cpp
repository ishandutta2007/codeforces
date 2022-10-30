#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[100001];
int B[100001];

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<M; i++)
        scanf("%d%d", A+i, B+i);
    int ans=max(B[0]+A[0]-1, N-A[M-1]+B[M-1]);
    for(int i=1; i<M; i++)
    {
        if(abs(B[i-1]-B[i])>abs(A[i-1]-A[i]))
        {
            printf("IMPOSSIBLE\n");
            return 0;
        }
        int lo=A[i-1], mid, hi=A[i];
        int tmp2=max(B[i-1], B[i]);
        if(B[i-1]<B[i])
            lo+=B[i]-B[i-1];
        int tmp=lo;
        while(lo<hi)
        {
            mid=(lo+hi+1)/2;
            if(abs((tmp2+mid-tmp)-B[i])>A[i]-mid)
                hi=mid-1;
            else
                lo=mid;
        }
        ans=max(ans, tmp2+lo-tmp);
    }
    printf("%d\n", ans);
    return 0;
}