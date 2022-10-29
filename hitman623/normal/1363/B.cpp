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

void solve(){
    string s;
    cin>>s;
    int ones=0,zeros=0;
    for(auto i:s) if(i=='1') ones++; else zeros++;
    int o=0,z=0,ans=min(zeros,ones);
    rep(i,1,sz(s)+1){
        if(s[i-1]=='1') o++;
        else z++;
        ans=min(ans,i-z+sz(s)-i-(ones-o));
        ans=min(ans,i-(zeros-z)+sz(s)-i-o);
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