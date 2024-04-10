#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T; while(T--)
    {
        int N, K; cin >> N >> K;
        vector<int> A(N); int xorv = 0;
        for(int& i: A){ cin >> i; xorv ^= i; }

        vector<vector<int>> conn(N);
        for(int i=0; i<N-1; ++i)
        {
            int u, v; cin >> u >> v; --u; --v;
            conn[u].push_back(v); conn[v].push_back(u);
        }

        if(xorv == 0)
        {
            cout << "YES" << endl;
            continue;
        }
        if(K == 2)
        {
            cout << "NO" << endl;
            continue;
        }

        int cnt = 0;
        function<int(int, int)> dfs = [&](int a, int p)
        {
            int ret = A[a];
            for(auto x: conn[a]) if(x != p) ret ^= dfs(x, a);
            if(ret == xorv)
            {
                ++cnt; ret = 0;
            }
            return ret;
        };

        dfs(0, -1);
        if(cnt >= 3) cout << "YES" << endl;
        else cout << "NO" << endl;


    }

}