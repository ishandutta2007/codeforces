#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[100001];

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<N; i++)
        scanf("%d", A+i);
    sort(A, A+N);
    long long ans=0;
    for(int i=0; i<N; i++)
    {
        ans+=((long long)M)*A[i];
        M=max(1, M-1);
    }
    cout<<ans<<endl;
    return 0;
}