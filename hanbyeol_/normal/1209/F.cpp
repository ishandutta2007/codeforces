#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int N, M; cin >> N >> M;
    vector<vector<pair<int, int>>> conn(N);

    auto dummy = [&](){int r = conn.size(); conn.emplace_back(); return r;};
    for(int d=1; d<=M; ++d)
    {
        int a, b; cin >> a >> b; --a; --b;
        string s = to_string(d);
        vector<int> V = {a};
        for(int i=0; i<(int)s.size()-1; ++i) V.push_back(dummy());
        V.push_back(b);
        for(int i=0; i<(int)s.size(); ++i)
        {
            conn[V[i]].emplace_back(V[i+1], s[i] - '0');
            conn[V[i+1]].emplace_back(V[i], s[s.size()-i-1] - '0');
        }
    }

    vector<bool> vis(conn.size()); vector<int> ans(N);

    queue<pair<int, vector<int>>> Q; Q.emplace(0, vector<int>({0}));
    while(!Q.empty())
    {
        auto [c, v] = Q.front(); Q.pop();
        vector<vector<int>> prop(10);
        for(auto x: v) if(!vis[x])
        {
            vis[x] = true; if(x < N) ans[x] = c;
            for(auto [y, d]: conn[x]) prop[d].push_back(y);
        }
        for(int i=0; i<10; ++i) if(prop[i].size())
            Q.emplace((10LL*c+i) % 1000000007, prop[i]);
    }
    for(int i=1; i<N; ++i) cout << ans[i] << '\n'; 
}