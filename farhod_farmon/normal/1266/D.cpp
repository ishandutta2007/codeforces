#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 100100;
const int mod = 1e9 + 7;

using namespace std;

int n;
int m;
long long in[N];
long long out[N];

int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);

        ios_base::sync_with_stdio(0);

        cin >> n >> m;
        for(int i = 1; i <= m; i++){
                int x, y, w;
                cin >> x >> y >> w;
                out[x] += w;
                in[y] += w;
        }

        vector < int > v;
        for(int i = 1; i <= n; i++){
                long long g = min(in[i], out[i]);
                in[i] -= g;
                out[i] -= g;

                if(in[i] > 0){
                        v.push_back(i);
                }
        }
        vector < pair < pair < int, int >, long long > > res;
        for(int i = 1; i <= n; i++){
                while(out[i] > 0){
                        int j = v.back();
                        if(j == i){
                                v.pop_back();
                                j = v.back();
                                long long g = min(out[i], in[j]);

                                out[i] -= g;
                                in[j] -= g;
                                res.push_back({{i, j}, g});
                                if(in[j] == 0){
                                        v.pop_back();
                                }
                                v.push_back(i);
                        } else{
                                long long g = min(out[i], in[j]);

                                out[i] -= g;
                                in[j] -= g;
                                res.push_back({{i, j}, g});
                                if(in[j] == 0){
                                        v.pop_back();
                                }
                        }
                }
        }

        cout << res.size() << "\n";
        for(auto p: res){
                cout << p.fi.fi << ' ' << p.fi.se << " " << p.se << "\n";
        }
}