#include <bits/stdc++.h>

using namespace std;

int N;
pair<int, int> A[100000];
priority_queue<int> pq;

int main()
{
    int sum=0;
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d", &A[i].first);
    for(int i=0; i<N; i++)
        scanf("%d", &A[i].second), sum+=A[i].second;
    sort(A, A+N);
    int keep=0;
    for(int i=0, j; i<N; i=j)
    {
        for(j=i; j<N && A[i].first==A[j].first; j++);
        int n=0, tot=0;
        vector<int> v;
        for(int k=j-1; k>=i; k--)
        {
            tot+=A[k].second;
            n++;
            if(!pq.empty() && n>1)
            {
                int x=pq.top();
                tot+=x;
                v.push_back(x);
                pq.pop();
            }
            keep=max(keep, tot);
        }
        for(auto& it: v)
            pq.push(it);
        for(int k=i; k<j; k++)
            pq.push(A[k].second);
    }
    printf("%d\n", sum-keep);
    return 0;
}