#include <bits/stdc++.h>

using namespace std;

int N, K;

int main()
{
    scanf("%d%d", &N, &K);
    printf("%d\n", K*(6*N-1));
    for(int i=0; i<N; i++)
        printf("%d %d %d %d\n", K*(i*6+1), K*(i*6+2), K*(i*6+3), K*(i*6+5));
    return 0;
}