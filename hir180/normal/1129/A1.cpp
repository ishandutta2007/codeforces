#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
int n,m;
vector<int>go[5005];
ll num[20005];
struct RMQ{
	#define s (1<<16)
	ll seg[s];
	void update(int k,ll a){
		k+=s/2-1; seg[k]=a;
		while(k>0){
			k=(k-1)/2;
			seg[k]=max(seg[k*2+1],seg[k*2+2]);
		}
	}
	ll query(int a,int b,int k,int l,int r){
		if(r<a || b<l) return 0;
		if(a<=l && r<=b) return seg[k];
		else{
			ll vl=query(a,b,k*2+1,l,(l+r)/2);
			ll vr=query(a,b,k*2+2,(l+r)/2+1,r);
			return max(vl,vr);
		}
	}
}kaede;
int main(){
	cin>>n>>m;
	rep(i,m){
		int a,b; cin>>a>>b;
		go[a].pb(b);
	}
	for(int i=1;i<=2*n;i++){
		int j = i; if(j > n) j-=n;
		if(go[j].empty()){
			num[i] = -1e18; kaede.update(i,num[i]);
			continue;
		}
		num[i] = 1LL*i;
		num[i] += 1LL * (go[j].size()-1) * n;
		ll mn = 1e18;
		for(int x=0;x<go[j].size();x++){
			if(j < go[j][x]) mn = min(mn,1LL*go[j][x]-j);
			else mn = min(mn,1LL*go[j][x]-j+n);
		}
		num[i] += mn;
		kaede.update(i,num[i]);
	}
	for(int i=1;i<=n;i++){
		cout << kaede.query(i,i+n-1,0,0,(1<<15)-1)-i << endl;
	}
}