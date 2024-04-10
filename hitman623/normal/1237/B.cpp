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
int n,a[100005],b[100005],c[100005],d[100005],cnt;
void solve(){
    cin>>n;
    rep(i,1,n+1){
        int x;
        cin>>x;
        a[x]=i;
        c[i]=x;
    }
    rep(i,1,n+1){
        int x;
        cin>>x;
        b[x]=i;
    }
    rep(i,1,n+1) d[i]=max(d[i-1],b[c[i]]);
    rep(i,1,n+1){
        if(d[a[i]]>b[i]) cnt++;
    }
    cout<<cnt<<endl;
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