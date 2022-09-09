#include<bits/stdc++.h>
using namespace std;
constexpr int maxn = 100000;
constexpr int SB = 320;
vector<int> G[maxn + 1];
int c[maxn + 1];
int query[maxn][3];
vector<int> dfp;
int key[maxn + 1], kv[maxn + 1];
vector<int> kidv[maxn + 1];
int par[maxn + 1];
int park[maxn + 1];
vector<int> kidk[maxn + 1];
pair<int, int> path[maxn + 1];
void DFS(int u){
    for(int v : G[u]) if(v != par[u]){
        par[v] = u;
        DFS(v);
    }
    dfp.push_back(u);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, k;
    cin >> n >> k;
    for(int i = 1, u, v; i < n; i += 1){
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    for(int i = 1; i <= n; i += 1) cin >> c[i];
    int q;
    cin >> q;
    for(int i = 0; i < q; i += 1){
        cin >> query[i][0] >> query[i][1];
        if(query[i][0] == 2) cin >>  query[i][2];
    }
    DFS(1);
    for(int L = 0; L < q; L += SB){
        int R = min(q, L + SB), root = 1;
        vector<int> key_node;
        for(int u : dfp){
            key[u] = 0;
            kidv[u].clear();
            kidk[u].clear();
        }
        for(int j = L; j < R; j += 1)
            if(query[j][0] != 3) key[query[j][1]] = 2;
        for(int u : dfp) if(key[u]){
            if(key[u] >= 2){
            root = u;
            key_node.push_back(u);
            }
            key[par[u]] += 1; 
        }
        for(int u : dfp) if(not key[u]){
            if(~c[u]) kv[u] = c[u] ? n + 1 : -n;
            else{
                int L = -n, R = n;
                while(L < R){
                    int M = (L + R - ((L + R) & 1)) / 2;
                    int b = 0, r = 0;
                    for(int x : kidv[u]) (M < x ? b : r) += 1;
                    if(b - r >= M) L = M + 1;
                    else R = M;
                }
                kv[u] = L;
            }
            kidv[par[u]].push_back(kv[u]);
        }
        for(int u : dfp) if(key[u] >= 2){
            path[u] = {-n, n + 1};
            sort(kidv[u].begin(), kidv[u].end());
            if(u == root) continue;
            int p = u;
            while(key[par[p]] < 2){
                int L = -n, R = n;
                while(L < R){
                    int M = (L + R - ((L + R) & 1)) / 2;
                    int r = upper_bound(kidv[u].begin(), kidv[u].end(), M) - kidv[u].begin();
                    int b = kidv[u].size() - r;
                    (M < path[u].first ? b : r) += 1;
                    if(b - r >= M) L = M + 1;
                    else R = M;
                }
                path[u].first = L;
                L = -n, R = n;
                while(L < R){
                    int M = (L + R - ((L + R) & 1)) / 2;
                    int r = upper_bound(kidv[u].begin(), kidv[u].end(), M) - kidv[u].begin();
                    int b = kidv[u].size() - r;
                    (M < path[u].second ? b : r) += 1;
                    if(b - r >= M) L = M + 1;
                    else R = M;
                }
                path[u].second = L;
                p = par[p];
            }
            park[u] = par[p];
            kidk[par[p]].push_back(u);
            //cout << u << " " << park[u] << " " << path[u].first << " " << path[u].second << endl;
        }
        auto rebuild = [&](){
            for(int u : key_node)
                if(~c[u]) kv[u] = c[u] ? n + 1 : -n;
                else{
                    int L = -n, R = n;
                    while(L < R){
                        int M = (L + R - ((L + R) & 1)) / 2;
                        int r = upper_bound(kidv[u].begin(), kidv[u].end(), M) - kidv[u].begin();
                        int b = kidv[u].size() - r;
                        for(int v : kidk[u])
                            (M < (M >= kv[v] ? path[v].first : path[v].second) ? b : r) += 1;
                        if(b - r >= M) L = M + 1;
                        else R = M;
                    }
                    kv[u] = L;
                }
            if(0)for(int u : key_node)
                cout << "kv[" << u << "] = " << kv[u] << endl; 
        };
        rebuild();
        for(int i = L; i < R; i += 1)
            if(query[i][0] == 3) k = query[i][1];
            else if(query[i][0] == 1)
                cout << (~c[query[i][1]] ? c[query[i][1]] : k < kv[query[i][1]]) << "\n";
            else{
                c[query[i][1]] = query[i][2];
                rebuild();
            }
    }
    return 0;
}