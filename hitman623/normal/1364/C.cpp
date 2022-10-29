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
int n,a[100005],b[100005];
void solve(){
    vi empty;
    cin>>n;
    rep(i,1,n+1) cin>>a[i];
    for(int i=n;i>1;i--){
        if(a[i]!=a[i-1]){
            b[i]=a[i-1];
        }
    }
    if(a[1]==1) b[1]=0;
    else empty.pb(1);
    rep(i,2,n+1){
        if(a[i]!=a[i-1]){
            b[i]=a[i-1];
            int cur=a[i]-1;
            while(cur!=b[i]){
                if(sz(empty)==0){
                    cout<<-1<<endl;
                    return;
                }
                b[empty.back()]=cur;
                empty.pop_back();
                cur--;
            }
        }
        else empty.pb(i);
    }
    while(!empty.empty()){
        b[empty.back()]=n+2;
        empty.pop_back();
    }
    rep(i,1,n+1) cout<<b[i]<<" ";
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