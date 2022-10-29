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
int n,a[2][300005],s[300005],d[2][300005];
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>a[0][i];
        s[i]+=a[0][i];
    }
    rep(i,0,n){
        cin>>a[1][i];
        s[i]+=a[1][i];
    }
    for(int i=n-1;i>=0;i--){
        s[i]+=s[i+1];
        d[0][i]=d[0][i+1]+a[1][i]*(2*(n-i)-1)+s[i+1];
        d[1][i]=d[1][i+1]+a[0][i]*(2*(n-i)-1)+s[i+1];
    }
    int cur=0,ans=0,tim=-1;
    rep(i,0,n+1){
        if(i%2==0){
            tim++;
            ans=max(ans,cur+d[0][i]+s[i]*tim);
            cur+=a[0][i]*tim;
            tim++;
            cur+=a[1][i]*tim;
        }
        else{
            tim++;
            ans=max(ans,cur+d[1][i]+s[i]*tim);
            cur+=a[1][i]*tim;
            tim++;
            cur+=a[0][i]*tim;
        }
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