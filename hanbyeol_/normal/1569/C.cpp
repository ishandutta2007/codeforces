#include <bits/stdc++.h>
using namespace std;


const int MOD = 998244353;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        int N; cin >> N; vector<int> V(N);
        for(int&x: V) cin >> x;
        int maxv = *max_element(V.begin(), V.end());
        int maxc = count(V.begin(), V.end(), maxv);
        int a = 1, b = 1;
        if(maxc == 1)
        {
            int maxm = count(V.begin(), V.end(), maxv-1);
            a = maxm+1; b = maxm;
        }
        long long ans = 1;
        for(int i=1; i<=N; ++i)
        {
            if(i == a) ans *= b;
            else ans *= i;
            ans %= MOD;
        }
        cout << ans << '\n';
    }
}