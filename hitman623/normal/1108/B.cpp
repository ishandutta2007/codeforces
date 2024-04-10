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
vi v;
int freq[10004];
void solve(){
    cin>>n;
    rep(i,0,n){
        int x;
        cin>>x;
        v.pb(x);
        freq[x]++;
    }
    sort(all(v));
    int y=v.back(),x;
    for(int i=1;i<=y;++i){
        if(y%i==0){
            freq[i]--;
        }
    }
    rep(i,0,10001) if(freq[i]) x=i;
    cout<<x<<" "<<y<<endl;
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