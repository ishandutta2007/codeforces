#include <bits/stdc++.h>
using namespace std;

int solve(const vector<vector<int>>& conn)
{
    int ans = 0;
    function<bool(int, int)> dfs = [&](int a, int p)
    {
        int lc = 0;
        for(int x: conn[a]) if(x != p)
            if(dfs(x, a)) ++lc;
        if(lc == 0) return true;
        ans += lc - 1;
        return false;
    };
    dfs(0, -1);
    return ans+1;
}

int main()
{
    int T; cin >> T; while(T--)
    {
        int N; cin >> N; vector<vector<int>>conn(N);
        for(int i=0; i<N-1; ++i)
        {
            int u, v; cin >> u >> v; --u; --v;
            conn[u].push_back(v);
            conn[v].push_back(u);
        }
        cout << solve(conn) << endl;
    }
}