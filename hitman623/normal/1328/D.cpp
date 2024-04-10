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
int n,c[200005],a[200005];
void solve(){
    cin>>n;
    int diff=0;
    rep(i,0,n){
        cin>>c[i];
        if(c[i]!=c[0]) diff=1;
    }
    if(diff==0){
        cout<<1<<endl;
        rep(i,0,n) cout<<1<<" ";
        cout<<endl;
        return; 
    }
    int g=0;
    rep(i,0,n) if(c[i]==c[(i+1)%n]) g=(i+1)%n;
    rep(i,0,n) a[(g+i)%n]=i%2+1;
    int w=2;
    rep(i,0,n){
        if(c[i]!=c[(i+1)%n] and a[i]==a[(i+1)%n]) a[i]=3,w=3;
    }
    cout<<w<<endl;
    rep(i,0,n) cout<<a[i]<<" ";
    cout<<endl;
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