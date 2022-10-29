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

void solve(){
    ll n,m,k;
    cin>>n>>m>>k;
    ll reqd=max(n,m);
    if(k<reqd){
        cout<<-1<<endl;
        return;
    }
    ll d=max(m,n)-min(m,n);
    k-=min(m,n);
    if(d%2==0){
        cout<<min(m,n)+k-2*(k%2)<<endl;
    }
    else{
        cout<<min(m,n)+k-1<<endl;
    }
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