#include <bits/stdc++.h>
using namespace std;

int main()
{
    int T; cin >> T; while(T--)
    {
        int N, M; cin >> N >> M;
        vector<bool> fill(N*M);
        auto put = [&](int r, int c)
        {
            // cout << r << " " << c << endl;
            int ans = 0;
            for(int i=r*M; i<r*M+c; ++i) if(fill[i]) ++ans;
            fill[r*M+c] = true;
            return ans;
        };
        vector<pair<int, int> > A(N*M);
        for(int i=0; i<N*M; ++i)
        {
            int t; cin >> t; A[i] = {t, i};
        }
        vector<pair<int, int> > V;
        for(int i=0; i<N; ++i) for(int j=0; j<M; ++j) V.emplace_back(i, j);
        sort(A.begin(), A.end());
        for(int i=0; i<N*M; ++i)
        {
            int j = i; while(j != (int)A.size() && A[i].first == A[j].first) ++j;
            // A[i, j)
            // cout << i << " " << j << endl;
            sort(V.begin()+i, V.begin()+j, [&](pair<int, int> a, pair<int, int> b)
            {
                auto [ar, ac] = a; auto [br, bc] = b;
                if(ar != br) return ar < br;
                return ac > bc;
            });
            i = j-1;
        }
        vector<pair<int, int> > P(N*M);
        for(int i=0; i<N*M; ++i)
        {
            P[A[i].second] = V[i];
        }
        long long ans = 0;
        for(auto [a, b]: P) ans += put(a, b);
        cout << ans << endl;
    }
}