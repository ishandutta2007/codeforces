#include <bits/stdc++.h>

#define int         long long
#define pb          emplace_back
#define pii         pair<int,int>
#define tiii        tuple<int,int,int>
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
const int N=1000005;
tiii seg[N<<2];
string a;
tiii combine(tiii a,tiii b){
    int d=min(get<2>(a),get<0>(b));
    return tiii(get<0>(a)+get<0>(b)-d,get<1>(a)+get<1>(b)+2*d,get<2>(a)+get<2>(b)-d);
}
void build(int node,int start,int end){
    if(start==end){
        seg[node]=tiii(a[start]==')',0,a[start]=='(');
        return;
    }
    int mid=(start+end)>>1;
    build(node<<1,start,mid);
    build(node<<1|1,mid+1,end);
    seg[node]=combine(seg[node<<1],seg[node<<1|1]);
}
tiii query(int node,int start,int end,int l,int r){
    if(l<=start && r>=end) return seg[node];
    if(r<start || l>end) return tiii(0,0,0);
    int mid=(start+end)>>1;
    return combine(query(node<<1,start,mid,l,r),query(node<<1|1,mid+1,end,l,r));
}
void solve(){
    cin>>a;
    n=sz(a);
    build(1,0,n-1);
    int q;
    cin>>q;
    while(q--){
        int l,r;
        cin>>l>>r;
        cout<<get<1>(query(1,0,n-1,l-1,r-1))<<endl;
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