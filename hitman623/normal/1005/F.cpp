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
int n,m,k,x[200005],y[200005],vis[200005];
vi a[200005],par[200005];
string s;
mii mp;
vector<string> res;
void sol(int in){
    if(in==n+1){
        res.pb(s);
        if(sz(res)==k){
            cout<<k<<endl;
            for(auto i:res){
                cout<<i<<endl;
            }
            exit(0);
        }
    }
    for(auto i:par[in]){
        s[mp[{in,i}]]='1';
        sol(in+1);
        s[mp[{in,i}]]='0';
    }
}
void solve(){
    cin>>n>>m>>k;
    rep(i,0,m){
        cin>>x[i]>>y[i];
        a[x[i]].pb(y[i]);
        a[y[i]].pb(x[i]);
        mp[{x[i],y[i]}]=i;
        mp[{y[i],x[i]}]=i;
        s+='0';
    }
    queue<int> q;
    q.push(1);
    par[1].pb(-1);
    vis[1]=2;
    while(1){
        set<int> st;
        while(!q.empty()){
            int d=q.front();
            q.pop();
            for(auto i:a[d]){
                if(vis[i]!=2){
                    par[i].pb(d);;
                    vis[i]=1;
                    st.insert(i);
                }
            }
        }
        for(auto i:st){
            q.push(i);
            vis[i]=2;
        }
        if(sz(q)==0) break;
    }
    sol(2);
    cout<<sz(res)<<endl;
    for(auto i:res){
        cout<<i<<endl;
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