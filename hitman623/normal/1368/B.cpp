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
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
string s="codeforces";
void solve(){
    int k;
    cin>>k;
    int w=-1,val=-1;
    rep(i,1,41){
        int cur=1;
        rep(j,0,10){
            cur*=i;
        }
        if(cur>=k){
            w=i;
            val=cur;
            break;
        }
    }
    string res;
    rep(i,0,10){
        int f=w;
        if(val/w*(w-1)>=k){
            val=val/w*(w-1);
            f--;
        }
        rep(j,0,f) res+=s[i];
    }
    cout<<res<<endl;
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