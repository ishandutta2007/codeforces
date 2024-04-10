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
int n,l[300005],r[300005],lmx,lmn,rmx,rmn,posl,posr,ans;
int sol(){
    int lm=-1,rm=2*hell;
    rep(i,0,n){
        lm=max(lm,l[i]);
        rm=min(rm,r[i]);
    }
    return rm-lm;
}
void solve(){
    lmx=rmx=-1;
    rmn=hell;
    lmn=hell;
    cin>>n;
    rep(i,0,n){
        cin>>l[i]>>r[i];
        lmx=max(lmx,l[i]);
        rmn=min(rmn,r[i]);
    }
    rep(i,0,n){
        if(l[i]==lmx and r[i]<lmn){
            lmn=r[i];
            posl=i;
        }
        if(r[i]==rmn and l[i]>rmx){
            rmx=l[i];
            posr=i;
        }
    }
    int L=l[posl],R=r[posl];
    l[posl]=-1;
    r[posl]=hell;
    ans=max(ans,sol());
    l[posl]=L;
    r[posl]=R;
    L=l[posr];
    R=r[posr];
    l[posr]=-1;
    r[posr]=hell;
    ans=max(ans,sol());
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