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
int n,mx;
vi v;
mi f;
void solve(){
    cin>>n;
    rep(i,0,n){
        int x;
        cin>>x;
        f[x]++;
    }
    for(auto i:f) v.pb(i.y);
        sort(all(v));
    for(int i=sz(v)-1;i>=0;i--){
        rep(j,1,v[i]+1){
            int cur=i+1;
            int ans=0,cnt=1,ter=j;
            while(cur<sz(v)){
                int l=lower_bound(v.begin()+cur,v.end(),2*ter)-v.begin();
                if(l!=sz(v) and v[l]>=2*ter) cnt++;
                cur=l+1;
                ter*=2;
            }
            ans=((1<<cnt)-1)*j;
            mx=max(mx,ans);
        }
    }
    cout<<mx<<endl;
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