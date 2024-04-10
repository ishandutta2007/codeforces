#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;
int N, M;
vector<int> place[100001];
vector<int> var[100001];
int neg[100001];
bool seen[100001];
bool seen2[100001];

void addmod(int& x, int v)
{
    x+=v;
    if(x>=MOD)
        x-=MOD;
}

int dfs(int u, int p, vector<int>& o)
{
    seen[u]=true;
    int v=-1;
    for(auto& it: var[p]) if(abs(it)!=u && !seen[abs(it)])
        v=abs(it);
    if(v==-1)
        return -1;
    seen[v]=true;
    int w=-1;
    for(auto& it: place[v]) if(it!=p)
        w=it;
    if(w==-1)
        return v;
    o.push_back(neg[v]);
    return dfs(v, w, o);
}

int dp[100005][2][2];

pair<int, int> do_dp(vector<int>& v, int first, int last)
{
    for(int x=0; x<=1; x++)
        for(int y=0; y<=1; y++)
            dp[0][x][y]=0;
    dp[0][first][0]=1;
    for(int i=0; i<(int)v.size(); i++)
    {
        for(int x=0; x<=1; x++)
            for(int y=0; y<=1; y++)
                dp[i+1][x][y]=0;
        for(int x=0; x<=1; x++)
            for(int y=0; y<=1; y++)
                for(int z=0; z<=1; z++)
                    addmod(dp[i+1][z^v[i]][y^(x|z)], dp[i][x][y]);
    }
    int ret[2]={0, 0};
    for(int x=0; x<=1; x++)
        for(int y=0; y<=1; y++)
            for(int z=last; z<=last; z++)
                addmod(ret[y^(x|z)], dp[v.size()][x][y]);
    return make_pair(ret[0], ret[1]);
}

pair<int, int> get_line(vector<int>& v, int mi=1, int mj=1)
{
    int a=0, b=0;
    int x, y;
    for(int i=0; i<=mi; i++) for(int j=0; j<=mj; j++)
    {
        tie(x, y)=do_dp(v, i, j);
        addmod(a, x);
        addmod(b, y);
    }
    return make_pair(a, b);
}

pair<int, int> get_circle(int t, vector<int>& v)
{
    int a=0, b=0;
    int x, y;
    for(int i=0; i<=1; i++)
    {
        tie(x, y)=do_dp(v, i, i^t);
        addmod(a, x);
        addmod(b, y);
    }
    return make_pair(a, b);
}

int dp2[100005][2];

int main()
{
    scanf("%d%d", &M, &N);
    for(int i=1; i<=M; i++)
    {
        int n;
        scanf("%d", &n);
        while(n--)
        {
            int x;
            scanf("%d", &x);
            place[abs(x)].push_back(i);
            if(x<0)
                neg[abs(x)]^=1;
            var[i].push_back(x);
        }
    }
    vector<pair<int, int>> terms;
    for(int i=1; i<=M; i++) if(var[i].size()==1 && !seen[abs(var[i][0])])
    {
        int x=abs(var[i][0]);
        if(place[x].size()==1)
        {
            seen[x]=true;
            terms.push_back({1, 1});
            continue;
        }
        if(place[x].size()==2 && place[x][0]==place[x][1])
        {
            seen[x]=true;
            if(neg[x])
                terms.push_back({0, 2});
            else
                terms.push_back({1, 1});
            continue;
        }
        int o=-1;
        for(auto& it: place[x]) if(it!=i)
            o=it;
        vector<int> v;
        v.push_back(neg[x]);
        int y=dfs(x, o, v);
        if(y==-1)
            terms.push_back(get_line(v, 0, 0));
        else
            terms.push_back(get_line(v, 0, 1));
    }
    for(int i=1; i<=N; i++) if(!seen[i] && place[i].size()==0)
    {
        seen[i]=true;
        terms.push_back({2, 0});
    }
    for(int i=1; i<=N; i++) if(!seen[i] && place[i].size()==1)
    {
        vector<int> v;
        dfs(i, place[i][0], v);
        auto p=get_line(v);
        terms.push_back(p);
    }
    for(int i=1; i<=N; i++) if(!seen[i] && place[i].size()==2)
    {
        vector<int> v;
        if(place[i][0]==place[i][1])
        {
            seen[i]=true;
            if(neg[i])
                terms.push_back({0, 2});
            else
                terms.push_back({1, 1});
            continue;
        }
        if(var[place[i][0]].size()==1)
            dfs(i, place[i][0], v);
        else
            dfs(i, place[i][1], v);
        auto p=get_circle(neg[i], v);
        terms.push_back(p);
    }
    dp2[0][0]=terms[0].first;
    dp2[0][1]=terms[0].second;
    for(int i=1; i<(int)terms.size(); i++)
    {
        addmod(dp2[i][0], 1LL*dp2[i-1][0]*terms[i].first%MOD);
        addmod(dp2[i][1], 1LL*dp2[i-1][1]*terms[i].first%MOD);
        addmod(dp2[i][0], 1LL*dp2[i-1][1]*terms[i].second%MOD);
        addmod(dp2[i][1], 1LL*dp2[i-1][0]*terms[i].second%MOD);
    }
    printf("%d\n", dp2[terms.size()-1][1]);
    return 0;
}