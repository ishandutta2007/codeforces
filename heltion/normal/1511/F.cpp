#include <bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
constexpr int maxn = 300;
int id = 0;
struct Mat{
    LL A[maxn][maxn];
    Mat(){
        memset(A, 0, sizeof A);
    }
    Mat operator * (const Mat& mat)const{
        Mat res;
        for(int i = 0; i < id; i += 1)
            for(int j = 0; j < id; j += 1)
                for(int k = 0; k < id; k += 1)
                    res.A[i][j] = (res.A[i][j] + A[i][k] * mat.A[k][j]) % mod;
        return res;
    }
};
Mat power(Mat a, LL r){
    Mat res;
    for(int i = 0; i < maxn; i += 1) res.A[i][i] = 1;
    for(; r; r >>= 1, a = a * a)
        if(r & 1) res = res * a;
    return res;
}
int main(){
    cin.sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<string> vs(n);
    for(auto& s : vs) cin >> s;
    vector<int> shift(n + 1);
    for(int i = 1; i <= n; i += 1)
        shift[i] = shift[i - 1] + vs[i - 1].size() - 1;
    int f = shift.back(), k = (f + 1) * (f + 1);
    vector<vector<int>> G(k), H(k);
    auto tr = [&](int x, int y){
        if(x == f){
            for(int i = 0; i < n; i += 1)
                if(y == shift[i] and vs[i].size() > 1) return vs[i][0];
            return '\0';
        }
        if(y == f){
            for(int i = 0; i < n; i += 1)
                if(x == shift[i + 1] - 1 and vs[i].size() > 1) return vs[i].back();
            return '\0'; 
        }
        for(int i = 0; i < n; i += 1)
            if(x + 1 == y and x >= shift[i] and y < shift[i + 1]) return vs[i][x - shift[i] + 1];
        return '\0';
    };
    for(int i = 0; i <= f; i += 1)
        for(int j = 0; j <= f; j += 1)
            for(int x = 0; x <= f; x += 1)
                for(int y = 0; y <= f; y += 1){
                    if(i == f and x == f and j == f and y == f){
                        for(int k = 0; k < n; k += 1)
                            if(vs[k].size() == 1) G[i * (f + 1) + j].push_back(x * (f + 1) + y);
                        continue;
                    }
                    if(i == f and x == f){
                        for(int k = 0; k < n; k += 1){
                            if(vs[k].size() == 1 and tr(j, y) == vs[k][0]) G[i * (f + 1) + j].push_back(x * (f + 1) + y);
                        }
                        continue;
                    }
                    if(j == f and y == f){
                        for(int k = 0; k < n; k += 1){
                            if(vs[k].size() == 1 and tr(i, x) == vs[k][0]) G[i * (f + 1) + j].push_back(x * (f + 1) + y);
                        }
                        continue;
                    }
                    int ti = tr(i, x), tj = tr(j, y);
                    if(ti and tj and ti == tj){
                        G[i * (f + 1) + j].push_back(x * (f + 1) + y);
                    }
                }
    for(int i = 0; i < k; i += 1)
        for(int j : G[i]) H[j].push_back(i);
    vector<int> vG(k), vH(k);
    function<void(vector<vector<int>>&, vector<int>&, int)> DFS = [&](vector<vector<int>>& G, vector<int>& vis, int u){
        vis[u] = 1;
        for(int v : G[u]) if(not vis[v]) DFS(G, vis, v);
    };
    DFS(G, vG, k - 1);
    DFS(H, vH, k - 1);
    map<int, int> mp;
    for(int i = 0; i < k; i += 1)
        if(vG[i] and vH[i]) mp[i] = id ++;
    //cout << id << "\n";
    assert(id <= maxn);
    Mat mat;
    for(int i = 0; i < k; i += 1) if(mp.count(i))
        for(int j : G[i]) if(mp.count(j)){
            //cout << i << " " << j << endl;
            mat.A[mp[j]][mp[i]] += 1;
        }
    Mat res = power(mat, m);
    cout << res.A[mp[k - 1]][mp[k - 1]] << '\n';
    return 0;
}