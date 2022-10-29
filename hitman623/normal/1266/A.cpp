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
    int sum=0,z=0,e=0;
    cin>>s;
    if(s=="0"){
        cout<<"red"<<endl;
        return;
    }
    for(auto i:s){
        if(i=='0' and z==0) z=1;
        else if((i-'0')%2==0) e=1;
        sum+=i-'0';
    }
    if(sum%3==0 and z and e) cout<<"red"<<endl;
    else cout<<"cyan"<<endl;
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