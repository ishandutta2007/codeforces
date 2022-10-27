#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

pair<int, pair<int,int> > arr[100005];
bool spc[100005];
int x[100005], p[100005], ans[100005];
vector<int> a[100005];

int find(int v){
    return (p[v] == v)?v:(p[v] = find(p[v]));
}

void combine(int u, int v, int w, int k){
    u = find(u), v = find(v);
    if(u == v)return;
    if(a[u].size() < a[v].size())swap(u, v);
    p[v] = u;
    for(auto x : a[v]){
        a[u].push_back(x);
    }
    if(a[u].size() == k){
        for(int i = 1; i <= k; i++){
            cout<<w<<" ";
        }
        exit(0);
    }
}

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    int n, m, k, u, v, w;
    cin>>n>>m>>k;
    memset(spc, false, sizeof(spc));
    for(int i = 1; i <= k; i++){
        cin>>x[i];
        spc[x[i]] = true;
    }
    for(int i = 1; i <= n; i++){
        ans[i] = 0;
        p[i] = i;
        if(spc[i])a[i].push_back(i);
    }
    for(int i = 1; i <= m; i++){
        cin>>u>>v>>w;
        arr[i] = {w, {u, v}};
    }
    sort(arr + 1, arr + m + 1);
    for(int i = 1; i <= m; i++){
        w = arr[i].first;
        u = arr[i].second.first;
        v = arr[i].second.second;
        combine(u, v, w, k);
    }
}