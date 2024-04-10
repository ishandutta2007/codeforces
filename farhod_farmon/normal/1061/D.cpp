#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int Q = 1000100;
const long long mod = 1e9 + 7;

using namespace std;

int n;
long long x;
long long y;

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> x >> y;
        long long ans = 0;
        vector < pair < long long, int > > v;
        for(int i = 1; i <= n; i++){
                int l, r;
                cin >> l >> r;
                ans = (ans + (r - l) * y) % mod;
                v.push_back({l, -2});
                v.push_back({r, -1});
        }
        sort(v.begin(), v.end());
        vector < int > g;
        g.push_back(-1e9 - 1);
        for(auto p: v){
                if(p.se == -1){
                        g.push_back(p.fi);
                        continue;
                }
                if(y * (p.fi - g.back()) < x){
                        ans += y * (p.fi - g.back());
                        g.pop_back();
                }
                else{
                        ans += x;
                }
                if(ans >= mod){
                        ans -= mod;
                }
        }
        cout << ans << "\n";
}