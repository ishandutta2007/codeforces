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
string s,w,ww;
int a;
void solve(){
    cin>>s;
    for(auto i:s) if(i=='a') a++;
    if((sz(s)+a)%2){
        cout<<":("<<endl;
        return;
    }
    int n=(sz(s)+a)/2;
    rep(i,0,n){
        w+=s[i];
        if(s[i]!='a') ww+=s[i];
    }
    ww=w+ww;
    if(ww==s) cout<<w<<endl;
    else cout<<":("<<endl;
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