#include<bits/stdc++.h>
#define maxn 8000000

using namespace std;
typedef long long ll;
int to[maxn][2],sz[maxn],n,k,p,t;
ll ans;
bool f;
vector <int> h[maxn];

int cnt(ll x,ll y,ll z)
{
    f=y&z;
    if (z==0) return 0;
    if (to[x][f]) return cnt(to[x][f],y,z/2); else return z+cnt(to[x][!f],y,z/2);
}

ll solve(ll x,ll y)
{
    int u=to[x][0],v=to[x][1];
    if (u) solve(u,y/2);
    if (v) solve(v,y/2);
    if (u&&v){
        ans+=y; t=y-1;
        if (h[u].size()>h[v].size()) swap(u,v);
        for (int i=0;i<h[u].size();i++) t=min(t,cnt(v,h[u][i],y/2));
        ans+=t;
    }
}

int main()
{
    scanf("%d",&n);
    while (n--){
        scanf("%d",&k); t=0;
        for (int i=29;i>=0;i--)
        {
            f=k&(1<<i);
            if (!to[t][f]) to[t][f]=++p;
            t=to[t][f]; h[t].push_back(k);
        }
    }
    solve(0,1<<29);
    cout << ans << endl;
}