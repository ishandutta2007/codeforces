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
int n,ans;
int fx[100001],fy[100001],sx[100001],sy[100001],d1,d2;
int ham(int a,int b){
    return a*a+b*b;
}
float ham(float a,float b){
    return a*a+b*b;
}
void solve(){
    cin>>n>>d1>>d2;
    d1*=d1;
    d2*=d2;
    rep(i,0,n){
        cin>>fx[i]>>fy[i]>>sx[i]>>sy[i];
    }
    int f=1;
    rep(i,0,n-1){
        int D1=ham(fx[i]-sx[i],fy[i]-sy[i]),D2=ham(fx[i+1]-sx[i+1],fy[i+1]-sy[i+1]);
        float num=-((fx[i]-sx[i])*(fx[i+1]-fx[i]-sx[i+1]+sx[i])+(fy[i]-sy[i])*(fy[i+1]-fy[i]-sy[i+1]+sy[i]));
        float denom=((fx[i+1]-fx[i]-sx[i+1]+sx[i])*(fx[i+1]-fx[i]-sx[i+1]+sx[i])+(fy[i+1]-fy[i]-sy[i+1]+sy[i])*(fy[i+1]-fy[i]-sy[i+1]+sy[i]));
        float tim=min(1.0,max(0.0,1.0*num/denom));
        float dis=ham((fx[i]-sx[i]+tim*(fx[i+1]-fx[i]-sx[i+1]+sx[i])),(fy[i]-sy[i]+tim*(fy[i+1]-fy[i]-sy[i+1]+sy[i])));
        if(D1>d2) f=1;
        if(dis-d1<=1e-2 and f) ans++,f=0;
        if(D2>d2) f=1;
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