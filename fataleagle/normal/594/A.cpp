#include <bits/stdc++.h>

using namespace std;

int N;
int A[200000];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", A+i);
    sort(A, A+N);
    int offs=(N-2)/2;
    int ans=0x3f3f3f3f;
    for(int i=offs+1; i<N; i++)
        ans=min(ans, A[i]-A[i-offs-1]);
    printf("%d\n", ans);
    return 0;
}