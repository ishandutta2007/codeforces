#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        int N, Z; cin >> N >> Z;
        int ans = 0;
        for(int i=0; i<N; i++)
        {
            int t; cin >> t;
            ans = max(ans, t | Z);
        }
        cout << ans << endl;
    }
}