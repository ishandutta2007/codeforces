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
int n,m,q;
int p[200005];
int go[200005][20];
int a[200005];
int rev[200005];
vector<int>pos[200005];
struct RMQ{
	#define s (1<<19)
	int seg[s];
	void init(){
		fill(seg,seg+s,INF);
	}
	void update(int k,int a){
		k+=s/2-1; seg[k]=a;
		while(k>0){
			k=(k-1)/2;
			seg[k]=min(seg[k*2+1],seg[k*2+2]);
		}
	}
	int query(int a,int b,int k,int l,int r){
		if(r<a || b<l) return INF;
		if(a<=l && r<=b) return seg[k];
		else{
			int vl=query(a,b,k*2+1,l,(l+r)/2);
			int vr=query(a,b,k*2+2,(l+r)/2+1,r);
			return min(vl,vr);
		}
	}
}rmq;
int main(){
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n;i++){
		scanf("%d",&p[i]);
		rev[p[i]] = i;
	}
	for(int i=1;i<=m;i++){
		scanf("%d",&a[i]);
		pos[a[i]].pb(i);
	}
	for(int i=0;i<200005;i++) for(int j=0;j<20;j++) go[i][j] = -1;
	for(int i=1;i<=m;i++){
		int nxt = rev[a[i]]+1;
		if(nxt == n+1) nxt = 1;
		int a = POSU(pos[p[nxt]],i);
		if(a != pos[p[nxt]].size()){
			go[i][0] = pos[p[nxt]][a];
		}
	}
	for(int j=0;j<19;j++){
		for(int i=1;i<=m;i++){
			if(go[i][j] == -1) go[i][j+1] = -1;
			else go[i][j+1] = go[go[i][j]][j];
		}
	}
	rmq.init();
	for(int i=1;i<=m;i++){
		int a = i;
		int N = n-1;
		for(int j=0;j<19&&a!=-1;j++){
			if(((N>>j)&1)){
				a = go[a][j];
			}
		}
		if(a == -1) rmq.update(i,INF);
		else rmq.update(i,a);
	}
	string ans = "";
	for(int i=0;i<q;i++){
		int a,b; scanf("%d%d",&a,&b);
		int anss = rmq.query(a,b,0,0,s/2-1);
		if(anss <= b){
			ans.pb('1');
		}
		else{
			ans.pb('0');
		}
	}
	cout << ans << endl;
	return 0;
}