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
int n;
int a[5222][5222];
bool check(int x){
    for(int i=1;i+x-1<=n;i+=x){
        for(int j=1;j+x-1<=n;j+=x){
            int d=a[i+x-1][j+x-1]-a[i+x-1][j-1]-a[i-1][j+x-1]+a[i-1][j-1];
            if(d==0 or d==x*x);
            else return 0;
        }
    }
    return 1;
}
void solve(){
    cin>>n;
    rep(i,1,n+1){
        string s;
        cin>>s;
        int cur=1;
        for(auto j:s){
            int d;
            if(isdigit(j)) d=j;
            else d=j-'A'+10;
            rep(k,0,4){
                a[i][cur++]=(d>>(3-k))&1;
            }
        }
    }
    rep(i,1,n+1){
        rep(j,1,n+1){
            a[i][j]+=a[i][j-1]+a[i-1][j]-a[i-1][j-1];
        }
    }
    int ans=1;
    rep(i,1,n+1){
        if(n%i==0 and check(i)) ans=i;
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