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
#define hell        1000000000000007LL
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
int n,k,a[200005],b[200005],ca[200005];
bool check(int mid){
    rep(i,1,n+1) ca[i]=a[i];
    priority_queue<pii,vii,greater<pii>> pq;
    rep(i,1,n+1) pq.push({ca[i]/b[i]+1,i});
    rep(i,1,k+1){
        if(pq.empty()) return 1;
        pii cur=pq.top();
        pq.pop();
        if(cur.x>k+1) return 1;
        if(cur.x<i) return 0; 
        int id=cur.y;
        ca[id]+=mid;
        ca[id]=min(ca[id],hell);
        if(ca[id]/b[id]+1<=k+1) pq.push({ca[id]/b[id]+1,id});
    }
    return 1;
}
void solve(){
    cin>>n>>k;
    rep(i,1,n+1) cin>>a[i];
    rep(i,1,n+1) cin>>b[i];
    int lo=-1,hi=1e13;
    while(hi-lo>1){
        int mid=(lo+hi)/2;
        if(check(mid)) hi=mid;
        else lo=mid;
    }
    if(hi==1e13) cout<<-1<<endl;
    else cout<<hi<<endl;
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