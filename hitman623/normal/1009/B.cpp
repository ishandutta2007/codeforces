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
string s,ans;
int zero,ones;
void solve(){
    cin>>s;
    int n=sz(s);
    for(int i=n-1;i>=0;i--){
        if(s[i]=='1') ones++;
        else if(s[i]=='0') zero++;
        else{
            rep(j,0,zero){
                ans+='0';
            }
            zero=0;
            ans+='2';
        }
    }
    rep(i,0,ones){
        ans+='1';
    }
    rep(i,0,zero){
        ans+='0';
    }
    reverse(all(ans));
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