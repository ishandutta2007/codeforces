#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T; while(T--)
    {
        int N; cin >> N;
        vector<int> A(N), B(N);
        for(int&i:A) cin >> i;
        for(int&i:B) cin >> i;
        int ans = 2*N;
        for(int i=1; i<N; ++i) B[i] = max(B[i-1], B[i]);
        for(int i=0; i<N; ++i)
        {
            int lb = lower_bound(B.begin(), B.end(), A[i]) - B.begin();
            ans = min(ans, i + lb);
        }
        cout<<ans<<endl;
    }
}