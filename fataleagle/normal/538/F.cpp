#include <bits/stdc++.h>

using namespace std;

int N;
int A[200001];
int ans[200002];

int main()
{
    // p(v) = (v - 1) // k
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", A+i);
    for(int i=0; i<N-1; i++)
    {
        int idx=0;
        while(idx<i)
        {
            int nidx=i/(i/(idx+1));
            int p=i/nidx;
            if(A[i+1]<A[p])
                ans[idx+1]++, ans[nidx+1]--;
            idx=nidx;
        }
        if(A[i+1]<A[0])
            ans[i+1]++;
    }
    int sum=0;
    for(int i=1; i<N; i++)
    {
        sum+=ans[i];
        printf("%d ", sum);
    }
    printf("\n");
    return 0;
}