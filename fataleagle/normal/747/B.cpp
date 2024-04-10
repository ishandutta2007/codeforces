#include <bits/stdc++.h>

using namespace std;

int N;
char S[256];

int main()
{
    scanf("%d", &N);
    scanf("%s", S);
    if(N%4!=0)
    {
        printf("===\n");
        return 0;
    }
    string s;
    int X=N/4;
    for(auto c: "ACGT")
    {
        if(count(S, S+N, c)>X)
        {
            printf("===\n");
            return 0;
        }
        int n=X-count(S, S+N, c);
        while(n--)
            s+=c;
    }
    int k=0;
    for(int i=0; i<N; i++) if(S[i]=='?')
        S[i]=s[k++];
    puts(S);
    return 0;
}