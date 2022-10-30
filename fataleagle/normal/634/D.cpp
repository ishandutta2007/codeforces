#include <bits/stdc++.h>

using namespace std;

int D, N, M;
long long dp[200003];
pair<int, int> A[200003];
int X[200003];
int P[200003];
int R[200003];

int main()
{
    scanf("%d%d%d", &D, &N, &M);
    for(int i=0; i<M; i++)
        scanf("%d%d", &A[i].first, &A[i].second);
    A[M++]=make_pair(0, 0);
    A[M++]=make_pair(D, 0);
    sort(A, A+M);
    for(int i=0; i<M; i++)
        X[i]=A[i].first, P[i]=A[i].second;
    vector<pair<int, int>> S;
    for(int i=M-1; i>=0; i--)
    {
        while(!S.empty() && P[i]<=S.back().first)
            S.pop_back();
        if(S.empty())
            R[i]=-1;
        else
            R[i]=S.back().second;
        S.push_back(make_pair(P[i], i));
    }
    int pos=0, gas=0;
    long long ans=0;
    while(pos<M)
    {
        if(R[pos]==-1 || X[R[pos]]-X[pos]>N)
        {
            ans+=1LL*(N-gas)*P[pos];
            gas=N-(X[pos+1]-X[pos]);
            pos++;
            if(gas<0)
                return printf("-1\n"), 0;
        }
        else
        {
            int fillup=max(0, (X[R[pos]]-X[pos])-gas);
            ans+=1LL*fillup*P[pos];
            gas=gas+fillup-(X[R[pos]]-X[pos]);
            pos=R[pos];
        }
    }
    printf("%lld\n", ans);
    return 0;
}