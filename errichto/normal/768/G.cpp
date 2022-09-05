// organizers code

#include <bits/stdc++.h>
using namespace std;

const int N = 100005;
vector<int> adj[N];
int sz[N], ans[N];
int n, root;
bool big[N];
map<int,int> mp, mpo, par;

void getsz(int s){
    sz[s] = 1;
    ans[s] = n - 1;
    for(auto it : adj[s]){
        getsz(it);
        sz[s] += sz[it];
    }
    mpo[sz[s]]++;
}

void bs(map<int, int> &mp1, int l, int r, int mi, int s, int off){
    if(mi == n - 1) return;
    int ma = r;
    while(r - l > 1){
        int mid = (r + l) / 2;
        auto it = mp1.lower_bound(ma - mid + off);
        if(it == mp1.end()) 
            l = mid;
        else if(mi + it->first <= mid + off) 
            r = mid;
        else 
            l = mid;
    }
    ans[s] = min(ans[s], r);
}

void add(int s){
    mp[sz[s]]++;
    if(mpo[sz[s]] == 1)
        mpo.erase(sz[s]);
    else
        mpo[sz[s]]--;
    for(auto it:adj[s])
        if(!big[it]) add(it);
}

void rem(int s){
    mpo[sz[s]]++;
    if(mp[sz[s]] == 1)
        mp.erase(sz[s]);
    else
        mp[sz[s]]--;
    for(auto it:adj[s])
        if(!big[it]) rem(it);
}

void dfs(int s, bool isbig){
    par[sz[s]]++;
    if(mpo[sz[s]] == 1)
        mpo.erase(sz[s]);
    else
        mpo[sz[s]]--;
    int ma = -1, sma = -1, mac = -1, mi = n - 1;
    for(auto it:adj[s]){
        if(sz[it]>ma){
            sma = ma;
            ma = sz[it];
            mac = it;
        }
        else if(sz[it]==ma)
            sma = ma;
        else
            sma = max(sma,sz[it]);
        mi = min(mi,sz[it]);
    }
    if(s != root)
        mi = min(mi,n-sz[s]);
    for(auto it:adj[s]){
        if(it!=mac)
            dfs(it,0);
    }
    if(mac != -1){
        big[mac]=true;
        dfs(mac,1);
    }
    if(ma >= n - sz[s]){
        sma = max(sma, n - sz[s]);
        bs(mp, sma - 1, ma, mi, s, 0);
    }
    mpo[sz[s]]++;
    add(s);
    if(par[sz[s]] == 1)
        par.erase(sz[s]);
    else
        par[sz[s]]--;
    if(n-sz[s] > ma){
        sma = ma;
        bs(mpo, sma - 1, n - sz[s], mi, s, 0);
        bs(par, sma - 1, n - sz[s], mi, s, sz[s]);
    }
    if(mac != -1)
        big[mac] = false;
    if(!isbig) rem(s);
}

int main(){
    int i, u, v;
    scanf("%d", &n);
    for(i = 0; i < n; ++i){
        scanf("%d%d", &u ,&v);
        if(u == 0) root = v - 1;
        else
            adj[u - 1].push_back(v - 1);
    }
    getsz(root);
    dfs(root, 1);
    for(i = 0; i < n; ++i)
        printf("%d\n", ans[i]);
}