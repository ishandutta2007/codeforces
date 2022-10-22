#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T; while(T--)
    {
        int N; cin >> N;
        vector<int> A(N), B(N);
        long long ans = 0; int sv = 0; long long sos = 0;
        for(int i=0; i<N; ++i) cin >> A[i], sos += A[i]*A[i], sv += A[i];
        for(int i=0; i<N; ++i) cin >> B[i], sos += B[i]*B[i], sv += B[i];
        bitset<20001> DP; DP[0] = 1;
        for(int i=0; i<N; ++i)
            DP = (DP << A[i]) | (DP << B[i]);
        long long rv = 1e18;
        for(int i=0; i<=sv; ++i) if(DP[i])
        {
            rv = min(rv, 1LL*i*i + 1LL*(sv-i)*(sv-i) - sos );
        }
        cout << (rv + sos*(N-1)) << '\n';
    }
}