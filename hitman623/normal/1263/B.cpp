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
int n;
string s[22];
void solve(){
    int ans=0;
    map<string,int> mp;
    cin>>n;
    rep(i,0,n){
        cin>>s[i];
        mp[s[i]]=i;
    }
    rep(i,0,n){
        if(mp[s[i]]!=i){
            rep(k,0,4){
                rep(l,0,10){
                    string h=s[i];
                    h[k]=l+'0';
                    if(mp.count(h)==0){
                        s[i]=h;
                        mp[h]=1;
                        goto d;
                    }
                }
            }
            d:
            ans++;
        }
    }
    cout<<ans<<endl;
    rep(i,0,n) cout<<s[i]<<endl;
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