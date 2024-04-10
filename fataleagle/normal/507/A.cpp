#include <bits/stdc++.h>

using namespace std;

int N, K;
pair<int, int> A[100];

int main()
{
    scanf("%d%d", &N, &K);
    for(int i=0; i<N; i++)
        scanf("%d", &A[i].first), A[i].second=i;
    sort(A, A+N);
    vector<int> ans;
    for(int i=0; i<N; i++)
        if(K>=A[i].first)
            ans.push_back(A[i].second), K-=A[i].first;
    printf("%d\n", ans.size());
    for(auto& it: ans)
        printf("%d ", it+1);
    printf("\n");
    return 0;
}