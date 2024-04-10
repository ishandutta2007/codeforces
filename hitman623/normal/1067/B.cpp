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
int n,k,deg[100005],freq[100005];
set<int> a[100005];
vi leaves;
void solve(){
    cin>>n>>k;
    rep(i,0,n-1){
        int u,v;
        cin>>u>>v;
        a[u].insert(v);
        a[v].insert(u);
        deg[u]++;
        deg[v]++;
    }
    rep(i,1,n+1){
        if(deg[i]==1){
            leaves.pb(i);
        }
    }
    while(sz(leaves)>1){
        set<int> new_leaves;
        for(auto i:leaves){
            if(sz(a[i])==0){
                cout<<"No"<<endl;
                return;
            }
            int d=*a[i].begin();
            a[d].erase(i);
            freq[d]++;
            new_leaves.insert(d);
        }
        k--;
        leaves.clear();
        for(auto i:new_leaves){
            leaves.pb(i);
            if(freq[i]<3 or sz(a[i])>1){
                cout<<"No"<<endl;
                return;
            }
        }
    }
    if(k){
        cout<<"No"<<endl;
        return;
    }
    cout<<"Yes"<<endl;
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