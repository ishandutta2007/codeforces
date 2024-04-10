#include <bits/stdc++.h>
#include <cmath>
#include <regex>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ba back
#define ppb pop_back
#define eb emplace_back
#define eps 1e-6
#define vll vector< int>
#define pll pair< int, int>
#define pqb             priority_queue<ll>
#define pqs             priority_queue<ll,vll,greater<ll> >
#define sz(x) (int((x.size())))
#define all(x) (x).begin(),(x).end()
#define FAST ios_base :: sync_with_stdio (false); cin.tie (NULL)
#define fo(i,s,n) for(int i=s;i<n;i++)
using namespace std;
typedef  int ll;

//------------------------------MOD-Operations--------------------------------------------------------------------------------------------------------------------------------------------//
const ll M = 1e9 + 7;
const ll N = 2e5 + 5;
ll n;
char ar[51][51];
vector<pll> adj[51][51];
vector<vector<bool> > vis(51, vector<bool>(51, 0));
bool check(int i , int j){
    // cout<<i<<" "<<j<<endl;
    return (i<=n && i>=1 && j>=1 && j<=n && ar[i][j]=='0'); 
}
void bfs(pll cur, vector<pll> &v){
    queue<pll> q;
    q.push(cur);
    while(!q.empty()){  
        ll i=q.front().fi;
        ll j=q.front().se;
        q.pop();
        if(vis[i][j]) continue;
        vis[i][j]=1;
        v.pb({i,j});
        for(auto nb:adj[i][j]){
            if(!vis[nb.fi][nb.se]) q.push(nb);
        }   
    }
    
}

int main(){
    FAST;
 cin>>n;
 pll st; cin>>st.fi; cin>>st.se;
 pll en; cin>>en.fi; cin>>en.se;
 fo(i,1,n+1){
     fo(j,1,n+1){
        cin>>ar[i][j]; 
     }
 }
 fo(i,1,n+1){
     fo(j,1,n+1){
         adj[i][j].clear();
         if(ar[i][j]=='1')continue;
        ll dx[]={-1,0,1,0};
        ll dy[]={0,-1,0,1};
        fo(k,0,4){
            ll ni=i+dx[k];
            ll nj=j+dy[k];
            if(check(ni,nj)){ 
                // cout<<i<<" "<<j<<" "<<ni<<" "<<nj<<endl;
                 adj[i][j].pb({ni,nj});}
        }
     }
 }
//  fo(i,0,adj[1][1].size())cout<<adj[1][1][i].fi<<" "<<adj[1][1][i].se<<endl;
//  cout<<endl;
 vector<pll> in,out;
bfs(st,in);
if(!vis[en.fi][en.se]) bfs(en,out);
if(out.size()==0){cout<<0; return 0;}
ll mn=INT_MAX;
// cout<<in.size()<<" "<<out.size()<<endl;
fo(i,0,in.size()){  
    fo(j,0,out.size()){
        // cout<<in[i].fi<<" "<<in[i].se<<endl;
        //  cout<<out[j].fi<<" "<<out[j].se<<endl;
        
    ll dis=(in[i].fi-out[j].fi)*(in[i].fi-out[j].fi)+(in[i].se-out[j].se)*(in[i].se-out[j].se);
     mn=min(mn,dis);
    }
}
cout<<mn;



}