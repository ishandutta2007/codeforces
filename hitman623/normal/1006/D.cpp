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
#define hell        998244353
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,ans;
string a,b;
void solve(){
    cin>>n>>a>>b;
    rep(i,0,n/2){
        map<char,int> s;
        s[a[i]]++;
        s[b[i]]++;
        s[a[n-i-1]]++;
        s[b[n-i-1]]++;
        if(sz(s)==4) ans+=2;
        else if(sz(s)==3){
            if(a[i]==a[n-i-1]) ans++;
            ans+=1;
        }
        else if(sz(s)==2){
            int f=0;
            for(auto j:s){
                if(j.y%2) f=1;
            }
            ans+=f;
        }
    }
    if(n%2) ans+=a[n/2]!=b[n/2];
    cout<<ans<<endl;
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