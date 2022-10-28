#include <iostream>
#include <bits/stdc++.h>
#define mp make_pair
#define pb push_back
using namespace std;
using ll = long long int;
vector < vector<int> > g, gr;
vector<bool> used;
vector<int> order, component;
template<typename T>
istream& operator>>(istream& in, vector<T> &vec){
    for(auto &x : vec){
        in>>x;
    }
    return in;
}
void dfs1 (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i)
        if (!used[ g[v][i] ])
            dfs1 (g[v][i]);
    order.push_back (v);
}

void dfs2 (int v) {
    used[v] = true;
    component.push_back (v);
    for (size_t i=0; i<gr[v].size(); ++i)
        if (!used[ gr[v][i] ])
            dfs2 (gr[v][i]);
}

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> p(n);
    vector<int> q(n);
    cin>>p>>q;
    g.resize(n);
    gr.resize(n);
    for(auto &x : p) --x;
    for(auto &x : q) --x;
    for(int i=1;i<n;i++){
        g[p[i-1]].pb(p[i]);
        gr[p[i]].pb(p[i-1]);
        g[q[i-1]].pb(q[i]);
        gr[q[i]].pb(q[i-1]);
    }
    used.assign(n, false);
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs1(i);
    used.assign(n, false);
    int val = 0;
    string ans(n, '-');
    for (int i=0; i<n; ++i) {
        int v = order[n-1-i];
        if (!used[v]) {
            dfs2(v);
            for(const auto &x : component){
                ans[x] = 'a' + val - (val==26 ? 1 : 0);
            }
            if(val<26) ++val;
            component.clear();
        }
    }
    if(val<k){
        cout<<"NO\n";
        return 0;
    }
    cout<<"YES\n";
    cout<<ans<<"\n";
}