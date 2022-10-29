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
int n,ans=hell;
string s,w="BGR",res;
void solve(){
    cin>>n;
    cin>>s;
    do{
        int cnt=0;
        rep(i,0,n){
            if(s[i]!=w[i%3]) cnt++;
        }
        if(ans>cnt){
            ans=cnt;
            res=w;
        }
    }while(next_permutation(all(w)));
    cout<<ans<<endl;
    rep(i,0,n) cout<<res[i%3];
    cout<<endl;
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