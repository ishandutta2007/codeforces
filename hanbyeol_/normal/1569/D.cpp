#include <bits/stdc++.h>
using namespace std;


const int MOD = 998244353;
int main()
{
    ios::sync_with_stdio(false); cin.tie(0);
    int T; cin >> T;
    while(T--)
    {
        int N, M, K; cin >> N >> M >> K;
        vector<int> X(N), Y(M);
        for(int&x: X) cin >> x;
        for(int&y: Y) cin >> y;
        vector<map<int, int> > Xi(N), Yi(M);
        for(int i=0; i<K; ++i)
        {
            int a, b; cin >> a >> b;
            auto it1 = lower_bound(X.begin(), X.end(), a);
            auto it2 = lower_bound(Y.begin(), Y.end(), b);
            if(*it1 == a && *it2 == b) continue;
            if(*it1 != a) Xi[it1-X.begin()][b]++;
            if(*it2 != b) Yi[it2-Y.begin()][a]++;
        }
        long long ans = 0;
        for(const auto& x: Xi)
        {
            long long s = 0, s2 = 0;
            for(auto [a, b]: x)
            {
                s2 += 1LL*b*b;
                s += b;
            }
            ans += (s*s-s2)/2;
        }
        for(const auto& x: Yi)
        {
            long long s = 0, s2 = 0;
            for(auto [a, b]: x)
            {
                s2 += 1LL*b*b;
                s += b;
            }
            ans += (s*s-s2)/2;
        }
        cout << ans << '\n';
    }
}