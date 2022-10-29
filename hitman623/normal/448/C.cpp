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
int n,a[5005];
int sol(int l,int r,int m){
    if(l>r) return 0;
    int d=min_element(a+l,a+r+1)-a;
    return min(r-l+1,sol(l,d-1,a[d])+sol(d+1,r,a[d])+a[d]-m);
}
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
    }
    cout<<sol(0,n-1,0)<<endl;
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