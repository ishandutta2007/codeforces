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
int n,m,p[11][100005],ans;
map<int,int> a[100005];
void solve(){
    cin>>n>>m;
    rep(i,0,m){
        rep(j,1,n+1){
            cin>>p[i][j];
        }
        rep(j,1,n){
            a[p[i][j]][p[i][j+1]]++;
        }
    }
    int cur=1;
    while(cur<=n){
        int l=cur;
        while(cur<n and a[p[0][cur]][p[0][cur+1]]==m){
            cur++;
        }
        ans+=(cur-l+1)*(cur-l+2)/2;
        cur++;
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