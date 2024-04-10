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
int n,a[200005];
void solve(){
    cin>>n;
    rep(i,1,n+1) cin>>a[i];
    int l=1,r=n,cnt=0;
    while(l<=n and a[l]==l) l++;
    while(r>=1 and a[r]==r) r--;
    rep(i,l,r+1) if(a[i]==i) cnt++;
    if(l==n+1) cout<<0<<endl;
    else if(cnt) cout<<2<<endl;
    else cout<<1<<endl;
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