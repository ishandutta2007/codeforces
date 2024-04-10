#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 220;
const long long mod = 998244353;

using namespace std;

int n;
int m;
int a[N][N];

pair < string, string > solve(int k)
{
        string s = "", t = "";
        for(int i = 1; i <= m; i++){
                int need = (i <= k) ^ 1;
                if(a[1][i] != need){
                        t += "1";
                } else{
                        t += "0";
                }
        }
        vector < pair < int, int > > v;
        if(k < m){
                v.push_back({0, 1});
        } else{
                v.push_back({0, 0});
        }
        for(int i = 2; i <= n; i++){
                vector < int > g;
                for(int j = 1; j <= m; j++){
                        int x = a[i][j] ^ (t[j - 1] - '0');
                        if(g.empty() || x != g.back()){
                                g.push_back(x);
                        }
                }
                if(g.size() == 1){
                        g.push_back(g.back());
                }
                if(g.size() > 2){
                        return {"", ""};
                }
                v.push_back({g[0], g[1]});
        }
        int cnt = 0;
        for(auto p: v){
                cnt += p.fi ^ p.se;
        }
        if(cnt > 1){
                return {"", ""};
        }
        int cur = 0;
        for(auto p: v){
                if(cur == 0){
                        if(p.fi){
                                s += "1";
                                p.se ^= 1;
                        } else{
                                s += "0";
                        }
                        cur = p.se;
                } else{
                        if(p.fi){
                                s += "0";
                        } else{
                                s += "1";
                                p.se ^= 1;
                        }
                        assert(p.se == 1);
                }
        }
        return {s, t};
}

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= m; j++){
                        cin >> a[i][j];
                }
        }
        for(int i = 1; i <= m; i++){
                auto res = solve(i);
                if(res.fi != ""){
                        cout << "YES" << "\n";
                        cout << res.fi << "\n";
                        cout << res.se << "\n";
                        return 0;
                }
        }
        cout << "NO" << "\n";
}