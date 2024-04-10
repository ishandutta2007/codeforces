#include <bits/stdc++.h>

#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,m,p,ans[10],s[10];
int vis[1001][1001];
string a[1001];
queue<pair<int,pii>> q[10],temp;
void solve(){
    cin>>n>>m>>p;
    rep(i,1,p+1) cin>>s[i];
    rep(i,0,n) cin>>a[i];
    rep(i,0,n){
        rep(j,0,m){
            if(isdigit(a[i][j])){
                q[a[i][j]-'0'].push({0,{i,j}});
            }
        }
    }
    while(1){
        bool done=1;
        rep(i,1,p+1){
            while(!q[i].empty()){
                auto d=q[i].front();
                q[i].pop();
                if(vis[d.y.x][d.y.y]) continue;
                if(d.x==s[i]+1) temp.push({1,d.y});
                else{
                    vis[d.y.x][d.y.y]=1;
                    ans[i]++;
                    rep(x,-1,2){
                        rep(y,-1,2){
                            if(abs(x)+abs(y)==1 and x+d.y.x>=0 and x+d.y.x<n and y+d.y.y>=0 and y+d.y.y<m and !vis[d.y.x+x][d.y.y+y] and a[d.y.x+x][d.y.y+y]=='.'){
                                q[i].push({d.x+1,{d.y.x+x,d.y.y+y}});
                            }
                        }
                    }
                }
            }
            if(!temp.empty()){
                swap(q[i],temp);
                done=0;
            }
        }
        if(done) break;
    }
    rep(i,1,p+1) cout<<ans[i]<<" ";
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}