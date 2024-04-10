#include <bits/stdc++.h>

using namespace std;

int N, L;
int A[1002];

int main()
{
    scanf("%d%d", &N, &L);
    for(int i=0; i<N; i++)
        scanf("%d", A+i);
    sort(A, A+N);
    int ans=0;
    for(int i=1; i<N; i++)
        ans=max(ans, A[i]-A[i-1]);
    ans=max(ans, A[0]*2);
    ans=max(ans, (L-A[N-1])*2);
    cout<<fixed<<setprecision(10)<<(ans/2.0L)<<endl;
    return 0;
}