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
int mu[7007];
void process_seive(int n){
    rep(i,0,n+1) mu[i]=1;
    for(int i=2;i*i<=n;i++){
        for(int j=i*i;j<=n;j+=i*i){
            mu[j]=0;
        }
    }
}
int n,q;
vector<bitset<7001>> w;
bitset<7001> g[7007];
void solve(){
    process_seive(7006);
    cin>>n>>q;
    w.resize(n+1);
    rep(i,1,7001){
        for(int j=i;j<=7000;j+=i){
            g[i][j]=mu[j/i];
        }
    }
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int x,v;
            cin>>x>>v;
            w[x].reset();
            for(int i=1;i*i<=v;++i){
                if(v%i==0) w[x][i]=w[x][v/i]=1;
            }
        }
        else if(type==2){
            int x,y,z;
            cin>>x>>y>>z;
            w[x]=w[y]^w[z];
        }
        else if(type==3){
            int x,y,z;
            cin>>x>>y>>z;
            w[x]=w[y]&w[z];
        }
        else{
            int x,v;
            cin>>x>>v;
            cout<<(w[x]&g[v]).count()%2;
        }
    }
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