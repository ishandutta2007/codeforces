#include <bits/stdc++.h>

#define int          long long
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
int n,k,s,m;
vi ans;
void solve(){
    cin>>n>>k>>s;
    m=n-1;
    if(s>m*k || s<k){
        cout<<"NO"<<endl;
        return;
    }
    int cur1=1,cur2=n;
    while(m){
        while(k and s-m>=k-1){
            s-=m;
            k--;
            swap(cur1,cur2);
            ans.pb(cur1);
        }
        int d=max(1LL,m-(s-k+1));
        if(cur1>cur2) cur2+=d;
        else cur2-=d;
        m-=d;
    }
    cout<<"YES"<<endl;
    for(auto i:ans){
        cout<<i<<" ";
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