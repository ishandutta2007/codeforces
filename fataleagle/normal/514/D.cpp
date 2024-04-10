#include <bits/stdc++.h>

using namespace std;

struct max_deque
{
    deque<pair<int, int>> dq;
    void append(int x, int i)
    {
        while(!dq.empty() && dq.back().first<=x)
            dq.pop_back();
        dq.push_back(make_pair(x, i));
    }
    void popleft(int i)
    {
        while(!dq.empty() && dq.front().second<=i)
            dq.pop_front();
    }
    int getmax()
    {
        return dq.front().first;
    }
};

int N, M, K;
int A[100000][5];
max_deque mdq[5];
int ans[5];

bool solve(int len)
{
    for(int i=0; i<M; i++)
        mdq[i].popleft(N);
    for(int i=0; i<len; i++)
        for(int j=0; j<M; j++)
            mdq[j].append(A[i][j], i);
    int sum=0;
    for(int i=0; i<M; i++)
        sum+=mdq[i].getmax();
    if(sum<=K)
    {
        for(int j=0; j<M; j++)
            ans[j]=mdq[j].getmax();
        return true;
    }
    for(int i=len; i<N; i++)
    {
        sum=0;
        for(int j=0; j<M; j++)
        {
            mdq[j].append(A[i][j], i);
            mdq[j].popleft(i-len);
            sum+=mdq[j].getmax();
        }
        if(sum<=K)
        {
            for(int j=0; j<M; j++)
                ans[j]=mdq[j].getmax();
            return true;
        }
    }
    return false;
}

int main()
{
    scanf("%d%d%d", &N, &M, &K);
    for(int i=0; i<N; i++)
        for(int j=0; j<M; j++)
            scanf("%d", A[i]+j);
    int lo=0, mid, hi=N;
    while(lo<hi)
    {
        mid=(lo+hi+1)/2;
        if(solve(mid))
            lo=mid;
        else
            hi=mid-1;
    }
    for(int i=0; i<M; i++)
        printf("%d%c", ans[i], " \n"[i==M-1]);
    return 0;
}