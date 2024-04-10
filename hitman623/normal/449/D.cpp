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
int n,f[1<<20],pow2[1<<20]={1};
void solve(){
    cin>>n;
    rep(i,1,n+1){
        int x;
        cin>>x;
        f[x]++;
        pow2[i]=2*pow2[i-1]%hell;
    }
    rep(i,0,20){
        rep(mask,0,1<<20){
            if((mask&(1<<i))==0){
                f[mask]+=f[mask^(1<<i)];
            }
        }
    }
    rep(i,0,1<<20) f[i]=(pow2[f[i]]-1+hell)%hell;
    rep(i,0,20){
        rep(mask,0,1<<20){
            if((mask&(1<<i))==0){
                f[mask]=(f[mask]-f[mask^(1<<i)]+hell)%hell;
            }
        }
    }    
    cout<<f[0]<<endl;
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