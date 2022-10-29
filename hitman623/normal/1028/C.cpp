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
vi canx,cany;
vii x,y;
struct d{
    int a,b,c,d;
};
vector<d> rect;
void solve(){
    cin>>n;
    rep(i,0,n){
        int ax,ay,bx,by;
        cin>>ax>>ay>>bx>>by;
        rect.pb({ax,ay,bx,by});
        x.pb({ax,-1});
        x.pb({bx,1});
        y.pb({ay,-1});
        y.pb({by,1});
    }
    sort(all(y));
    sort(all(x));
    int cur=0;
    for(auto i:x){
        cur-=i.y;
        if(cur>=n-1){
            canx.pb(i.x);
        }
    }
    cur=0;
    for(auto i:y){
        cur-=i.y;
        if(cur>=n-1){
            cany.pb(i.x);
        }
    }
    for(auto i:canx){
        for(auto j:cany){
            int a=i,b=j,cnt=0;
            for(auto k:rect){
                if(k.a<=a and a<=k.c and k.b<=b and b<=k.d){
                    cnt++;
                }
            }
            if(cnt>=n-1){
                cout<<i<<" "<<j<<endl;
                return;
            }
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