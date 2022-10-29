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
#define N           1000006
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n;
vi ent[N],ext[N],v,ans;
bool check(){
    int f=1;
    sort(all(v));
    v.resize(unique(all(v))-v.begin());
    for(auto i:v){
        if(sz(ent[i])!=1 or sz(ext[i])!=1){
            f=0;
            break;
        }
        if(ent[i][0]>ext[i][0]){
            f=0;
            break;
        }
    }
    ans.pb(2*sz(v));
    for(auto i:v) ent[i].clear(),ext[i].clear();
    v.clear();
    return f;
}
void solve(){
    cin>>n;
    set<int> st;
    rep(i,0,n){
        int x;
        cin>>x;
        if(x>0){
            ent[x].pb(i);
            st.insert(x);
        }
        else{
            ext[-x].pb(i);
            if(st.count(-x)) st.erase(-x);
        }
        v.pb(abs(x));
        if(sz(st)==0){
            if(check());
            else{
                cout<<-1<<endl;
                return;
            }
        }
    }
    if(sz(ans)==0 or sz(st)){
        cout<<-1<<endl;
        return;
    }
    cout<<sz(ans)<<endl;
    for(auto i:ans) cout<<i<<" ";
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