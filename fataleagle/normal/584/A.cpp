#include <bits/stdc++.h>

using namespace std;

int N;
char T[101];

int main()
{
    scanf("%d%s", &N, T);
    int M=strlen(T);
    while(M<N)
        T[M++]='0';
    if(M==N)
        printf("%s\n", T);
    else
        printf("-1\n");
    return 0;
}