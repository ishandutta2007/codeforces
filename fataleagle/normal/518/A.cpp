#include <bits/stdc++.h>

using namespace std;

int N;
char S[500];
char T[500];

int main()
{
    scanf("%s%s", S, T);
    N=strlen(S);
    for(int i=N-1; i>=0; i--)
    {
        if(S[i]!='z')
        {
            S[i]++;
            for(int j=i+1; j<N; j++)
                S[j]='a';
            break;
        }
    }
    if(strcmp(S, T)==0)
        printf("No such string\n");
    else
        printf("%s\n", S);
    return 0;
}