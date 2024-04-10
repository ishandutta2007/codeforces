#include<bits/stdc++.h>
using namespace std;

// returns pair of oriented one, (s, e, edges inside)
pair<vector<int>, vector<tuple<int, int, vector<int>>>> solve(int N, int M, vector<tuple<int, int, int>> V)
{
    vector<vector<pair<int, int>>> conn(N);
    for(auto [u, v, i]: V)
    {
        conn[u].emplace_back(v, i);
        conn[v].emplace_back(u, -i);
    }
    vector<int> cnt(N); // counter of edge
    vector<bool> used(M+1); // whether edge used

    vector<bool> odeg(N);
    for(int i=0; i<N; ++i) if(conn[i].size()%2 == 1) odeg[i] = true;

    auto poll = [&](int a)
    {
        while(cnt[a] < (int)conn[a].size())
        {
            auto [v, e] = conn[a][cnt[a]]; ++cnt[a];
            if(!used[abs(e)])
            {
                used[abs(e)] = 1;
                return make_pair(v, e);
            }
        }
        return make_pair(-1, -1);
    };

    vector<int> ret0;
    vector<tuple<int, int, vector<int>>> ret1;

    for(int i=0; i<N; ++i) if(odeg[i])
    {
        odeg[i] = 0;
        int u = i;
        vector<int> edg;
        while(!odeg[u])
        {
            auto [v, e] = poll(u); assert(v != -1);
            edg.push_back(e); u = v;
        }
        odeg[u] = 0;
        ret1.emplace_back(i, u, edg);
    }
    for(int i=0; i<N; ++i)
    {
        int u = i;
        while(true)
        {
            auto [v, e] = poll(u); if(v == -1) break;
            ret0.push_back(e); u = v;
        }
        assert(u == i);
    }
    return make_pair(ret0, ret1);
}
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int N, M; cin >> N >> M;
    vector<tuple<int, int, int>> V1, V2; // s, e, i;
    for(int i=0; i<M; ++i)
    {
        int a, b, c; cin >> a >> b >>  c; --a; --b;
        if(c == 1) V1.emplace_back(a, b, i+1);
        else V2.emplace_back(a, b, i+1);
    }
    string ans(M, ' ');
    auto set_ans = [&](int x)
    {
        if(x < 0) ans[(-x)-1] = '2';
        else ans[x-1] = '1';
    };
    auto [a1, b1] = solve(N, M, V1);
    int ans0 = 2*b1.size();
    auto [a2, b2] = solve(N, M, V2);
    for(auto x: a1) set_ans(x);
    for(auto x: a2) set_ans(x);

/*
    cout << "#1" << endl;
    for(auto x: a1) cout << x << " ";
    cout << endl << endl;
    for(auto [a, b, c]: b1)
    {
        cout << a+1 << "->" << b+1 << endl;
        for(auto x: c) cout << x << " ";
        cout << endl << endl;
    }
    cout << "#2" << endl;
    for(auto x: a2) cout << x << " ";
    cout << endl << endl;
    for(auto [a, b, c]: b2)
    {
        cout << a+1 << "->" << b+1 << endl;
        for(auto x: c) cout << x << " ";
        cout << endl << endl;
    }
*/

    copy(b2.begin(), b2.end(), back_inserter(b1));

    auto set_meta_ans = [&](int x)
    {
        int r = abs(x)-1;
        const auto& v = get<2>(b1[r]);
        for(auto y: v) if(x < 0) set_ans(-y); else set_ans(y);
    };

    vector<tuple<int, int, int>> metaG;

    for(int i=0; i<(int)b1.size(); ++i)
    {
        int u = get<0>(b1[i]), v = get<1>(b1[i]);
        metaG.emplace_back(u, v, i+1);
    }
    auto [am, bm] = solve(N, (int)b1.size(), metaG);
    for(auto x: am) set_meta_ans(x);
    for(auto x: bm) for(auto y: get<2>(x)) set_meta_ans(y);
    cout << ans0 << endl;
    cout << ans << endl;
}