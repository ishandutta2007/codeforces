#include <bits/stdc++.h>

using namespace std;

int N, Q;
int A[100];

int main()
{
    scanf("%d%d", &N, &Q);
    for(int i=0; i<Q; i++)
    {
        int t, k, d;
        scanf("%d%d%d", &t, &k, &d);
        int cnt=0;
        for(int i=0; i<N; i++) if(A[i]<=t)
            cnt++;
        if(cnt<k)
            printf("-1\n");
        else
        {
            int ans=0;
            for(int i=0; i<N && k; i++) if(A[i]<=t)
                A[i]=t+d, k--, ans+=i+1;
            printf("%d\n", ans);
        }
    }
    return 0;
}