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
string s;
int f[10001];
void solve(){
    cin>>s;
    int n=sz(s);
    s+='b';
    rep(i,0,n){
        if(s[i]=='a' and s[i+1]=='b') f[i]=1;
        else if(s[i]=='b' and s[i+1]=='a') f[i]=1;
    }
    rep(i,0,n){
        if(f[i]) cout<<1<<" ";
        else cout<<0<<" ";
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