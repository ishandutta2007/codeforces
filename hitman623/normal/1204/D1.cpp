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
int lis[100005];
void solve(){
    cin>>s;
    int cnt1=0;
    for(int i=sz(s)-1;i>=0;i--){
        lis[i]=lis[i+1];
        if(s[i]=='1') lis[i]=max(lis[i],++cnt1);
        else lis[i]++;
    }
    rep(i,0,sz(s)){
        if(s[i]=='1' and lis[i+1]+1<=lis[i]) s[i]='0';
    }
    cout<<s<<endl;
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