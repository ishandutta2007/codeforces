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
int n,m,a[200005],b[200005],driver[200005],l[200005],r[200005];
void solve(){
    cin>>n>>m;
    rep(i,1,n+m+1){
        cin>>a[i];
    }
    rep(i,1,n+m+1){
        cin>>b[i];
    }
    a[0]=-hell;
    a[n+m+1]=2*hell;
    int last=0;
    rep(i,1,n+m+1){
        if(b[i]==1) last=i;
        else l[i]=last;
    }
    last=n+m+1;
    for(int i=m+n;i>=1;i--){
        if(b[i]==1) last=i;
        else r[i]=last;
    }
    rep(i,1,n+m+1){
        if(b[i]==0){
            if(a[i]-a[l[i]]<=a[r[i]]-a[i]){
                driver[l[i]]++;
            }
            else driver[r[i]]++;
        }
    }
    rep(i,1,n+m+1){
        if(b[i]==1){
            cout<<driver[i]<<" ";
        }
    }
    cout<<endl;
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