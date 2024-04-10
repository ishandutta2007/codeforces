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
int n,q,a[5005],ans,l[5005],r[5005],cnt1[5005];
void solve(){
    cin>>n>>q;
    rep(i,0,q){
        cin>>l[i]>>r[i];
        rep(j,l[i],r[i]+1){
            a[j]++;
        }
    }
    rep(i,0,q){
        int cur=0;
        rep(j,l[i],r[i]+1){
            a[j]--;
        }
        rep(j,1,n+1){
            if(a[j]) cur++;
            cnt1[j]=cnt1[j-1]+(a[j]==1);
        }
        rep(j,0,q){
            if(j==i) continue;
            ans=max(ans,cur-(cnt1[r[j]]-cnt1[l[j]-1]));
        }
        rep(j,l[i],r[i]+1){
            a[j]++;
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