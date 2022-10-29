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

void solve(){
    string s;
    int n;
    cin>>n>>s;
    string a,b;
    rep(i,0,sz(s)){
        if(s[i]=='0') a+='0',b+='0';
        else if(s[i]=='1'){
            a+='1';
            b+='0';
            rep(j,i+1,sz(s)) a+='0',b+=s[j];
            cout<<a<<"\n"<<b<<endl;
            return;
        }
        else a+='1',b+='1';
    }
    cout<<a<<endl;
    cout<<b<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}