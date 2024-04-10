#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
constexpr int maxn = 1000000 + 1;
int a[maxn], b[maxn], p[maxn], sz[maxn], pt;
vector<int> G[maxn], H[maxn];
int ans = 0;
void DFS2(int u){
    p[u] = pt += 1;
    sz[u] = 1;
    for(int v : H[u]){
        DFS2(v);
        sz[u] += sz[v];
    }
}
struct cmp{
    bool operator()(const int& x, const int& y)const{
        return p[x] < p[y];
    }
};
set<int, cmp> s;
void DFS1(int u){
    int ins = 1;
    auto x = s.lower_bound(u);
    int pop = 0;
    if(x != s.end() and (p[*x] <= p[u] + sz[u] - 1)) ins = 0;
    else{
        auto y = s.lower_bound(u);
        if(y != s.begin() and (p[u] <= p[*prev(y)] + sz[*prev(y)] - 1)) pop = *prev(y);
        if(pop) s.erase(pop);
        s.insert(u);
    }
    ans = max(ans, (int)s.size());
    for(int v : G[u]) DFS1(v);
    if(pop) s.insert(pop);
    if(ins) s.erase(u);
}
int main(){
    cin.tie(nullptr)->sync_with_stdio(false);
    int t;
    for(cin >> t; t; t -= 1){
        int n;
        cin >> n;
        for(int i = 1; i <= n; i += 1){
            G[i].clear();
            H[i].clear();
        }
        for(int i = 2; i <= n; i += 1){
            cin >> a[i];
            G[a[i]].push_back(i);   
        }
        for(int i = 2; i <= n; i += 1){
            cin >> b[i];
            H[b[i]].push_back(i);   
        }
        DFS2(1);
        ans = 0;
        DFS1(1);
        cout << ans << "\n";
    }
    return 0;
}