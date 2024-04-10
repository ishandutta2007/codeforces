#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 50500;
const long long mod = 1e9 + 7;

using namespace std;

int n;
int a[N];

vector < pair < int, int > > solve(vector < pair < int, int > > &v)
{
        vector < pair < int, int > > res;
        for(int i = (int)v.size() - 1; i >= 0; i--){
                if(res.empty() || v[i].se < res.back().fi){
                        res.push_back(v[i]);
                }
        }
        return res;
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n;
        for(int i = 1; i <= n; i++){
                cin >> a[i];
        }
        vector < pair < int, pair < int, int > > > v;
        for(int i = 1; i <= n; i++){
                int s = 0;
                for(int j = i; j <= n; j++){
                        s += a[j];
                        v.push_back({s, {i, j}});
                }
        }
        sort(v.begin(), v.end());
        vector < pair < int, int > > res, g;
        for(int i = 0; i < v.size(); i++){
                g.push_back(v[i].se);
                if(i + 1 < v.size() && v[i].fi == v[i + 1].fi){
                        continue;
                }
                auto gg = solve(g);
                if(gg.size() > res.size()){
                        res = gg;
                }
                g.clear();
        }
        cout << res.size() << "\n";
        for(auto p: res){
                cout << p.fi << " " << p.se << "\n";
        }
}