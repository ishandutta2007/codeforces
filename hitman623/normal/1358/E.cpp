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
int n,m,x,a[500005],s,suf[500005],sufmin[500005];
void solve(){
    cin>>n;
    m=(n+1)/2;
    rep(i,1,m+1){
        cin>>a[i];
        s+=a[i];
    }
    cin>>x;
    s+=(n-m)*x;
    if(s>0){
        cout<<n<<endl;
        return;
    }
    if(x>0){
        cout<<-1<<endl;
        return;
    }
    for(int i=m;i>=1;i--){
        suf[i]=a[i]-x+suf[i+1];
    }
    sufmin[1]=suf[1];
    rep(i,2,m+1) sufmin[i]=min(sufmin[i-1],suf[i]);
    int cur=(n-m)*x;
    for(int k=m;k>1;k--){
        cur+=a[k];
        if(cur<0) continue;
        if(sufmin[k-1]-suf[k]+cur>0){
            cout<<n-k+1<<endl;
            return;
        }
    }
    cout<<-1<<endl;
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