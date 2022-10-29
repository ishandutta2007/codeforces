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
void solve(){
    cin>>s;
    int n=sz(s),f=0;
    rep(i,0,n/2) if(s[i]!=s[0]) f=1;
    if(f==0){
        cout<<"Impossible"<<endl;
        return;
    }
    rep(i,1,n+1){
        string a,b;
        rep(j,0,i){
            a+=s[j];
        }
        rep(j,i,n){
            b+=s[j];
        }
        b+=a;
        string c=b;
        reverse(all(c));
        if(c==b and c!=s){
            cout<<1<<endl;
            return;
        }
    }
    cout<<2<<endl;
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