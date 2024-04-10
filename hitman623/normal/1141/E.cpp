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
#define hell        1000000000000000007LL
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int h,n,d[200005],cur=0,mn=hell;
void solve(){
    cin>>h>>n;
    rep(i,0,n) cin>>d[i];
    rep(i,0,n){
        cur+=d[i];
        mn=min(mn,cur);
    }
    if(cur>=0){
        if(h+mn<=0){
            rep(i,0,n){
                h+=d[i];
                if(h<=0){
                    cout<<i+1<<endl;
                    return;
                }
            }
        }
        else cout<<-1<<endl;
    }
    else{
        // h+x*cur+mn<=0
        int ans=(h+mn)/(-cur);
        if(ans) ans--;
        ans=max(ans,0LL);
        h+=cur*ans;
        ans*=n;
        int pos=0;
        while(1){
            ans++;
            h+=d[pos];
            if(h<=0){
                cout<<ans<<endl;
                return;
            }
            pos++;
            pos%=n;
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