#include <bits/stdc++.h>

using namespace std;

int N;
char S[100001];

int main()
{
    scanf("%s", S);
    N=strlen(S);
    int first=-1;
    for(int i=0; i<N; i++) if(S[i]!='a')
    {
        first=i;
        break;
    }
    if(first==-1)
    {
        S[N-1]='z';
        puts(S);
        return 0;
    }
    int last=-1;
    for(int i=first; i<N; i++)
    {
        if(S[i]=='a')
            break;
        last=i;
    }
    for(int i=first; i<=last; i++)
        S[i]--;
    puts(S);
    return 0;
}