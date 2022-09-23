#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 1000100;
const int mod = 1e9 + 7;

using namespace std;

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        int n;
        cin >> n;
        vector < pair < long double, pair < long double, int > > > res;
        for(int i = 1; i <= n; i++){
                int x;
                cin >> x;
                res.push_back({x, {x, 1}});
                int l = res.size();
                while(l > 1 && res[l - 1].fi < res[l - 2].fi){
                        auto p = res.back();
                        res.pop_back();
                        p.se.fi += res.back().se.fi;
                        p.se.se += res.back().se.se;
                        res.pop_back();
                        p.fi = p.se.fi / p.se.se;
                        res.push_back(p);
                        l -= 1;
                }
        }
        for(auto p: res){
                for(int i = 0; i < p.se.se; i++){
                        cout << fixed << setprecision(9) << p.fi << '\n';
                }
        }
}