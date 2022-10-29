#include <bits/stdc++.h>

#define ll          long long
#define pb          emplace_back
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
int n,a[2005];
set<int> s;
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
        a[i]=max(a[i],-a[i]);
        s.insert(a[i]);
    }
    vi v(all(s));
    reverse(all(v));
    rep(i,0,sz(v)){
        int l=0,r=0,ans=0;
        for(int j=n-1;j>=0;j--){
            if(a[j]==v[i]){
                ans+=r;
            }
            else if(abs(a[j])<v[i]) r++;
        }
        rep(j,0,n){
            if(abs(a[j])<v[i]){
                l++;
                r--;
            }
            else if(a[j]==v[i]){
                if(ans>ans+l-r){
                    ans=ans+l-r;
                    a[j]*=-1;
                }
                else break;
            }
        }
    }
    int ans=0;
    rep(i,0,n){
        rep(j,i+1,n){
            if(a[i]>a[j]) ans++;
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