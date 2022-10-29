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
#define hell        100000000000000007LL
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,k,mn=hell,mx=-1,a,b;
void solve(){
    cin>>n>>k;
    cin>>a>>b;
    if(a>b) swap(a,b);
    rep(i,0,n+1){
        int l;
        l=b-a+i*k;
        if(a+l%k==b) mn=min(mn,n*k/__gcd(n*k,l));
        if(a+l%k==b) mx=max(mx,n*k/__gcd(n*k,l));
        l=k-a-b+i*k;
        if(k-a-l%k==b) mn=min(mn,n*k/__gcd(n*k,l));
        if(k-a-l%k==b) mx=max(mx,n*k/__gcd(n*k,l));
    }
    cout<<mn<<" "<<mx<<endl;
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