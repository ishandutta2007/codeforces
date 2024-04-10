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
int n,ans=1,res,mx;
void solve(){
    vi v;
    cin>>n;
    if(n==1){
        cout<<1<<" "<<0<<endl;
        return;
    }
    for(int i=2;i<=n;++i){
        if(n%i==0){
            int cnt=0;
            while(n%i==0) n/=i,cnt++;
            ans*=i;
            mx=max(mx,cnt);
            v.pb(cnt);
        }
    }
    sort(all(v));
    if(v[0]!=mx){
        if(mx&(mx-1)) res++;
        while(mx>1){
            mx/=2;
            res++;
        }
        res++;            
    }
    else{
        if(mx&(mx-1)){
            res++;
            while(mx>1){
                mx/=2;
                res++;
            }
            res++;                        
        }
        else{
            while(mx>1){
                mx/=2;
                res++;
            }            
        }
    }
    cout<<ans<<" "<<res<<endl;
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