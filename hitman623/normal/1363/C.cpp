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
int n,x,d[1001];
void solve(){
    cin>>n>>x;
    rep(i,1,n+1) d[i]=0;
    rep(i,0,n-1){
        int u,v;
        cin>>u>>v;
        d[u]++;
        d[v]++;
    }
    if(d[x]<=1) cout<<"Ayush"<<endl;
    else if(n%2==0) cout<<"Ayush"<<endl;
    else cout<<"Ashish"<<endl;
}

signed main(){
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