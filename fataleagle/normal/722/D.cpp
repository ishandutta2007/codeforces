#include <bits/stdc++.h>

using namespace std;

int N, n;
int A[50000];
int trie[50000*35][2];
bool leaf[50000*35];
vector<int> v;

int dfs(int u, int lim, int x)
{
    int sum=leaf[u];
    for(int i=0; i<2; i++) if(trie[u][i])
        sum+=dfs(trie[u][i], lim, x*2+i);
    if(x>=1 && x<=lim && sum>0)
        sum--, v.push_back(x);
    return sum;
}

int main()
{
    scanf("%d", &N);
    n=1;
    for(int i=0; i<N; i++)
    {
        scanf("%d", A+i);
        int cur=1;
        for(int j=30; j>=0; j--) if(A[i]>>j)
        {
            int b=(A[i]>>j)&1;
            if(!trie[cur][b])
                trie[cur][b]=++n;
            cur=trie[cur][b];
        }
        leaf[cur]=true;
    }
    int lo=1, mid, hi=1000000000;
    while(lo<hi)
    {
        v.clear();
        mid=(lo+hi)/2;
        if(dfs(1, mid, 0)==0)
            hi=mid;
        else
            lo=mid+1;
    }
    v.clear();
    dfs(1, lo, 0);
    for(auto& it: v)
        printf("%d ", it);
    printf("\n");
    return 0;
}