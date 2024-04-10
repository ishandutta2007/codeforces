#include<bits/stdc++.h>
using namespace std;


int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T; while(T--)
    {
        int N; cin >> N; vector<int> V(N); for(int &i: V) cin >> i;
        int ans = 0;
        for(int i=0; i<N; ++i) if(i == N-1 || V[i] != V[i+1])
        {
            auto [fi, se] = equal_range(V.begin(), V.end(), V[i]);
            int p = se-V.begin()-1, c = se-fi;
            while(true)
            {
                auto it = lower_bound(V.begin()+p+1, V.end(), 2*V[p]-V[i]);
                if(it == V.end()) break;
                else
                {
                    ++c; p = it - V.begin();
                }
            }
            ans = max(ans, c);
        }
        cout << N-ans << '\n';
    }
}