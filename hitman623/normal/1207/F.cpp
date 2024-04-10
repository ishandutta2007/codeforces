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
#define P           710
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int q,b[500005];
ll a[1001][1001];
void solve(){
    cin>>q;
    while(q--){
        int type,x,y;
        cin>>type>>x>>y;
        if(type==1){
            b[x]+=y;
            rep(i,1,P) a[i][x%i]+=y;
        }
        else{
            ll ans=0;
            if(x>=P){
                while(y<=500000){
                    ans+=b[y];
                    y+=x;
                }
            }
            else ans=a[x][y];
            cout<<ans<<endl;
        }
    }
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