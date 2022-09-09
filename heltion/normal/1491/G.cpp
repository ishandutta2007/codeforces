#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr int maxn = 200000 + 1;
int p[maxn], vis[maxn];
vector<pair<int, int>> ans;
void swapp(int u, int v){
    swap(p[u], p[v]);
    p[u] = -p[u];
    p[v] = -p[v];
    ans.push_back({u, v});
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    //for(int i = 1; i <= n; i += 1) p[i] = i;
    //random_shuffle(p + 1, p + n + 1);
    for(int i = 1; i <= n; i += 1) cin >> p[i];
    vector<vector<int>> cycles;
    for(int i = 1; i <= n; i += 1) if(not vis[i]){
        vector<int> cycle;
        int j = i;
        while(not vis[j]){
            cycle.push_back(j);
            vis[j] = 1;
            j = p[j];
        }
        if(cycle.size() > 1) cycles.push_back(cycle); 
    }
    for(int i = 0; i + 1 < cycles.size(); i += 2){
        auto& A = cycles[i], &B = cycles[i + 1];
        swapp(A[0], B[0]);
        for(int i = 1; i < B.size(); i += 1)
            swapp(A[0], B[i]);
        for(int i = 1; i < A.size(); i += 1)
            swapp(B[0], A[i]);
        swapp(A[0], B[0]);
    }
    if(cycles.size() & 1){
        auto& A = cycles.back();
        if(A.size() > 2){
            for(int i = 0; i < A.size() - 2; i += 1) swapp(A[i], A.back());
            swapp(A[0], A[A.size() - 2]);
            swapp(A[A.size() - 2], A.back());
            swapp(A[0], A.back());
        }
        else{
            vector<int> B;
            for(int i = 1; i <= n; i += 1) if(i != A[0] and i != A[1]){
                B.push_back(i);
                break;
            }
            swapp(A[0], B[0]);
            for(int i = 1; i < B.size(); i += 1)
                swapp(A[0], B[i]);
            for(int i = 1; i < A.size(); i += 1)
                swapp(B[0], A[i]);
            swapp(A[0], B[0]);
        }
    }
    cout << ans.size() << "\n";
    assert(ans.size() <= n + 1);
    for(auto [x, y] : ans) cout << x << " " << y << "\n";
    for(int i = 1; i <= n; i += 1){
        //cout << p[i] << " ";
        assert(p[i] == i);
    }
    return 0;
}