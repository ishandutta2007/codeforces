#include <bits/stdc++.h>

using namespace std;

int N, P, Q;
char S[101];

int main()
{
    scanf("%d%d%d", &N, &P, &Q);
    scanf("%s", S);
    for(int i=0; i*P<=N; i++) if((N-i*P)%Q==0)
    {
        printf("%d\n", i+(N-i*P)/Q);
        for(int j=0; j<i; j++)
            printf("%.*s\n", P, S+j*P);
        for(int j=0; j<(N-i*P)/Q; j++)
            printf("%.*s\n", Q, S+i*P+j*Q);
        return 0;
    }
    printf("-1\n");
    return 0;
}