#include <bits/stdc++.h>

using namespace std;

int N, A, B;
int ans[100][100];

int main()
{
    scanf("%d%d%d", &N, &A, &B);
    int odd=1, even=2;
    for(int i=0; i<A; i++)
        for(int j=0; j<B; j++)
            if((i+j)%2==0 && odd<=N)
                ans[i][j]=odd, odd+=2;
            else if((i+j)%2==1 && even<=N)
                ans[i][j]=even, even+=2;
    if(odd>N && even>N)
    {
        for(int i=0; i<A; i++)
            for(int j=0; j<B; j++)
                printf("%d%c", ans[i][j], " \n"[j==B-1]);
        return 0;
    }
    memset(ans, 0, sizeof ans);
    odd=1, even=2;
    for(int i=0; i<A; i++)
        for(int j=0; j<B; j++)
            if((i+j)%2==1 && odd<=N)
                ans[i][j]=odd, odd+=2;
            else if((i+j)%2==0 && even<=N)
                ans[i][j]=even, even+=2;
    if(odd>N && even>N)
    {
        for(int i=0; i<A; i++)
            for(int j=0; j<B; j++)
                printf("%d%c", ans[i][j], " \n"[j==B-1]);
        return 0;
    }
    printf("-1\n");
    return 0;
}