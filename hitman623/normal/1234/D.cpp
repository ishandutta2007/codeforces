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
int q;
string s;
set<int> st[26];
void solve(){
    cin>>s>>q;
    rep(i,0,sz(s)) st[s[i]-'a'].insert(i);
    while(q--){
        int type;
        cin>>type;
        if(type==1){
            int pos;
            char c;
            cin>>pos>>c;
            pos--;
            st[s[pos]-'a'].erase(pos);
            s[pos]=c;
            st[s[pos]-'a'].insert(pos);
        }
        else{
            int l,r;
            cin>>l>>r;
            l--,r--;
            int ans=0;
            rep(i,0,26){
                auto d=st[i].lower_bound(l);
                if(d!=st[i].end() and *d<=r) ans++;
            }
            cout<<ans<<endl;
        }
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