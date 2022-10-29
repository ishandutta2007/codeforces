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
#define hell        1000000000000000007LL
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,a,r,m,h[100005];
void solve(){
    int s=0;
    cin>>n>>a>>r>>m;
    rep(i,1,n+1){
        cin>>h[i];
        s+=h[i];
    }
    sort(h+1,h+n+1);
    int lef=0,ans=hell;
    rep(i,1,n+1){
        lef+=h[i];
        s-=h[i];
        auto get=[lef,s,i](int w){
            int rem=s-(n-i)*w;
            int add=w*i-lef;
            int d=min(add,rem);
            return min(add*a+rem*r,d*m+(add-d)*a+(rem-d)*r);
        };
        ans=min(ans,get(h[i]));
        int hh=(s+lef)/n;
        if(i+1<=n and hh>=h[i] and hh<=h[i+1]) ans=min(ans,get(hh));
        hh++;
        if(i+1<=n and hh>=h[i] and hh<=h[i+1]) ans=min(ans,get(hh));
    }
    cout<<ans<<endl;
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