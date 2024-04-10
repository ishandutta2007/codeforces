#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int N, M; cin >> N >> M;
    vector<int> X(N), Y(N); 
    for(int i=0; i<N; ++i) cin >> X[i] >> Y[i];

    vector<int> cur(N, -1);
    vector<vector<pair<int, int>>> MM(M);

    auto put = [&](int d, int c, int k)
    {
        // cout << "P" << d << " " << c << " " << k << endl;
        if(d>=M) return;
        MM[d].emplace_back(c, k);
    };

    int ans = 0;
    for(int i=0; i<M; ++i)
    {
        int op, k; cin >> op >> k; --k;
        if(op == 1)
        {
            cur[k] = i;
            put(i+X[k],X[k]+Y[k], 1);
            put(i+X[k]+Y[k], X[k]+Y[k], -1);
        }
        else
        {
            int p = i-cur[k];
            int cl = X[k]+Y[k];
            int d = cur[k] + (p/cl)*cl;
            if(d+X[k] >= i) put(d+X[k], cl, -1);
            else put(d+cl+X[k], cl, -1);
            if(d >= i) put(d, cl, 1);
            else put(d+cl, cl, 1);
            // update maintenance
            // cout << p << " " << cl << " " << X[k] << " " << Y[k] << endl;
            
            // for prev day, if it is in mant
            if((p+cl-1)%cl >= X[k]) --ans;
        }

        sort(MM[i].begin(), MM[i].end());
        if(!MM[i].empty())
        {
            auto [cyc, cur] = MM[i][0];
            for(int j=1; j<(int)MM[i].size(); ++j)
            {
                auto [yj, uj] = MM[i][j];
                if(cyc == yj) cur += uj;
                else
                {
                    if(cur) put(i+cyc, cyc, cur);
                    ans += cur;
                    cyc = yj, cur = uj;
                }
            }
            if(cur) put(i+cyc, cyc, cur);
            ans += cur;
        }

        cout << ans << '\n';
    }

}