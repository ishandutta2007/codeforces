#include <bits/stdc++.h>
 
#define fi first
#define se second
#define ll long long
#define dl double long
 
using namespace std;
 
const int N = 1e6 + 7;
const long long mod = 998244353;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int n;
int f[N];
int s[N];
int pa[N];
bool used[N];
vector<int> g;
map<pair<int, int> , int> mp;
vector<pair<int, int>> v[N];
 
void dfs(int x , int p)
{
    s[x] = 1;
    g.push_back(x);
    for(auto z : v[x]){
        int y = z.fi;
        if(y == p || used[z.se])continue;
        pa[y] = x;
        dfs(y , x);
        s[x] += s[y];
    }
}
 
void foo(int st)
{
    g.clear();
    dfs(st , st);
    if((int)g.size() <= 3)return;
    int gg = 0;
    for(int i = 1; i < N; i++){
        if(f[i] == s[st]){
            gg = i;
            break;
        }
    }
    if(gg == 0){
        cout << "NO";
        exit(0);
    }
    int ok = 0;
    for(auto x : g){
        if(s[x] == f[gg - 1] || s[x] == f[gg - 2]){
            assert(mp.find({x , pa[x]}) != mp.end());
            assert(used[mp[make_pair(x , pa[x])]] == false);
            used[mp[{x , pa[x]}]] = true;
            foo(pa[x]);
            foo(x);
            ok = 1;
            break;
        }
    }
    if(!ok){
        cout << "NO";
        exit(0);
    }
}
 
void solve()
{
    f[0] = f[1] = 1;
    cin >> n;
    for(int i = 1; i < n; i++){
        int x,y;
        cin >> x >> y;
        v[x].push_back({y , i});
        v[y].push_back({x , i});
        mp[{x , y}] = mp[{y , x}] = i;
    }
    if(n <= 3){
        cout << "YES";
        return;
    }
    int ok = -1;
    for(int i = 2; i < N; i++){
        f[i] = f[i - 1] + f[i - 2];
        if(f[i] == n){
            ok = i;
        }
        if(f[i] > n)break;
    }
    if(ok == -1){
        cout << "NO";
        return;
    }
    foo(1);
    cout << "YES";
}
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen( "input.txt" , "r" , stdin );
    //freopen( "output.txt" , "w" , stdout );
 
    int T = 1;
    //cin >> T;
    while( T-- ){
        solve();
    }
}