#include <bits/stdc++.h>

#define fi first
#define se second

const int N = 300300;
const long long mod = 998244353;

using namespace std;

int n;
int x[N];
int y[N];

int dist(pair < int, int > x, pair < int, int > y)
{
        return abs(x.fi - y.fi) + abs(x.se - y.se);
}

int get(vector < pair < int, int > > v)
{
        int cnt = 0;
        for(int i = 0; i < v.size(); i++){
                cnt += dist(v[i], v[(i + 1) % (int)v.size()]);
        }
        return cnt;
}

void solve()
{
        cin >> n;
        vector < pair < int, int > > v;
        if(n == 3){
                for(int i = 1; i <= n; i++){
                        cin >> x[i] >> y[i];
                        v.push_back({x[i], y[i]});
                }
                cout << get(v) << "\n";
                return;
        }
        for(int i = 1; i <= n; i++){
                cin >> x[i] >> y[i];
                if(i == 1){
                        v.push_back({x[i], y[i]});
                        v.push_back({x[i], y[i]});
                        v.push_back({x[i], y[i]});
                        v.push_back({x[i], y[i]});
                }
                else{
                        if(y[i] < v[0].se){
                                v[0] = {x[i], y[i]};
                        }
                        if(x[i] > v[1].fi){
                                v[1] = {x[i], y[i]};
                        }
                        if(y[i] > v[2].se){
                                v[2] = {x[i], y[i]};
                        }
                        if(x[i] < v[3].fi){
                                v[3] = {x[i], y[i]};
                        }
                }
        }
        {
                int ans = 0;
                for(int i = 0; i < v.size(); i++){
                        for(int j = i + 1; j < v.size(); j++){
                                vector < pair < int, int > > g;
                                g.push_back(v[i]);
                                g.push_back(v[j]);
                                for(int h = 1; h <= n; h++){
                                        if(x[h] == v[i].fi && y[h] == v[i].se){
                                                continue;
                                        }
                                        if(x[h] == v[j].fi && y[h] == v[j].se){
                                                continue;
                                        }
                                        g.push_back({x[h], y[h]});
                                        ans = max(ans, get(g));
                                        g.pop_back();
                                }
                        }
                }
                cout << ans << " ";
        }
        int ans = get(v);
        for(int i = 4; i <= n; i++){
                cout << ans << " ";
        }
}

int main()
{
        //freopen("input.txt","r",stdin);
        //freopen("output.txt","w",stdout);
        ios_base::sync_with_stdio(0);

        int test = 1;
        while(test--){
                solve();
        }
}