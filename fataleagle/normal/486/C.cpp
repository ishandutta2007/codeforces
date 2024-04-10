#include <bits/stdc++.h>

using namespace std;

int N, P;
char S[100002];

int main()
{
    scanf("%d%d", &N, &P);
    scanf("%s", S+1);
    int ans=0;
    int A=N+1, B=-1, C=N+1, D=-1;
    for(int i=1; i<=N; i++)
    {
        ans+=min(abs(S[i]-S[N-i+1]), 26-abs(S[i]-S[N-i+1]));
        if(S[i]!=S[N-i+1])
        {
            if(i*2<=N)
            {
                A=min(A, i);
                B=max(B, i);
            }
            else
            {
                C=min(C, i);
                D=max(D, i);
            }
        }
    }
    ans/=2;
    if(P*2<=N)
        ans+=min((max(B, P)-P)*2+max(0, P-A), (P-min(A, P))*2+max(0, B-P));
    else
        ans+=min((max(D, P)-P)*2+max(0, P-C), (P-min(C, P))*2+max(0, D-P));
    printf("%d\n", ans);
    return 0;
}