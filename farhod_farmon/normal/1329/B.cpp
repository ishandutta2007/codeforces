#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 111;
const int mod = 998244353;

using namespace std;

int D, m;
long long d[N];

void solve()
{
        cin >> D >> m;
        vector < long long > v;
        for(long long i = 1; i <= D; i *= 2){
                long long j = i * 2 - 1;
                j = min(j, (long long)D);
                v.push_back(j - i + 1);
        }
        int n = v.size();
        for(int i = 0; i < n; i++) d[i] = 0;
        long long res = 0;
        for(int i = 0; i < n; i++){
                v[i] %= m;
                d[i] = v[i];
                for(int j = 0; j < i; j++) d[i] += d[j] * v[i] % m;
                d[i] %= m;
                res += d[i];
        }
        cout << res % m << "\n";
}

int main()
{
        ios_base::sync_with_stdio(0);

        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        int t;
        cin >> t;
        while(t--) solve();

}