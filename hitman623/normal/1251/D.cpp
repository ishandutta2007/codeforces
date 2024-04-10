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
int n,s,l[300005],r[300005];
vii v;
bool check(int mid){
	int sum=0,lef=0,rig=0;
	rep(i,0,n){
		if(l[i]>mid) sum+=l[i],rig++;
		if(r[i]<mid) sum+=l[i],lef++;
	}
	if(lef>n/2) return 0;
	if(rig>n/2) return 1;
	int reml=n/2-lef;
	if(reml)
	rep(i,0,n){
		if(l[i]>mid or r[i]<mid) continue;
		sum+=l[i];
		reml--;
		if(reml==0) break;
	}
	if((n+1)/2-rig>s/mid) return 0;
	sum+=((n+1)/2-rig)*mid;
	return sum<=s;
}
void solve(){
    cin>>n>>s;
    v.clear();
    v.resize(n);
    rep(i,0,n) cin>>v[i].x>>v[i].y;
    sort(all(v));
    rep(i,0,sz(v)) l[i]=v[i].x,r[i]=v[i].y;
    int lo=0,hi=2e14+1;
    while(hi-lo>1){
    	int mid=(lo+hi)/2;
    	if(check(mid)) lo=mid;
    	else hi=mid;
    }
    cout<<lo<<endl;
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