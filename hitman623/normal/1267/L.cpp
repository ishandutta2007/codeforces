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
int n,l,k,f[26],cnt;
string s,ans;
vector<string> v;
void solve(){
    cin>>n>>l>>k>>s;
    sort(all(s));
    cnt=sz(s)-1;
    for(auto i:s) f[i-'a']++;
    rep(i,0,l){
        rep(j,0,26){
            if(f[j]>=k){
                ans+=j+'a';
                f[j]-=k;
                break;
            }
            else{
                rep(q,0,f[j]){
                    string w=ans;
                    w+=j+'a';
                    while(sz(w)<l) w+=s[cnt--];
                    v.pb(w);
                }
                k-=f[j];
                f[j]=0;
            }
        }
    }
    rep(_,0,k) v.pb(ans);
    while(sz(v)<n){
        string w;
        rep(_,0,l){
            w+=s[cnt--];
        }
        v.pb(w);
    }
    sort(all(v));
    for(auto i:v) cout<<i<<endl;
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