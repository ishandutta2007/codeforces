#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N;
    vector<vector<int>>C(N);
    for(int i=0; i<N; ++i)
    {
        int t; cin >> t; C[i].resize(t);
        for(int &v: C[i]) cin >> v;
    }
    int M; cin >> M; vector<vector<int>> pro(M, vector<int>(N));
    for(auto&x: pro) for(auto&y:x) { cin >> y; --y; }
    sort(pro.begin(), pro.end());
    vector<bool> vis(M);

    priority_queue<pair<int, vector<int>>> Q;
    int s = 0; for(auto&x: C) s += x.back();
    vector<int> T(N); for(int i=0; i<N; ++i) T[i] = (int)C[i].size()-1;

    int ret = -1;
    vector<int> rv;
    function<void(const vector<int>&)> dfs = [&](const vector<int>& V)
    {
        auto it = lower_bound(pro.begin(), pro.end(), V);
        if(it == pro.end() || *it != V)
        {
            int ans = 0;
            for(int i=0; i<N; ++i) ans += C[i][V[i]];
            if(ret < ans)
            {
                ret = ans;
                rv = V;
            }
            return;
        }
        int idx = it - pro.begin();
        if(vis[idx]) return;
        vis[idx] = true;
        for(int i=0; i<N; ++i)
            if(V[i] > 0)
            {
                auto U = V; U[i]--; dfs(U);
            }
    };

    dfs(T);

    for(auto x: rv) cout << x+1 << " ";
    cout << endl;
}