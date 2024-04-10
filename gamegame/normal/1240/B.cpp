#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int bit[300001];
int mi[300001],ma[300001],sz[300001];
void upd(int id,int v){
	for(int i=id; i<=n ;i+=i&-i) bit[i]=max(bit[i],v);
}
int qry(int id){
	int v=0;
	for(int i=id; i>=1 ;i-=i&-i) v=max(v,bit[i]);
	return v;
}
void solve(){
	cin >> n;
	for(int i=1; i<=n ;i++){
		bit[i]=0;mi[i]=ma[i]=sz[i]=0;
	}
	int cc=0;
	for(int i=1; i<=n ;i++){
		int x;cin >> x;
		if(!mi[x]) mi[x]=i;
		ma[x]=i;
		sz[x]++;
		if(sz[x]==1) cc++;
	}
	int ans=0;
	int bb=0;
	int prv=0;
	for(int i=1; i<=n ;i++){
		if(mi[i]==0) continue;
		if(mi[i]<ma[prv]) bb=0;
		bb++;
		prv=i;
		ans=max(ans,bb);
	}
	cout << cc-ans << '\n';
}
int main(){
	ios::sync_with_stdio(false);
	int q;cin >> q;while(q--) solve();
}