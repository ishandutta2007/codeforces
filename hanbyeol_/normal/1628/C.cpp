#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T; while(T--)
    {
        int N; cin >> N;
        vector<vector<int>> V(N, vector<int>(N));
        vector<vector<bool>> filled(N, vector<bool>(N));
        for(auto&y: V) for(int&x: y) cin >> x;
        int ans = 0;
        for(int i=1; i<N; ++i)
        {
            for(int j=0; j<N; ++j)
            {
                if(!filled[i-1][j])
                {
                    int dx[] = {-1, 0, 1, 0};
                    int dy[] = {0, 1, 0, -1};
                    ans ^= V[i][j];
                    for(int d=0; d<4; ++d)
                    {
                        int r = i+dx[d], c = j+dy[d];
                        if(0<=r&&r<N&&0<=c&&c<N) filled[r][c] = !filled[r][c];
                    }
                }
            }
        }
        for(int i=0; i<N; ++i) for(int j=0; j<N; ++j) assert(filled[i][j]);
        cout << ans << endl;
    }
}