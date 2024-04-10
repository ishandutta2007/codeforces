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
int n,m,k;
void solve(){
    cin>>n>>m>>k;
    rep(i,0,k){
        int x,y;
        cin>>x>>y;
    }
    rep(i,0,k){
        int x,y;
        cin>>x>>y;
    }
    string s;
    rep(i,0,n) s+='U';
    rep(i,0,m) s+='L';
    rep(w,0,m){
        rep(i,0,n-1) s+='D';
        w++;
        if(w<m){
            s+='R';
            rep(i,0,n-1) s+='U';
            w++;
            if(w<m) s+='R';
        }
        w--;
    }
    cout<<sz(s)<<endl<<s<<endl;
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