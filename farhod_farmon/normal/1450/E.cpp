#include <bits/stdc++.h>
 
#define fi first
#define se second
 
const int N = 202;
 
using namespace std;
 
int inf = 1e9;
 
int n;
int m;
bool used[N];
vector < int > a;
vector < int > v[N];
vector < pair < int, int > > g[N];
 
void make(int x)
{
        for(int i = 1; i <= n; i++){
                a[i] = inf;
                used[i] = 0;
        }
        a[x] = 0;
        for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    for(int h: v[j]){
                        if(a[j] + 1 < a[h]){
                            a[h] = a[j] + 1;
                        }
                    }
                    for(auto h: g[j]){
                        if(a[j] + h.se < a[h.fi]){
                            a[h.fi] = a[j] + h.se;
                        }
                    }
                }
        }
}
 
int main()
{
        //freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
        ios_base::sync_with_stdio(0);
 
        cin >> n >> m;
        for(int i = 1; i <= m; i++){
                int x, y, z;
                cin >> x >> y >> z;
                if(z == 1){
                        g[x].push_back({y, 1});
                        g[y].push_back({x, -1});
                } else{
                        v[x].push_back(y);
                        v[y].push_back(x);
                }
        }
        a.resize(n + 1);
        vector < int > ca;
        int best = -1;
        for(int i = 1; i <= n; i++){
                make(i);
                bool good = true;
                int mn = a[1], mx = a[1];
                for(int j = 1; j <= n; j++){
                        for(int h: v[j]){
                                if(abs(a[h] - a[j]) != 1){
                                        good = false;
                                }
                        }
                        for(auto h: g[j]){
                                if(a[j] + h.se != a[h.fi]){
                                        good = false;
                                }
                        }
                        mn = min(mn, a[j]);
                        mx = max(mx, a[j]);
                }
                if(good){
                        if(mx - mn > best){
                                best = mx - mn;
                                ca = a;
                                for(int &x: ca){
                                        x -= mn;
                                }
                        }
                }
        }
        if(best == -1){
                cout << "NO" << "\n";
                return 0;
        }
        cout << "YES" << "\n";
        cout << best << "\n";
        for(int i= 1; i <= n; i++){
                cout << ca[i] << " ";
        }
}