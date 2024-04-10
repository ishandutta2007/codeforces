#include <bits/stdc++.h>

#define int         long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          unordered_map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,a[500005],cnt,cur,res;
void solve(){
    cin>>n;
    rep(i,1,n+1){
        cin>>a[i];
        a[i]+=a[i-1];
        if(a[i]==0) cnt++;
    }
    int s=a[n],d=s/3;
    if(s%3){
        cout<<0<<endl;
        return ;
    }
    if(s==0){
        cout<<(cnt-1)*(cnt-2)/2<<endl;
        return;
    }
    rep(i,0,n){
        if(a[i]==2*d){
            res+=cur;
        }
        if(a[i]==d) cur++;
    }
    cout<<res<<endl;
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