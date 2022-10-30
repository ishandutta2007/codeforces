#include <bits/stdc++.h>

using namespace std;

int N;
char S[201];

int main()
{
    scanf("%d", &N);
    scanf("%s", S);
    int ans=0;
    for(int i=0; i<N; i++) for(int j=i; j<N; j++)
    {
        int x=0, y=0;
        for(int k=i; k<=j; k++)
        {
            x+=(S[k]=='L')-(S[k]=='R');
            y+=(S[k]=='U')-(S[k]=='D');
        }
        if(x==0 && y==0)
            ans++;
    }
    printf("%d\n", ans);
    return 0;
}