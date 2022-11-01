#include <bits/stdc++.h>

using namespace std;

int N, A, B;
char S[1000001];
int modA[1000001];

int fastpow(int b, int e, int m)
{
    int ret=1;
    while(e)
    {
        if(e&1)
            ret=(1LL*ret*b)%m;
        b=(1LL*b*b)%m;
        e/=2;
    }
    return ret;
}

int main()
{
    scanf("%s%d%d", S, &A, &B);
    N=strlen(S);
    modA[0]=(S[0]-'0')%A;
    for(int i=1; i<N; i++)
        modA[i]=(1LL*modA[i-1]*10+S[i]-'0')%A;
    int val=0;
    for(int i=N-1; i>=1; i--)
    {
        val=(val+1LL*(S[i]-'0')*fastpow(10, N-i-1, B))%B;
        if(S[i]!='0' && val==0 && modA[i-1]==0)
        {
            printf("YES\n");
            printf("%.*s\n", i, S);
            printf("%s\n", S+i);
            return 0;
        }
    }
    printf("NO\n");
    return 0;
}