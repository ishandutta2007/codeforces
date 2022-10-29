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
int n,k,ones[1000006],zeros[1000006];
string s;
vi v[1000006];
void solve(){
    int ans=0,tot=0;
    cin>>n>>k>>s;
    rep(i,0,n) v[i].clear();
    for(auto i:s) if(i=='1') tot++;
    rep(i,0,n) v[i%k].pb((s[i]=='1')-(s[i]=='0'));
    rep(i,0,k){
        int cur=0;
        for(auto j:v[i]){
            cur+=j;
            if(cur<0) cur=0;
            ans=max(ans,cur);
        }
    }
    cout<<tot-ans<<endl;
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