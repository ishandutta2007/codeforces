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
int ans,cnt;
char cur;
void solve(){
    cin>>s;
    int n=sz(s);
    rep(i,0,n){
        if(s[i]!=cur){
            cnt++;
            cur=s[i];
        }
        else{
            ans=max(ans,cnt);
            cnt=1;
            cur=s[i];
        }
    }
    ans=max(ans,cnt);
    if(s[0]==s.back()){
        cout<<ans<<endl;
        return;
    }
    int l=sz(s)-1;
    while(l>0 and s[l]!=s[l-1]) l--;
    int r=0;
    while(r<n-1 and s[r]!=s[r+1]) r++;
    if(l<r){
        cout<<n<<endl;
    }
    else{
        ans=max(ans,n-l+r+1);
        cout<<ans<<endl;
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