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
int n,k,a,b,x[100005];
int sol(int l,int r){
    int pos1=lower_bound(x,x+k,l)-x;
    int pos2=upper_bound(x,x+k,r)-x;
    if(l==r){
        if(binary_search(x,x+k,l)) return b*(pos2-pos1);
        else return a;
    }
    if(pos1<k and x[pos1]>=l and x[pos1]<=r) return min((pos2-pos1)*b*(r-l+1),sol(l,(l+r)/2)+sol((l+r)/2+1,r));
    else return a;
}
void solve(){
    cin>>n>>k>>a>>b;
    rep(i,0,k) cin>>x[i];
    sort(x,x+k);
    cout<<sol(1,1LL<<n)<<endl;
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