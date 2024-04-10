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
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,q,a[200005],f[50];
void solve(){
    cin>>n>>q;
    rep(i,0,n){
        int x;
        cin>>x;
        int c=0;
        while(x!=1){
            x/=2;
            c++;
        }
        f[c]++;
    }
    while(q--){
        int x;
        cin>>x;
        int cur=0,ans=0;
        for(int i=40;i>=0;i--){
            if((x>>i)&1) cur++;
            if(cur>f[i]){
                ans+=f[i];
                cur-=f[i];
            }
            else{
                ans+=cur;
                cur=0;
            }
            cur*=2;
        }
        if(!cur) cout<<ans<<endl;
        else cout<<-1<<endl;
    }
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}