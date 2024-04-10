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
int n,f=0,a[100005];
void solve(){
    cin>>n;
    rep(i,0,n) cin>>a[i];
    rep(i,0,n){
        if(a[i]%2==0) a[i]/=2;
        else if(f){
            if(a[i]<0) a[i]=(a[i]-1)/2;
            else a[i]/=2;
            f=0;
        }
        else{
            a[i]=(a[i]+1)/2;
            f=1;
        }
        cout<<a[i]<<endl;
    }
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