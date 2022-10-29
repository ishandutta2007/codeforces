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
int n,ans;
map<string,vi> v;
void solve(){
    cin>>n;
    rep(i,0,n){
        string s;
        int x;
        cin>>s>>x;
        v[s].pb(x);
    }
    for(auto &i:v){
        sort(all(i.y));
        reverse(all(i.y));
        rep(j,1,sz(i.y)){
            i.y[j]+=i.y[j-1];
        }
    }
    int d=sz(v["11"]);
    rep(a,0,sz(v["00"])+1){
        if(d<a) break;
        int x=d-a;
        int b=sz(v["01"]);
        int c=sz(v["10"]);
        if(b>c+x){
            b=c+x;
        }
        else if(b<c-x){
            c=b+x;            
        }
        if(c+d>=a+b and b+d>=a+c){
            ans=max(ans,(sz(v["11"])?v["11"].back():0)+(a?v["00"][a-1]:0)+(b?v["01"][b-1]:0)+(c?v["10"][c-1]:0));
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