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
int n,a[200005],b[200005];
vi can;
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>a[i]>>b[i];
    }
    for(int i=2;i*i<=a[0];++i){
        if(a[0]%i==0){
            while(a[0]%i==0) a[0]/=i;
            can.pb(i);
        }
    }
    if(a[0]>1) can.pb(a[0]);

    for(int i=2;i*i<=b[0];++i){
        if(b[0]%i==0){
            while(b[0]%i==0) b[0]/=i;
            can.pb(i);
        }
    }
    if(b[0]>1) can.pb(b[0]);
    for(auto i:can){
        int f=1;
        rep(j,1,n){
            if(a[j]%i==0 or b[j]%i==0) continue;
            f=0;
        }
        if(f){
            cout<<i<<endl;
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