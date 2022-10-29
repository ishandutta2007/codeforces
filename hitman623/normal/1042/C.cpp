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
int n,a[200005],cnt;
vii neg,pos;
vi zero;
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
        if(a[i]<0){
            neg.pb({-a[i],i+1});
        }
        else if(a[i]==0){
            zero.pb(i+1);
        }
        else{
            pos.pb({a[i],i+1});
        }
    }
    sort(all(neg));
    sort(all(pos));
    rep(i,1,sz(zero)){
        cout<<1<<" "<<zero[i]<<" "<<zero[0]<<endl;
        cnt++;
    }
    if(cnt==n-1) return;
    if(sz(neg)%2){
        if(sz(zero)){
            cout<<1<<" "<<zero[0]<<" "<<neg[0].y<<endl;
            cnt++;
        }
        if(cnt==n-1) return;
        cout<<2<<" "<<neg[0].y<<endl;
        cnt++;
        if(cnt==n-1) return;
        int root=0;
        if(sz(pos)) root=pos[0].y;
        else root=neg[1].y;
        for(auto i:neg){
            if(i.y==root || i.y==neg[0].y) continue;
            cout<<1<<" "<<i.y<<" "<<root<<endl;
        }
        for(auto i:pos){
            if(i.y==root) continue;
            cout<<1<<" "<<i.y<<" "<<root<<endl;
        }
    }
    else if(sz(zero)){
        int root=0;
        cout<<2<<" "<<zero[0]<<endl;
        if(sz(pos)) root=pos[0].y;
        else root=neg[0].y;
        for(auto i:neg){
            if(i.y==root) continue;
            cout<<1<<" "<<i.y<<" "<<root<<endl;
        }
        for(auto i:pos){
            if(i.y==root) continue;
            cout<<1<<" "<<i.y<<" "<<root<<endl;
        }
    }
    else{
        int root=0;
        if(sz(pos)) root=pos[0].y;
        else root=neg[0].y;
        rep(i,1,n+1){
            if(i==root) continue;
            cout<<1<<" "<<i<<" "<<root<<endl;
        }
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