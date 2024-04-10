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
string l,r;
int n;
vi fl[26],fr[26],ql,qr,extrar,extral;
vii pairs;
void solve(){
    cin>>n>>l>>r;
    rep(i,0,n){
        if(l[i]!='?') fl[l[i]-'a'].pb(i);
        else ql.pb(i);
        if(r[i]!='?') fr[r[i]-'a'].pb(i);
        else qr.pb(i);
    }
    rep(i,0,26){
        while(sz(fl[i]) and sz(fr[i])){
            pairs.pb({fl[i].back(),fr[i].back()});
            fl[i].pop_back();
            fr[i].pop_back();
        }
        while(sz(fl[i])){
            extral.pb(fl[i].back());
            fl[i].pop_back();
        }
        while(sz(fr[i])){
            extrar.pb(fr[i].back());
            fr[i].pop_back();
        }
    }
    while(sz(ql) and sz(extrar)){
        pairs.pb({ql.back(),extrar.back()});
        extrar.pop_back();
        ql.pop_back();
    }
    while(sz(qr) and sz(extral)){
        pairs.pb({extral.back(),qr.back()});
        extral.pop_back();
        qr.pop_back();
    }
    while(sz(ql) and sz(qr)){
        pairs.pb({ql.back(),qr.back()});
        ql.pop_back();
        qr.pop_back();        
    }
    cout<<sz(pairs)<<endl;
    for(auto i:pairs) cout<<i.x+1<<" "<<i.y+1<<endl;
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