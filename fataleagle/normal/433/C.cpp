#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[100001];
vector<int> val[100001];
long long orig;

int main()
{
    scanf("%d%d", &N, &M);
    for(int i=0; i<M; i++)
        scanf("%d", A+i);
    for(int i=1; i<M; i++)
        orig+=abs(A[i-1]-A[i]);
    for(int i=0; i<M; i++)
    {
        if(i>0 && A[i-1]-A[i])
            val[A[i]].push_back(A[i-1]-A[i]);
        if(i+1<M && A[i+1]-A[i])
            val[A[i]].push_back(A[i+1]-A[i]);
    }
    long long ans=orig;
    for(int i=1; i<=N; i++)
    {
        if(val[i].empty())
            continue;
        sort(val[i].begin(), val[i].end());
        int mid=val[i][val[i].size()/2];
        long long presum=0, postsum=0;
        for(size_t j=0; j<val[i].size(); j++)
        {
            presum+=abs(val[i][j]);
            postsum+=abs(val[i][j]-mid);
        }
        ans=min(ans, orig-(presum-postsum));
    }
    printf("%lld\n", ans);
    return 0;
}