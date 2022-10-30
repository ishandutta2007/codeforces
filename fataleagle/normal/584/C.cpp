#include <bits/stdc++.h>

using namespace std;

int N, T;
char A[100001];
char B[100001];
char C[100001];
bool c[100001];

char exclude(char a, char b)
{
    for(char c='a'; c<='z'; c++) if(c!=a && c!=b)
        return c;
    __builtin_unreachable();
}

int main()
{
    scanf("%d%d", &N, &T);
    T=N-T;
    scanf("%s%s", A, B);
    strcpy(C, A);
    int change=N-T;
    int match=0;
    for(int i=0; i<N; i++)
        if(C[i]==B[i])
            match++;
    for(int i=0; i<N && match>T; i++)
        if(C[i]==B[i])
            C[i]=exclude(A[i], B[i]), change--, match--, c[i]=1;
    for(int i=0; i<N && match<T; i++)
        if(C[i]!=B[i] && !c[i])
            C[i]=B[i], change--, match++, c[i]=1;
    for(int i=0; i<N && change>0; i++)
        if(C[i]!=B[i] && !c[i])
            C[i]=exclude(A[i], B[i]), change--;
    if(change==0 && match==T)
        puts(C);
    else
        printf("-1\n");
    return 0;
}