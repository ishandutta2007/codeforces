#include <bits/stdc++.h>

using namespace std;

int N, K, Q;
int A[5001];
unordered_set<int> denoms;

int main()
{
    scanf("%d%d", &N, &K);
    for(int i=0; i<N; i++)
        scanf("%d", A+i), denoms.insert(A[i]);
    scanf("%d", &Q);
    int x;
    while(Q--)
    {
        scanf("%d", &x);
        int ans=K+1;
        for(int i=0; i<N; i++)
            for(int j=1; j<=K; j++)
                for(int k=1; k<=j; k++)
                    if(x-k*A[i]>=0 && (x==k*A[i] || (j-k!=0 && (x-k*A[i])%(j-k)==0 && denoms.count((x-k*A[i])/(j-k)))))
                        ans=min(ans, j);
        if(ans>K)
            printf("-1\n");
        else
            printf("%d\n", ans);
    }
    return 0;
}