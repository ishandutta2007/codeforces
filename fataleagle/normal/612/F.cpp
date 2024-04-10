#include <bits/stdc++.h>

using namespace std;

int N, S;
int A[2001], X[2001];
int dp[2001][2001][2];
vector<int> pos[2002];
int idx[2001];
vector<int> ans;

int find_prev(int x, int p)
{
    int i=idx[p];
    i--;
    if(i<0)
        i+=pos[x].size();
    return pos[x][i];
}

int find_next(int x, int p)
{
    int i=idx[p];
    i++;
    if(i>=(int)pos[x].size())
        i-=pos[x].size();
    return pos[x][i];
}

int cdist(int a, int b)
{
    return min(abs(a-b), N-abs(a-b));
}

int solve(int l, int r, int s)
{
    int& ret=dp[l][r][s];
    if(ret!=-1)
        return ret;
    int cur=A[l];
    int loc=s?r:l;
    int lpos=find_prev(cur, l);
    int rpos=find_next(cur, r);
    if(l<=rpos && (r<l || rpos<=r) && lpos<=r && (l>r || l<=lpos))
    {
        if(pos[cur+1].empty())
            return ret=0;
        ret=0x3f3f3f3f;
        for(auto& it: pos[cur+1])
            ret=min(ret, solve(it, it, 0)+cdist(loc, it));
        return ret;
    }
    return ret=min(solve(lpos, r, 0)+cdist(lpos, loc),
                   solve(l, rpos, 1)+cdist(loc, rpos));
}

void trace(int l, int r, int s)
{
    int ret=dp[l][r][s];
    int cur=A[l];
    int loc=s?r:l;
    ans.push_back(loc);
    int lpos=find_prev(cur, l);
    int rpos=find_next(cur, r);
    if(l<=rpos && (r<l || rpos<=r) && lpos<=r && (l>r || l<=lpos))
    {
        if(pos[cur+1].empty())
            return;
        for(auto& it: pos[cur+1])
            if(solve(it, it, 0)+cdist(loc, it)==ret)
            {
                trace(it, it, 0);
                return;
            }
    }
    if(solve(lpos, r, 0)+cdist(lpos, loc)==ret)
        trace(lpos, r, 0);
    else
        trace(l, rpos, 1);
}

int main()
{
    memset(dp, -1, sizeof dp);
    scanf("%d%d", &N, &S);
    for(int i=1; i<=N; i++)
        scanf("%d", A+i), X[i]=A[i];
    sort(X+1, X+1+N);
    int NX=unique(X+1, X+1+N)-X-1;
    for(int i=1; i<=N; i++)
        A[i]=lower_bound(X+1, X+1+NX, A[i])-X;
    for(int i=1; i<=N; i++)
    {
        idx[i]=pos[A[i]].size();
        pos[A[i]].push_back(i);
    }
    int rans=0x3f3f3f3f;
    for(auto& it: pos[1])
        rans=min(rans, solve(it, it, 0)+cdist(S, it));
    ans.push_back(S);
    for(auto& it: pos[1])
        if(solve(it, it, 0)+cdist(S, it)==rans)
        {
            trace(it, it, 0);
            break;
        }
    printf("%d\n", rans);
    for(int i=0; i<N; i++)
    {
        int x=ans[i], y=ans[i+1];
        int dneg=x-y;
        if(dneg<0)
            dneg+=N;
        int dpos=y-x;
        if(dpos<0)
            dpos+=N;
        if(dneg<dpos)
            printf("-%d\n", dneg);
        else
            printf("+%d\n", dpos);
    }
    return 0;
}