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
int n,k;
string s;
int f[200005][26];
void solve(){
    cin>>n>>k>>s;
    rep(i,0,k+1) memset(f[i],0,sizeof f[i]);
    rep(i,0,n/k){
        int l=i*k,r=(i+1)*k;
        rep(j,l,r){
            f[min(j-l+1,r-j)][s[j]-'a']++;
        }
    }
    int ans=0;
    rep(i,1,k+1){
        int mx=0;
        rep(j,0,26) mx=max(mx,f[i][j]);
        ans+=mx;
    }
    cout<<sz(s)-ans<<endl;
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