#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define debug(x) cerr<<#x<<": "<<x<<endl
using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<int> p(n);
    rep(i,1,n) cin >> p[i];
    vector<vi> ch(n);
    rep(i,1,n) ch[p[i]].push_back(i);
    vector<int> depth(n);
    for(int i=n-1;i>0;--i) depth[p[i]]=max(depth[p[i]],1+depth[i]);
    vector<int> instr;
    vector<int> init;
    function<void(int)> dfs1 = [&](int u) {
        init.push_back(u);
        int k = sz(ch[u]);
        rep(j,0,k-1) {
            if(depth[ch[u][j]]>depth[ch[u][k-1]]) swap(ch[u][j],ch[u][k-1]);
        }
        for(int v:ch[u]) dfs1(v);
    };
    dfs1(0);
    int k = 0;
    assert(sz(init)==n);
    function<void(int)> dfs2 = [&](int u) {
        ++k;
        for(int v:ch[u]) dfs2(v);
        if(k<n) {
            instr.push_back(init[k]);
        }
    };
    dfs2(0);
    rep(i,0,n) {
        cout<<init[i];
        if(i==n-1) cout<<"\n";
        else cout<<" ";
    }
    cout<<sz(instr)<<"\n";
    for(int x:instr) {
        cout<<x<<" ";
    }
    cout<<endl;
}