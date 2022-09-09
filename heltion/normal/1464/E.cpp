#include<bits/stdc++.h>
using namespace std;
using LL = long long;
constexpr LL mod = 998244353;
LL power(LL a, LL r){
    LL res = 1;
    for(; r; r >>= 1, a = a * a % mod)
        if(r & 1) res = res * a % mod;
    return res;
}
void gauss(vector<vector<LL>>& A){
    int n = A.size();
    for(int i = 0; i < n; i += 1){
        int m = i;
        if(A[i][i] == 0)
            for(int j = i + 1; j < n; j += 1)
                if(A[j][i])
                    m = i;
        swap(A[i], A[m]);
        for(int j = 0; j < n; j += 1) if(i != j){
            LL d = A[j][i] * power(A[i][i], mod - 2) % mod;
            for(int k = i; k <= n; k += 1)
                A[j][k] = (A[j][k] + mod - A[i][k] * d % mod) % mod;
        }
    }
    for(int i = 0; i < n; i += 1) A[i][n] = A[i][n] * power(A[i][i], mod - 2) % mod;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> G(n + 1), H(n + 1);
    vector<int> d(n + 1), sg(n + 1);
    for(int i = 0; i < m; i += 1){
        int u, v;
        cin >> u >> v;
        d[u] += 1;
        G[u].push_back(v);
        H[v].push_back(u);
    }
    queue<int> q;
    for(int i = 1; i <= n; i += 1) if(not d[i]) q.push(i);
    while(not q.empty()){
        int u = q.front();
        q.pop();
        set<int> s;
        for(int v : G[u]) s.insert(sg[v]);
        while(s.count(sg[u])) sg[u] += 1;
        for(int v : H[u]) if(not (d[v] -= 1)) q.push(v);
    }
    int k = 1, msg = *max_element(sg.begin(), sg.end());
    while(k <= msg) k <<= 1;
    vector<int> cnt(k);
    for(int i = 1; i <= n; i += 1) cnt[sg[i]] += 1;
    vector<vector<LL>> A(k, vector<LL>(k + 1));
    LL x = power(n + 1, mod - 2);
    for(int i = 0; i < k; i += 1){
        A[i][i] = 1;
        A[i][k] = not i * x;
        for(int j = 0; j < k; j += 1)
            A[i][i ^ j] = (A[i][i ^ j] + mod - cnt[j] * x % mod) % mod;
    }
    if(0) for(int i = 0; i < k; i += 1){
        for(int j = 0; j <= k; j += 1) cout << A[i][j] << " ";
        cout << "\n";
    }
    gauss(A);
    cout << (mod + 1 - A[0][k]) % mod;
    return 0;
}