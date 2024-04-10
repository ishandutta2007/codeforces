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
#define hell        998244353
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,dp[1000006][2][2];
int go(int m,int f,int g){
    if(m==0) return 1;
    int &ans=dp[m][f][g];
    if(ans!=-1) return ans;
    int a=(m-1)/2;
    int b=m-1-a;
    ans=0;
    if(a==b){
        if((a+g+1)%2==f) ans=(ans+go(a,!f,g)*go(b,f,g^((a+1)%2)))%hell;
    }
    else{
        if((a+g+1)%2==f) ans=(ans+go(a,!f,g)*go(b,f,g^((a+1)%2)))%hell;
        if((b+g+1)%2==f) ans=(ans+go(b,!f,g)*go(a,f,g^((b+1)%2)))%hell;
    }
    return ans;
}
void solve(){
    cin>>n;
    memset(dp,-1,sizeof dp);
    cout<<(go(n,0,0)+go(n,1,0))%hell<<endl;
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