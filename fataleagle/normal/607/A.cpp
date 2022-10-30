#include <bits/stdc++.h>

using namespace std;

int N;
int len[100001];
int A[100001];
int B[100001];
pair<int, int> C[100001];

int main()
{
    scanf("%d", &N);
    int ans=0;
    for(int i=0; i<N; i++)
        scanf("%d%d", A+i, B+i), C[i]=make_pair(A[i], B[i]);
    sort(C, C+N);
    for(int i=0; i<N; i++)
        A[i]=C[i].first, B[i]=C[i].second;
    for(int i=0; i<N; i++)
    {
        int idx=lower_bound(A, A+i, A[i]-B[i])-A-1;
        if(idx==-1)
            len[i]=1;
        else
            len[i]=len[idx]+1;
        ans=max(ans, len[i]);
    }
    printf("%d\n", N-ans);
    return 0;
}