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
    int inc=0,dec=0;
    cin>>n;
    rep(i,0,n) cin>>a[i];
    rep(i,0,n) cin>>b[i];
    rep(i,0,n){
        if(a[i]<b[i]){
            if(inc==0){
                cout<<"NO"<<endl;
                return;
            }
        }
        else if(a[i]>b[i]){
            if(dec==0){
                cout<<"NO"<<endl;
                return;
            }
        }
        if(a[i]==1) inc++;
        if(a[i]==-1) dec++;
    }
    cout<<"YES"<<endl;
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