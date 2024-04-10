#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int N; cin >> N;
    vector<int> H(N); for(int&x:H) cin >> x;
    vector<vector<int>> conn(N);
    for(int i=0; i<N-1; ++i)
    {
        int u, v; cin >> u >> v; --u; --v;
        conn[u].push_back(v); conn[v].push_back(u);
    }
    int r = distance(H.begin(), max_element(H.begin(), H.end()));
    // install inf free, do not install inf, maximum among all
    function<tuple<long long, long long, int>(int, int)> dfs = [&](int a, int p)
    {
        vector<tuple<long long, long long, int>> res;
        for(auto x: conn[a]) if(x != p) res.push_back(dfs(x, a));
        if(res.empty())
        {
            // cerr << a << " " << p << ": " << 0LL << " " << H[a] << " " << H[a] << endl;
            return make_tuple(0LL, (long long)H[a], H[a]);
        }

        long long piff = LLONG_MAX;
        long long nifr = 0;
        int mxm = 0;
        for(auto [iff, nif, mv]: res)
        {
            piff = min(piff, iff-nif);
            nifr += nif;
            mxm = max(mxm, mv);
        }

        if(mxm >= H[a]) // no need to install additional H[a]
        {
            // cerr << a << " " << p << ": " << nifr+piff << " " << nifr << " " << mxm << endl;
            assert(piff+mxm == 0);
            return make_tuple(nifr+piff, nifr, mxm);
        }
        else // another inf should be installed somewhere for nifr
        {
            // cerr << a << " " << p << ": " << nifr+piff << " " << nifr+piff+H[a] << " " << mxm << endl;
            return make_tuple(nifr+piff, nifr+piff+H[a], H[a]);
        }

    };
    vector<tuple<long long, long long, int>> vals;
    for(auto x: conn[r])
    {
        vals.push_back(dfs(x, r));
    }
    if(vals.size() == 1)
    {
        auto [iff, nif, mxm] = vals[0];
        if(mxm == H[r])
            cout << nif + H[r] << endl;
        else
            cout << iff + 2*H[r] << endl;
    }
    else
    {
        // install two inf;
        vector<long long> delta;
        long long ans = 0;
        // int nif_is_iff = 0;
        for(auto [iff, nif, mxm]: vals)
        {
            delta.push_back(iff-nif);
            ans += nif;
        }
        sort(delta.begin(), delta.end());
        cout << ans + delta[0] + delta[1] + 2*H[r] << endl;
    }
}