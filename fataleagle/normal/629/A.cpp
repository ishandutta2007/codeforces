#include <bits/stdc++.h>

using namespace std;

int N;
char A[101][101];

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%s", A[i]);
    int ans=0;
    for(int i=0; i<N; i++)
    {
        int cnt1=0, cnt2=0;
        for(int j=0; j<N; j++)
            cnt1+=A[i][j]=='C', cnt2+=A[j][i]=='C';
        ans+=cnt1*(cnt1-1)/2;
        ans+=cnt2*(cnt2-1)/2;
    }
    printf("%d\n", ans);
    return 0;
}