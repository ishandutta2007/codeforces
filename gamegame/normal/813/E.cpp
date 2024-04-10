#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define fi first
#define se second
int n,k;
vector<int>v[262144];
vector<int>f[100001];
int a[100001];
void upd(int id,int l,int r,int p,int s){
	v[id].push_back(s);
	if(l==r) return;
	int mid=(l+r)/2;
	if(p<=mid) upd(id*2,l,mid,p,s);
	else upd(id*2+1,mid+1,r,p,s);
}
int qry(int id,int l,int r,int ql,int qr){
	if(r<ql) return 0;
	if(l>=ql){
		int pl=lower_bound(v[id].begin(),v[id].end(),ql)-v[id].begin();
		int pr=lower_bound(v[id].begin(),v[id].end(),qr+1)-v[id].begin();
		return pr-pl;
	}
	int mid=(l+r)/2;
	return qry(id*2,l,mid,ql,qr)+qry(id*2+1,mid+1,r,ql,qr);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		if(f[a[i]].size()>=k){
			upd(1,1,n,f[a[i]][f[a[i]].size()-k],i);
		}
		f[a[i]].push_back(i);
	}
	int q,ans=0;
	cin >> q;
	for(int i=1; i<=q ;i++){
		int l,r;cin >> l >> r;
		l=(l+ans)%n+1;
		r=(r+ans)%n+1;
		if(l>r) swap(l,r);
		ans=r-l+1-qry(1,1,n,l,r);
		cout << ans << '\n';
	}
}