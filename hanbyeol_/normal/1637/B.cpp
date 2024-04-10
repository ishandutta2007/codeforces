#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T; while(T--)
    {
        int N; cin >> N;
        vector<int> V(N);
        for(int i=0; i<N; ++i) cin >> V[i];
        long long ans = 0;
        for(int i=0; i<N; ++i)
        {
            for(int j=i; j<N; ++j)
            {
                for(int k=i; k<=j; ++k)
                {
                    ans += 1 + (V[k] == 0);
                }
            }
        }
        cout << ans << '\n';
    }
}