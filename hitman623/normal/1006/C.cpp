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
#define hell        998244353
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,a[200005],p[200005],s[200005];
mi fp,fs;
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
        p[i]=a[i];
        if(i) p[i]+=p[i-1];
        fp[p[i]]=i;
    }
    for(int i=n-1;i>=0;i--){
        s[i]=a[i]+s[i+1];
        fs[s[i]]=i;
    }
    int ans=0;
    rep(i,0,n){
        if(fs.count(p[i]) and fs[p[i]]>i){
            ans=max(ans,p[i]);
        }
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}