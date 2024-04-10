#include <bits/stdc++.h>

#define int         long long
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
int n,a,b;
string s;
void solve(){
    cin>>n>>a>>b>>s;
    int ans=2*(n+1)*b+(n+2)*a;
    int f=0;
    rep(i,0,n){
        if(s[i]=='0'){
            ans-=b;
        }
        else{
            f=i;
            break;
        }
    }
    if(f==0){
        cout<<n*a+(n+1)*b<<endl;
        return;
    }
    while(s.back()=='0'){
        ans-=b;
        s.pop_back();
    }
    vii v;
    rep(i,f,sz(s)){
        if(sz(v)==0 or v.back().x!=s[i]-'0'){
            v.pb({s[i]-'0',1});
        }
        else v.back().y++;
    }
    for(auto i:v){
        if(i.x==0){
            ans+=min(0LL,2*a-(i.y-1)*b);
        }
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}