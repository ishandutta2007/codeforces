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
int n,x,a[100005];
void solve(){
    int s=0;
    cin>>n>>x;
    rep(i,1,n+1){
        cin>>a[i];
        a[i]%=x;
        s+=a[i];
        s%=x;
    }
    if(s) cout<<n<<endl;
    else{
        int l=0,r=0;
        rep(i,1,n+1){
            if(a[i]){
                l=i;
                break;
            }
        }
        for(int i=n;i>=1;i--){
            if(a[i]){
                r=n-i+1;
                break;
            }
        }
        if(l and r) cout<<n-min(l,r)<<endl;
        else if(l) cout<<n-l<<endl;
        else if(r) cout<<n-r<<endl;
        else cout<<-1<<endl;
    }
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