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
int n,m;
void solve(){
    cin>>n>>m;
    if(n>m) swap(n,m);
    if(n==1){
        if(m%6==0) cout<<m<<endl;
        else if(m%6==4) cout<<m-2<<endl;
        else if(m%6==5) cout<<m-1<<endl;
        else cout<<(m/6)*6<<endl;
    }
    else if(n==2){
        if(m==2) cout<<0<<endl;
        else if(m%2==0) cout<<n*m<<endl;
        else if(m==3 or m==7) cout<<n*m-2<<endl;
        else cout<<n*m<<endl;
    }
    else if(n%2==0){
        cout<<n*m<<endl;
    }
    else if(m%2) cout<<n*m-1<<endl;
    else cout<<m*n<<endl;
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