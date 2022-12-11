#include <bits/stdc++.h>
                  
using namespace std;
          
typedef long long ll;
#define mp make_pair
#define pb push_back
#define x first
#define y second
#define all(a) a.begin(), a.end()
#define db long double

int n;
vector<int> g[100007];

vector<pair<int, int> > t;
int dp[100007];
void dfs(int v){
    if (g[v].size() == 0) dp[v] = 1;
    for (int to : g[v]) {
        dfs(to);
        dp[v] += dp[to];
    }
    t.pb(mp(dp[v], v));
}

int main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output1.txt", "w", stdout);
    //ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for (int i = 1; i < n; i++){
        int p;
        cin >> p;
        p--;
        g[p].pb(i);
    }
    dfs(0);
    sort(all(t));
    for (int i = 0; i < t.size(); i++){
        cout << t[i].x << ' ';
    }
}