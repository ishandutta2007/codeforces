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
map<int,set<pii>> pts;
mii mp,on;
int n=0;
void solve(){
    int q;
    cin>>q;
    while(q--){
        int t,x,y;
        cin>>t>>x>>y;
        if(t==1){
            int d=x*x+y*y;
            for(auto i:pts[d]){
                int midx=i.x+x,midy=i.y+y,g=__gcd(midx,midy);
                midx/=g;
                midy/=g;
                mp[{midx,midy}]++;
            }
            pts[d].insert({x,y});
            int g=__gcd(x,y);
            x/=g,y/=g;
            on[{x,y}]++;
            n++;
        }
        else if(t==2){
            int d=x*x+y*y;
            pts[d].erase({x,y});
            for(auto i:pts[d]){
                int midx=i.x+x,midy=i.y+y,g=__gcd(abs(midx),abs(midy));
                midx/=g;
                midy/=g;
                mp[{midx,midy}]--;
                if(mp[{midx,midy}]==0) mp.erase({midx,midy});
            }
            int g=__gcd(x,y);
            x/=g,y/=g;
            on[{x,y}]--;
            if(on[{x,y}]==0) on.erase({x,y});
            n--;
        }
        else{
            int g=__gcd(x,y);
            x/=g,y/=g;
            int ans=n;
            if(mp.count({x,y})) ans-=2*mp[{x,y}];
            if(on.count({x,y})) ans-=on[{x,y}];
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