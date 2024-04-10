#include <bits/stdc++.h>

using namespace std;

int N;
int A[51][51];
int ans[51];
bool used[51];

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
        for(int j=1; j<=N; j++)
            scanf("%d", A[i]+j);
    for(int i=1; i<=N; i++)
    {
        int cnt=N-i;
        for(int j=1; j<=N; j++) if(!used[j])
        {
            int num=0;
            for(int k=1; k<=N; k++)
                num+=(A[j][k]==i);
            if(num==cnt)
            {
                used[j]=true;
                ans[j]=i;
                break;
            }
        }
    }
    for(int i=1; i<=N; i++)
        printf("%d ", ans[i]);
    printf("\n");
    return 0;
}