#include <bits/stdc++.h>

using namespace std;

struct query
{
    int op, t, i;
};

int N;
map<int, vector<query>> tracks;
int ans[1000000];
int bit[1000001];

void add(int x, int v)
{
    for(; x<=1000000; x+=x&-x)
        bit[x]+=v;
}

int sum(int x)
{
    int ret=0;
    for(; x>0; x-=x&-x)
        ret+=bit[x];
    return ret;
}

void solve(vector<query>& v)
{
    int n=v.size();
    vector<int> X;
    for(int i=0; i<n; i++)
        X.push_back(v[i].t);
    sort(X.begin(), X.end());
    for(int i=0; i<n; i++)
    {
        int t=lower_bound(X.begin(), X.end(), v[i].t)-X.begin()+1;
        if(v[i].op==1)
        {
            add(t, 1);
        }
        else if(v[i].op==2)
        {
            add(t, -1);
        }
        else
        {
            ans[v[i].i]=sum(t);
        }
    }
    for(int i=0; i<n; i++) if(v[i].op!=3)
    {
        int t=lower_bound(X.begin(), X.end(), v[i].t)-X.begin()+1;
        if(v[i].op==1)
        {
            add(t, -1);
        }
        else if(v[i].op==2)
        {
            add(t, 1);
        }
    }
}

int main()
{
    memset(ans, -1, sizeof ans);
    scanf("%d", &N);
    int a, b, c;
    for(int i=0; i<N; i++)
    {
        scanf("%d%d%d", &a, &b, &c);
        tracks[c].push_back((query){a, b, i});
    }
    for(auto& it: tracks)
    {
        auto& v=it.second;
        solve(v);
    }
    for(int i=0; i<N; i++) if(ans[i]!=-1)
        printf("%d\n", ans[i]);
    return 0;
}