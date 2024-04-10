#include <bits/stdc++.h>

using namespace std;

int N;
int A[1001];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
    {
        int a;
        scanf("%d", &a);
        A[a]++;
    }
    for(int i=2; i<=999; i++) if(A[i-1] && A[i] && A[i+1])
        return printf("YES\n"), 0;
    printf("NO\n");
    return 0;
}