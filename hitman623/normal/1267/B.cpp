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
string s;
vii v;
void solve(){
    cin>>s;
    for(auto i:s){
        if(sz(v)==0 or v.back().x!=i-'A') v.pb({i-'A',1});
        else v.back().y++;
    }
    if(sz(v)%2==0){
        cout<<0<<endl;
        return;
    }
    int l=0,r=sz(v)-1;
    while(l<r){
        if(v[l].x==v[r].x and v[l].y+v[r].y>=3);
        else{
            cout<<0<<endl;
            return;
        }
        l++,r--;
    }
    if(v[l].y+1>=3) cout<<v[l].y+1<<endl;
    else cout<<0<<endl;
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