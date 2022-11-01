#include <bits/stdc++.h>

using namespace std;

int N, T, R;
int W[300];
bool candle[701];

int main()
{
    scanf("%d%d%d", &N, &T, &R); // NTR!
    for(int i=0; i<N; i++)
        scanf("%d", W+i), W[i]+=305;
    for(int i=0; i<N; i++)
    {
        int pre=-1;
loop:;
        int cnt=0;
        for(int j=max(W[i]-T+1, 0); j<=W[i]; j++)
            cnt+=candle[j];
        if(cnt<R)
        {
            if(pre==cnt)
            {
                printf("-1\n");
                return 0;
            }
            for(int j=W[i]; j>=0; j--)
                if(!candle[j])
                {
                    candle[j]=true;
                    break;
                }
            pre=cnt;
            goto loop;
        }
    }
    printf("%d\n", count(candle, candle+701, true));
    return 0;
}