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
string a,b;
int n,ans[200005];
void solve(){
    cin>>n>>a>>b;
    int cur=0;
    for(int i=n-1;i>=0;i--){
        ans[i]=(cur+(a[i]-'a')+(b[i]-'a'))%26;
        cur=(cur+(a[i]-'a')+(b[i]-'a'))/26;
    }
    rep(i,0,n){
        int w=(cur*26+ans[i])/2;;
        cur=(cur*26+ans[i])%2;
        ans[i]=w;
        cout<<(char)(ans[i]+'a');
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