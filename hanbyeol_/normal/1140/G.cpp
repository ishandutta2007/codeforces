#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N; vector<long long> cflip(N); for(auto&x: cflip) cin >> x; // LR flip
    vector<tuple<int, int, long long, long long>> E(N-1); // L cost, R cost

    vector<vector<int>> conn(N);
    for(int i=0; i<N-1; ++i)
    {
        auto&[a, b, c, d] =  E[i];
        cin >> a >> b >> c >> d;
        --a; --b;
        conn[a].emplace_back(i);
        conn[b].emplace_back(i);
    }
    vector<long long> flip(N, -1); // real flip cost
    using pli = pair<long long, int>;
    priority_queue<pli, vector<pli>, greater<pli>> Q;
    for(int i=0; i<N; ++i) Q.emplace(cflip[i], i);
    while(!Q.empty())
    {
        auto [d, v] = Q.top(); Q.pop();
        if(flip[v] != -1) continue; else flip[v] = d;
        for(auto Eno: conn[v])
        {
            auto [v1, v2, c1, c2] = E[Eno];
            int u = v1^v2^v;
            Q.emplace(c1+c2+d, u);
        }
    }

    // now run dfs and get parent information
    vector<int> par(N, -1); vector<int> height(N, -1);
    using cost_t = tuple<long long, long long, long long, long long>;
    vector<cost_t> cost(N); // cost to get parent, LL, LR, RL, RR
    function<void(int, int, int)> dfs = [&](int a, int p, int h)
    {
        height[a] = h;
        for(auto Eno: conn[a])
        {
            auto [v1, v2, c1, c2] = E[Eno];
            int u = v1^v2^a; if(u == p) continue;
            dfs(u, a, h+1);
            par[u] = a;
            // going u -> a
            long long LL = min(c1, flip[u] + c2 + flip[a]);
            long long LR = min(c1 + flip[a], flip[u] + c2);
            long long RL = min(flip[u] + c1, c2 + flip[a]);
            long long RR = min(c2, flip[u] + c1 + flip[a]);
            cost[u] = {LL, LR, RL, RR};
        }
    };
    dfs(0, -1, 0);

    const int K = log2(N);
    vector<vector<int>> sparse_par(K+1, vector<int>(N, -1));
    vector<vector<cost_t>> sparse_cost(K+1, vector<cost_t>(N));
    sparse_par[0] = par; sparse_cost[0] = cost;

    auto merge_cost = [&](cost_t f, cost_t t)
    {
        auto [FLL, FLR, FRL, FRR] = f;
        auto [TLL, TLR, TRL, TRR] = t;
        long long LL = min(FLL+TLL, FLR+TRL);
        long long LR = min(FLL+TLR, FLR+TRR);
        long long RL = min(FRL+TLL, FRR+TRL);
        long long RR = min(FRL+TLR, FRR+TRR);
        return cost_t(LL, LR, RL, RR);
    };
    auto rev_cost = [&](cost_t f)
    {
        auto [LL, LR, RL, RR] = f;
        return cost_t(LL, RL, LR, RR);
    };

    for(int k=1; k<=K; ++k)
    {
        for(int i=0; i<N; ++i) if(sparse_par[k-1][i] != -1)
        {
            sparse_par[k][i] = sparse_par[k-1][sparse_par[k-1][i]];
            if(sparse_par[k][i] != -1)
                sparse_cost[k][i] = merge_cost(sparse_cost[k-1][i], sparse_cost[k-1][sparse_par[k-1][i]]);
        }
    }

    auto solve = [&](int u, bool ul, int v, bool vl)
    {
        if(height[u] < height[v]){ swap(u, v); swap(ul, vl); }

        cost_t ucost = cost_t(0, flip[u], flip[u], 0);
        cost_t vcost = cost_t(0, flip[v], flip[v], 0);

        int hdiff = height[u] - height[v];
        for(int i=0; i<=K; ++i) if(hdiff&(1<<i))
        {
            ucost = merge_cost(ucost, sparse_cost[i][u]);
            u = sparse_par[i][u];
        }
        if(u != v)
        {
            for(int i=K; i>=0; --i) if(sparse_par[i][u] != sparse_par[i][v])
            {
                ucost = merge_cost(ucost, sparse_cost[i][u]);
                u = sparse_par[i][u];

                vcost = merge_cost(vcost, sparse_cost[i][v]);
                v = sparse_par[i][v];
            }
            // u != v
            ucost = merge_cost(ucost, sparse_cost[0][u]);
            vcost = merge_cost(vcost, sparse_cost[0][v]);
        }
        auto [LL, LR, RL, RR] = merge_cost(ucost, rev_cost(vcost));
        if(ul && vl) return LL;
        else if(ul && !vl) return LR;
        else if(!ul && vl) return RL;
        else if(!ul && !vl) return RR;
        else assert(false);
    };

    int Qv; cin >> Qv; while(Qv--)
    {
        int a, b; cin >> a >> b; --a; --b;
        cout << solve(a/2, a%2 == 0, b/2, b%2 == 0) << '\n';
    }

}