#include <bits/stdc++.h>

using namespace std;

char S[501];

int main()
{
    scanf("%s", S);
    int N=strlen(S);
    char nxt='a';
    for(int i=0; i<N; i++)
    {
        if(S[i]<=nxt)
        {
            if(S[i]==nxt)
                nxt++;
        }
        else
            return 0*printf("NO\n");
    }
    printf("YES\n");
	return 0;
}