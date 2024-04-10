#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[100001];
int X[100001];
int Y[100001];
map<int, int> S;

int main()
{
    scanf("%d", &N);
    for(int i=1; i<=N; i++)
    {
        scanf("%d", A+i);
        if(i==A[i])
        {
            X[i]=++M;
            Y[M]=i;
            S[A[i]]=M;
        }
    }
    for(int i=1; i<=N; i++)
    {
        if(S.count(A[i]))
            X[i]=S[A[i]];
        else
            return 0*printf("-1\n");
    }
    for(int i=1; i<=N; i++)
        if(Y[X[i]]!=A[i])
            return 0*printf("-1\n");
    for(int i=1; i<=M; i++)
        if(X[Y[i]]!=i)
            return 0*printf("-1\n");
    printf("%d\n", M);
    for(int i=1; i<=N; i++)
        printf("%d%c", X[i], " \n"[i==N]);
    for(int i=1; i<=M; i++)
        printf("%d%c", Y[i], " \n"[i==M]);
	return 0;
}