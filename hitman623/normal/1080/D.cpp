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
int f[100];
void solve(){
    int n,k;
    cin>>n>>k;
    int can=0;
    rep(i,1,n+1){
        k-=(1LL<<i)-1;
        if(k<0){
            cout<<"NO"<<endl;
            return;
        }
        int temp=(1LL<<(i+1))-3;
        if(n>32 or k<1.0l*temp*f[n-i]){
            cout<<"YES "<<n-i<<endl;
            return;    
        }
        can+=temp*f[n-i];
        if(k<=can){
            cout<<"YES "<<n-i<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

signed main(){
    f[0]=0;
    rep(i,1,100){
        f[i]=4*f[i-1]+1;
        if(f[i]>1e18+hell) f[i]=1e18+hell;
    }
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