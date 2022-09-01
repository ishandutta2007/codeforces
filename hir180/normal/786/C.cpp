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
#define s (1<<17)
int n,a[100005],nn[100005];
int pre[100005];
vector<int>pos[100005];
// segment tree
int seg[100005 * 50];
int L[100005 * 50];
int R[100005 * 50];
int nxt = 1;
inline void build(int k,int l,int r){
	if(l == r){
		seg[k] = (1<=l && l<=n && pre[l] == 0);
		//if(seg[k]) cout << l << " " << r << " " << seg[k] << endl;
		return;
	}
	L[k] = nxt++;
	R[k] = nxt++;
	build(L[k],l,(l+r)/2);
	build(R[k],(l+r)/2+1,r);
	seg[k] = seg[L[k]] + seg[R[k]];
}
inline int upd(int a,int id,int l,int r){
	int N = nxt++;
	seg[N] = seg[id]+1;
	L[N] = L[id];
	R[N] = R[id];
	if(l == r) return N;
	if(a <= (l+r)/2){
		L[N] = upd(a,L[id],l,(l+r)/2);
	}
	else{
		R[N] = upd(a,R[id],(l+r)/2+1,r);
	}
	return N;
}
inline int sum(int a,int b,int id,int l,int r){
	if(r < a || b < l) return 0;
	if(a <= l && r <= b) return seg[id];
	return sum(a,b,L[id],l,(l+r)/2)+sum(a,b,R[id],(l+r)/2+1,r);
}
inline int find(int id,int l,int r,int num){
	if(seg[id] < num) return n+1;
	if(l == r) return l;
	if(seg[L[id]] >= num){
		return find(L[id],l,(l+r)/2,num);
	}
	else{
		return find(R[id],1+(l+r)/2,r,num-seg[L[id]]);
	}
}
int root[100005];
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		pre[i] = nn[a[i]];
		nn[a[i]] = i;
	}
	for(int i=1;i<=n;i++)
	{
		pos[pre[i]].pb(i);
	}
	build(0,0,s-1);
	root[0] = 0;
	for(int i=1;i<n;i++){
		assert(pos[i].size() <= 1);
		if(pos[i].size() == 0) root[i] = root[i-1];
		else{
			root[i] = upd(pos[i][0],root[i-1],0,s-1);
		}
	}
	for(int k=1;k<=n;k++){
		int cur = 1;
		int ans = 0;
		while(cur <= n){
			int num = sum(0,cur-1,root[cur-1],0,s-1); //cout << cur << " " << k << " d " << num << endl;
			num += k+1;
			int pos = find(root[cur-1],0,s-1,num);
			cur = pos; //cout << k << " " << cur << endl;
			ans++;
		}
		printf("%d\n",ans);
	}
	return 0;
}