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
        if(N == 3 && V[1] % 2 == 1)
        {
            cout << -1 << '\n';
        }
        else if(*max_element(V.begin()+1, V.end()-1) == 1)
        {
            cout << -1 << '\n';
        }
        else
        {
            long long ans = 0;
            for(int i=1; i<N-1; ++i) ans += (V[i]+1)/2;
            cout << ans << '\n';
        }
    }
}