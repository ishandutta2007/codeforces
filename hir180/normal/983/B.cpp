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
int ans[5005][5005],n,a[5005];
struct RMQ{
	#define s (1<<14)
	int seg[s];
	void update(int k,int a){
		k+=s/2-1;
		if(seg[k] >= a) return;
		seg[k]=max(seg[k],a);
		while(k>0){
			k=(k-1)/2;
			seg[k]=max(seg[k*2+1],seg[k*2+2]);
		}
	}
	int query(int a,int b,int k,int l,int r){
		if(r<a || b<l) return 0;
		if(a<=l && r<=b) return seg[k];
		else{
			int vl=query(a,b,k*2+1,l,(l+r)/2);
			int vr=query(a,b,k*2+2,(l+r)/2+1,r);
			return max(vl,vr);
		}
	}
	int query(int a,int b) { return query(a,b,0,0,s/2-1); }
}kaede;
vector<P>query[5005];
int anss[100005],q;
int main(){
	scanf("%d",&n);
	repn(i,n) scanf("%d",&a[i]);
	repn(i,n) ans[i][i] = a[i];
	for(int len=2;len<=n;len++){
		for(int i=1;i+len-1<=n;i++){
			ans[i][i+len-1] = (ans[i+1][i+len-1] ^ ans[i][i+len-2]);
		}
	}
	scanf("%d",&q);
	repn(i,q){
		int L,R; scanf("%d%d",&L,&R);
		query[L].pb(mp(R,i));
	}
	for(int i=n;i>=1;i--){
		for(int j=i;j<=n;j++) kaede.update(j,ans[i][j]);
		for(int j=0;j<query[i].size();j++){
			int x = query[i][j].fi;
			anss[query[i][j].sc] = kaede.query(i,x);
		}
	}
	repn(i,q){
		printf("%d\n",anss[i]);
	}
}