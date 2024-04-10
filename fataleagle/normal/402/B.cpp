#include <bits/stdc++.h>

using namespace std;

int N, K;
int heights[1001];
int best[2];

void solve(int h)
{
    if(h<=0)
        return;
    int ans=0;
    for(int i=0; i<N; i++)
        if(heights[i]!=h+i*K)
            ans++;
    if(ans<best[0])
        best[0]=ans, best[1]=h;
}

int main()
{
    scanf("%d%d", &N, &K);
    best[0]=0x3f3f3f3f;
    for(int i=0; i<N; i++)
        scanf("%d", heights+i);
    for(int i=0; i<N; i++)
        solve(heights[i]-i*K);
    printf("%d\n", best[0]);
    for(int i=0; i<N; i++)
        if(heights[i]<best[1]+i*K)
        {
            printf("+ %d %d\n", i+1, best[1]+i*K-heights[i]);
        }
        else if(heights[i]>best[1]+i*K)
        {
            printf("- %d %d\n", i+1, heights[i]-(best[1]+i*K));
        }

    return 0;
}