#include <bits/stdc++.h>

using namespace std;

int N;
char S[200005];
int A[200005];

int main()
{
    scanf("%s", S+1);
    int M=strlen(S+1);
    scanf("%d", &N);
    int a;
    for(int i=0; i<N; i++)
    {
        scanf("%d", &a);
        A[a]++;
        A[M-a+2]--;
    }
    int sum=0;
    for(int i=1; i<=M; i++)
    {
        sum+=A[i];
        if(sum&1)
            putchar(S[M-i+1]);
        else
            putchar(S[i]);
    }
    putchar('\n');
    return 0;
}