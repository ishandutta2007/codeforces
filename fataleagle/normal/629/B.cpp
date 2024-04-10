#include <bits/stdc++.h>

using namespace std;

int N;
int M[367];
int F[367];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        char ch;
        int a, b;
        scanf(" %c", &ch);
        scanf("%d%d", &a, &b);
        if(ch=='M')
        {
            for(int j=a; j<=b; j++)
                M[j]++;
        }
        else
        {
            for(int j=a; j<=b; j++)
                F[j]++;
        }
    }
    int ans=0;
    for(int i=1; i<=366; i++)
        ans=max(ans, 2*min(M[i], F[i]));
    printf("%d\n", ans);
    return 0;
}