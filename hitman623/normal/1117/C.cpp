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
#define y1 asd
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int x1,y1,x2,y2,n,dx[100005],dy[100005];
string s;
bool check(int mid){
    int days=mid;
    int xx=x1+(mid/n)*dx[n-1]+(mid%n?dx[mid%n-1]:0);
    int yy=y1+(mid/n)*dy[n-1]+(mid%n?dy[mid%n-1]:0);
    return abs(x2-xx)+abs(y2-yy)<=days;
}
void solve(){
    cin>>x1>>y1>>x2>>y2;
    cin>>n>>s;
    rep(i,0,n){
        dx[i]=(i?dx[i-1]:0)+(s[i]=='R')-(s[i]=='L');
        dy[i]=(i?dy[i-1]:0)+(s[i]=='U')-(s[i]=='D');
    }
    int lo=0,hi=2e18;
    while(hi-lo>1){
        int mid=(lo+hi)/2;
        if(check(mid)) hi=mid;
        else lo=mid;
    }
    if(hi<2e18) cout<<hi<<endl;
    else cout<<-1<<endl;
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