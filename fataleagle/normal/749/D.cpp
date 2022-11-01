#include <bits/stdc++.h>

using namespace std;

int N, Q;
int A[200000];
int B[200000];
vector<int> pos[200001];

int cnt(int x, int p)
{
    return pos[x].end()-lower_bound(pos[x].begin(), pos[x].end(), p);
}

int get(vector<int>& V)
{
    int lo=0, mid, hi=N;
    while(lo<hi)
    {
        mid=(lo+hi)/2;
        int sum=0;
        for(auto& it: V)
            sum+=cnt(it, mid);
        if(sum==N-mid)
            hi=mid;
        else
            lo=mid+1;
    }
    return lo;
}

int get2(int x, vector<int>& V)
{
    int p=get(V);
    return *lower_bound(pos[x].begin(), pos[x].end(), p);
}

int main()
{
    scanf("%d", &N);
    for(int i=0; i<N; i++)
        scanf("%d%d", A+i, B+i), pos[A[i]].push_back(i);
    scanf("%d", &Q);
    while(Q--)
    {
        int K;
        scanf("%d", &K);
        vector<int> V(K);
        for(int i=0; i<K; i++)
            scanf("%d", &V[i]);
        int idx=get(V);
        if(idx==0)
            printf("0 0\n");
        else
        {
            V.push_back(A[idx-1]);
            printf("%d %d\n", A[idx-1], B[get2(A[idx-1], V)]);
        }
    }
    return 0;
}