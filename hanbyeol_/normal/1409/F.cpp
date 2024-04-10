#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int N, K; cin >> N >> K;
    string s, t; cin >> s >> t;
    if(t[0] == t[1])
    {
        int v = 0;
        for(auto c: s) if(c == t[0]) ++v;
        v = min(v+K, N);
        cout << v*(v-1)/2 << endl;
        return 0;
    }
    // DP[a][b][c]
    // seen until a, change: b, # first letter: c, ans?
    const int INF = 1e9;
    vector<vector<vector<int>>>DP(N+1, vector<vector<int>>(K+1, vector<int>(N+1, -INF)));
    DP[0][0][0] = 0;
    for(int a=0; a<N; ++a)
        for(int b=0; b<=K; ++b)
            for(int c=0; c<N; ++c)
            {
                if(s[a] == t[0])
                    DP[a+1][b][c+1] = max(DP[a+1][b][c+1], DP[a][b][c]);
                else if(s[a] == t[1])
                    DP[a+1][b][c] = max(DP[a+1][b][c], DP[a][b][c]+c);
                else
                    DP[a+1][b][c] = max(DP[a+1][b][c], DP[a][b][c]);

                if(b != K)
                {
                    // change to t[0]
                    DP[a+1][b+1][c+1] = max(DP[a+1][b+1][c+1], DP[a][b][c]);
                    // change to t[1]
                    DP[a+1][b+1][c] = max(DP[a+1][b+1][c], DP[a][b][c]+c);
                }
            }
    cout << *max_element(DP.back().back().begin(), DP.back().back().end()) << endl;
}