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
int n,m,val[2002],deg[2002],par[2002];
string s[2002];
vi a[2002];
int fp(int x){
    if(par[x]==x) return par[x];
    else return par[x]=fp(par[x]);
}
void merge(int x,int y){
    x=fp(x);
    y=fp(y);
    par[x]=y;
}
void solve(){
    cin>>n>>m;
    rep(i,1,n+m+1) par[i]=i;
    rep(i,0,n) cin>>s[i];
    rep(i,0,n){
        rep(j,0,m){
            if(s[i][j]=='='){
                merge(i+1,j+n+1);
            }
        }
    }
    rep(i,0,n){
        rep(j,0,m){
            int x=i+1,y=j+n+1;
            x=fp(x);
            y=fp(y);
            if(s[i][j]=='>'){
                a[y].pb(x);
                deg[x]++;
            }
            else if(s[i][j]=='<'){
                a[x].pb(y);
                deg[y]++;
            }
        }
    }
    int cnt=1;
    queue<int> q;
    rep(i,1,n+m+1) if(i==fp(i) and deg[fp(i)]==0) q.push(fp(i));
    while(!q.empty()){
        int d=sz(q);
        rep(_,0,d){
            int w=q.front();
            q.pop();
            val[w]=cnt;
            for(auto i:a[w]){
                deg[i]--;
                if(deg[i]==0){
                    q.push(i);
                }
            }
        }
        cnt++;
    }
    rep(i,1,n+m+1){
        val[i]=val[fp(i)];
        if(val[i]==0){
            cout<<"No"<<endl;
            return;
        }
    }
    int f=1;
    rep(i,0,n){
        rep(j,0,m){
            if(s[i][j]=='>' and val[i+1]<=val[j+n+1]) f=0;
            if(s[i][j]=='<' and val[i+1]>=val[j+n+1]) f=0;
            if(s[i][j]=='=' and val[i+1]!=val[j+n+1]) f=0;
        }
    }
    if(f==0){
        cout<<"No"<<endl;
        return;
    }
    cout<<"Yes"<<endl;
    rep(i,1,n+1) cout<<val[i]<<" ";
    cout<<endl;
    rep(i,n+1,n+m+1) cout<<val[i]<<" ";
    cout<<endl;
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