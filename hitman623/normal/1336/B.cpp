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
#define hell        3000000000000000007LL
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n[3],a[3][100005],pos[3];
int get(){
    int w=0;
    w+=(a[0][pos[0]]-a[1][pos[1]])*(a[0][pos[0]]-a[1][pos[1]]);
    w+=(a[0][pos[0]]-a[2][pos[2]])*(a[0][pos[0]]-a[2][pos[2]]);
    w+=(a[2][pos[2]]-a[1][pos[1]])*(a[2][pos[2]]-a[1][pos[1]]);
    return w;
}
void solve(){
    int res=hell;
    rep(i,0,3) cin>>n[i];
    rep(i,0,3){
        rep(j,0,n[i]){
            cin>>a[i][j];
        }
        sort(a[i],a[i]+n[i]);
    }
    vi v;
    rep(i,0,3) v.pb(i);
    do{
        rep(i,0,n[v[1]]){
            int mid=a[v[1]][i];
            int l=upper_bound(a[v[0]],a[v[0]]+n[v[0]],mid)-a[v[0]]-1;
            if(l<0) continue;
            int r=lower_bound(a[v[2]],a[v[2]]+n[v[2]],mid)-a[v[2]];
            if(r>=n[v[2]]) continue;
            pos[v[0]]=l;
            pos[v[1]]=i;
            pos[v[2]]=r;
            res=min(res,get());
        }
    }while(next_permutation(all(v)));
    cout<<res<<endl;
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