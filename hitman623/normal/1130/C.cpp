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
int n,r1,c1,r2,c2,ans=hell;
pii par[55][55];
string s[55];
pii fp(pii x){
    if(par[x.x][x.y]==x) return x;
    else return par[x.x][x.y]=fp(par[x.x][x.y]);
}
void merge(pii a,pii b){
    a=fp(a);
    b=fp(b);
    par[a.x][a.y]=b;
}
void solve(){
    cin>>n>>r1>>c1>>r2>>c2;
    rep(i,0,n){
        rep(j,0,n){
            par[i][j]={i,j};
        }
    }
    r1--,c1--,r2--,c2--;
    rep(i,0,n) cin>>s[i];
    rep(i,0,n){
        rep(j,0,n){
            if(s[i][j]=='1' or i+j==0) continue;
            if(i and s[i-1][j]=='0') merge({i,j},{i-1,j});
            if(j and s[i][j-1]=='0') merge({i,j},{i,j-1}); 
        }
    }
    rep(i,0,n){
        rep(j,0,n){
            rep(k,0,n){
                rep(l,0,n){
                    if(fp({i,j})==fp({r1,c1}) and fp({k,l})==fp({r2,c2})){
                        ans=min(ans,(k-i)*(k-i)+(l-j)*(l-j));
                    }
                }
            }
        }
    }
    cout<<ans<<endl;
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