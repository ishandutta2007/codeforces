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
int n,a[1502];
map<int,vii> sums;
void solve(){
    cin>>n;
    rep(i,1,n+1) cin>>a[i];
    rep(i,1,n+1){
        int s=0;
        rep(j,i,n+1){
            s+=a[j];
            sums[s].pb({i,j});
        }
    }
    int mx=0,mxsum=hell;
    vector<pair<int,vii>> sumsss(all(sums));
    for(auto i:sumsss){
        sort(all(i.y),[](pii lhs,pii rhs){
            return lhs.y<rhs.y;
        });
        int cnt=0;
        int last=0;
        for(auto j:i.y){
            if(j.x>last){
                cnt++;
                last=j.y;
            }
        }
        if(cnt>mx){
            mx=cnt;
            mxsum=i.x;
        }
    }
    cout<<mx<<endl;
    int last=0;
    sort(all(sums[mxsum]),[](pii lhs,pii rhs){
        return lhs.y<rhs.y;
    });
    for(auto j:sums[mxsum]){
        if(j.x>last){
            cout<<j.x<<" "<<j.y<<endl;
            last=j.y;
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