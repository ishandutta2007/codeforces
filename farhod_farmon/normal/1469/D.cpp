#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 200300;
const int mod = 998244353;

using namespace std;


int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);


        int t;
        cin >> t;
        while(t--){
                int n;
                cin >> n;
                vector < pair < int, int > > res;
                vector < int > v;
                vector < int > ban(n + 1, 0);
                v.push_back(n);
                while(v.back() > 2){
                        v.push_back(sqrt(v.back() * 1.0) + 1 - 1e-9);
                }
                for(int x: v){
                        ban[x] = 1;
                }
                for(int i = 1; i <= n; i++){
                        if(!ban[i]){
                                res.push_back({i, n});
                        }
                }

                for(int i = 0; i + 1 < (int)v.size(); i++){
                        assert((v[i] - 1) / v[i + 1] + 1 <= v[i + 1]);
                        res.push_back({v[i], v[i + 1]});
                        res.push_back({v[i], v[i + 1]});
                }

                assert((int)res.size() <= n + 5);
                cout << res.size() << "\n";
                for(auto p: res){
                        cout << p.fi << " " << p.se << "\n";
                }
        }
}