#include <bits/stdc++.h>
using namespace std;

const int MOD = 998244353;
const int SET_SIZE = 50349;
using Line = bitset<SET_SIZE>;

vector<vector<int>> gen(int N)
{
    vector<vector<int>>res;
    vector<int> cur (N);

    function<void(int, int)> fill = [&](int nxt, int now)
    {
        if(now == 0)
        {
            res.push_back(cur);
            return;
        }
        int mi = 31-__builtin_clz(now);

        now ^= (1<<mi);

        cur[mi] = nxt;
        for(int i=0; i=(i-now)&now;) if(__builtin_popcount(i)&1)
        {
            for(int j=0; j<N; ++j) if(i&(1<<j)) cur[j] = nxt;
            fill(nxt+1, now-i);
            for(int j=0; j<N; ++j) if(i&(1<<j)) cur[j] = 0;
        }
        cur[mi] = 0;


    };
    fill(1, (1<<N)-1);
    return res;
}


Line ok(vector<vector<bool>>adj, vector<vector<int> > V)
{
    int N = adj.size();
    map<tuple<int, int, int>,Line> DP;
    for(int i=0; i<N; ++i) for(int j=0; j<i; ++j) if(adj[i][j])
        for(int k=0; k<(int)V.size(); ++k) if(V[k][i] == V[k][j])
            DP[{i, j, (1<<i)|(1<<j)}][k] = true;

    vector<vector<Line>> eq(N, vector<Line>(N));
    for(int i=0; i<N; ++i) for(int j=0; j<i; ++j) for(int k=0; k<(int)V.size(); ++k)
        if(V[k][i] == V[k][j]) eq[i][j][k] = true;


    vector<vector<int>> VV(N+1);
    for(int b=0; b<(1<<N); ++b)
    {
        int p = __builtin_popcount(b);
        VV[p].push_back(b);
    }

    for(int i=4; i<=N; i += 2)
    {
        map<tuple<int, int, int>,Line> NDP;
        for(auto b: VV[i])
        {
            int p = __builtin_popcount(b);
            if(p <= 2 || (p & 1)) continue;
            for(int i=0; i<N; ++i) if((1<<i)&b)
            for(int j=0; j<i; ++j) if((1<<j)&b)
            {
                int rem = b ^ (1<<i) ^ (1<<j);
                set<pair<int, int> > KS;
                for(int k=0; k<N; ++k) if((1<<k)&rem && adj[i][k])
                for(int s=0; s<N; ++s) if(k != s && ((1<<s)&rem) && adj[s][j])
                {
                    KS.emplace(max(k, s), min(k, s));
                }
                for(auto [k, s]: KS)
                {
                    if(DP.count({k,s,rem}))
                        NDP[{i, j, b}] |= DP[{k,s,rem}] & eq[i][j] & eq[k][s];
                }
            }
        }
        DP.swap(NDP);
        NDP.clear();
    }
    Line ret;
    for(int i=0; i<N; ++i) for(int j=0; j<i; ++j) if(DP.count({i, j, (1<<N)-1})) ret |= DP[{i, j, (1<<N)-1}];
    return ret;
}

long long calc(int K, vector<int> x)
{
    long long ans = 1;
    int mv = *max_element(x.begin(), x.end());
    for(int i=0; i<mv; ++i) ans *= K-i;
    return ans;
}

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int N, M, K; cin >> N >> M >> K;
    vector<vector<bool>> adj(N, vector<bool>(N));
    for(int i=0; i<M; ++i)
    {
        int u, v; cin >> u >> v; --u; --v;
        adj[u][v] = adj[v][u] = 1;
    }
    // for(int i=0; i<N; ++i) for(int j=0; j<i; ++j) adj[i][j] = adj[j][i] = 1;
    vector<vector<int>> G = gen(N);
    vector<vector<int>> G1(G.begin(), G.begin()+G.size()/3);
    vector<vector<int>> G2(G.begin()+G.size()/3, G.begin()+G.size()*2/3);
    vector<vector<int>> G3(G.begin()+G.size()*2/3, G.begin()+G.size());
    auto res1 = ok(adj, G1);
    auto res2 = ok(adj, G2);
    auto res3 = ok(adj, G3);
    long long ans = 0;
    for(int i=0; i<(int)G1.size(); ++i)
        if(res1[i]) ans += calc(K, G1[i]);
    for(int i=0; i<(int)G2.size(); ++i)
        if(res2[i]) ans += calc(K, G2[i]);
    for(int i=0; i<(int)G3.size(); ++i)
        if(res3[i]) ans += calc(K, G3[i]);
    cout << ans << endl;
}