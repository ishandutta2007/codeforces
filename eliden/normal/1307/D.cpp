#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define debug(x) cerr<<#x<<": "<<x<<endl
using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m,k;
    cin>>n>>m>>k;
    vector<int> special(k);
    rep(i,0,k) {
        cin>>special[i];
        --special[i];
    }
    vector<vector<int>> g(n);
    rep(i,0,m) {
        int x,y;
        cin>>x>>y;
        --x;--y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    vector<int> source{0,n-1};
    const int INF=1e9;
    vector<vector<int>> dist(2,vector<int>(n,INF));
    rep(it,0,2) {
        queue<pair<int,int>> q;
        q.emplace(source[it],0);
        dist[it][source[it]] = 0;
        while(!q.empty()) {
            int i, d;
            tie(i,d) = q.front();
            q.pop();
            for(int v:g[i]) {
                if(dist[it][v]==INF) {
                    dist[it][v] = d+1;
                    q.emplace(v, d+1);
                }
            }
        }
    }
    vector<int> mx(2,INF);
    vector<pair<int,int>> a;
    for(int j:special) {
        int x = dist[0][j], y = dist[1][j];
        a.emplace_back(y-x, x);
    }
    sort(all(a));
    int best=0, acc=0;
    rep(i,0,k) {
        if(i>0) {
            best=max(best,a[i].second+acc);
        }
        acc=max(acc,a[i].first+a[i].second);
    }
    int ans = min(dist[0][n-1],best+1);
    cout<<ans<<"\n";
}