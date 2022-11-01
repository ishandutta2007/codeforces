#include <bits/stdc++.h>

using namespace std;

int N, Q;
int A[300001];
int B[300001];
int C[300001];

int main()
{
    scanf("%d%d", &N, &Q);
    vector<int> order;
    int maxi=0, ans=0;
    while(Q--)
    {
        int t;
        scanf("%d", &t);
        if(t==1)
        {
            int x;
            scanf("%d", &x);
            A[x]++;
            order.push_back(x);
            ans++;
        }
        else if(t==2)
        {
            int x;
            scanf("%d", &x);
            ans-=A[x]-max(B[x], C[x]);
            B[x]=A[x];
            ans+=A[x]-max(B[x], C[x]);
        }
        else
        {
            int x;
            scanf("%d", &x);
            for(int i=maxi; i<x; i++)
            {
                ans-=A[order[i]]-max(B[order[i]], C[order[i]]);
                C[order[i]]++;
                ans+=A[order[i]]-max(B[order[i]], C[order[i]]);
            }
            maxi=max(maxi, x);
        }
        printf("%d\n", ans);
    }
    return 0;
}