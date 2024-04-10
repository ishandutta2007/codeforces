#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
#define fi first
#define se second
#define pb push_back
int n,q;
pair<int,int>a[100001];
int pos[100001];
vector<pair<int,int> >qr[100001];
int max1[262144];
int max2[262144];
int ans[300001];
void upd1(int id,int l,int r,int x,int v){
	if(l==r){
		max1[id]=max(max1[id],v);
		return;
	}
	int mid=(l+r)/2;
	if(x<=mid) upd1(id*2,l,mid,x,v);
	else upd1(id*2+1,mid+1,r,x,v);
	max1[id]=max(max1[id*2],max1[id*2+1]);
}
void upd2(int id,int l,int r,int x,int v){
	if(l==r){
		max2[id]=max(max2[id],v);
		return;
	}
	int mid=(l+r)/2;
	if(x<=mid) upd2(id*2,l,mid,x,v);
	else upd2(id*2+1,mid+1,r,x,v);
	max2[id]=max(max2[id*2],max2[id*2+1]);
}
int qr1(int id,int l,int r,int ll,int rr){
	if(r<ll || l>rr) return -1e9;
	if(ll<=l && r<=rr) return max1[id];
	int mid=(l+r)/2;
	return max(qr1(id*2,l,mid,ll,rr),qr1(id*2+1,mid+1,r,ll,rr));
}
int qr2(int id,int l,int r,int ll,int rr){
	if(r<ll || l>rr) return -1e9;
	if(ll<=l && r<=rr) return max2[id];
	int mid=(l+r)/2;
	return max(qr2(id*2,l,mid,ll,rr),qr2(id*2+1,mid+1,r,ll,rr));
}
void wash(int id,int l,int r){
	max2[id]=-1e9;
	if(l==r) return;
	int mid=(l+r)/2;
	wash(id*2,l,mid);
	wash(id*2+1,mid+1,r);
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i].fi;
		a[i].se=i;
	}
	sort(a+1,a+n+1);
	for(int i=1; i<=n ;i++) pos[a[i].se]=i;
	wash(1,1,n);
	cin >> q;
	for(int i=1; i<=q ;i++){
		int l,r;
		cin >> l >> r;
		qr[r].pb({l,i});
	}
	for(int i=1; i<=n ;i++){
		int len=1e9,lb;
		while(len>=0){
			int val=a[pos[i]].fi-len;
			lb=lower_bound(a+1,a+n+1,make_pair(val,0))-a;
			int maxi=qr1(1,1,n,lb,pos[i]);
			if(maxi==0) break;
			upd2(1,1,n,maxi,a[pos[maxi]].fi-a[pos[i]].fi);
			len=(a[pos[i]].fi-a[pos[maxi]].fi+1)/2-1;
		}
		len=1e9;
		while(len>=0){
			int val=a[pos[i]].fi+len;
			lb=lower_bound(a+1,a+n+1,make_pair(val+1,0))-a-1;
			int maxi=qr1(1,1,n,pos[i],lb);
			if(maxi==0) break;
			upd2(1,1,n,maxi,a[pos[i]].fi-a[pos[maxi]].fi);
			len=(a[pos[maxi]].fi-a[pos[i]].fi+1)/2-1;
		}
		upd1(1,1,n,pos[i],i);
		for(auto cur:qr[i]) ans[cur.se]=-qr2(1,1,n,cur.fi,i);
	}
	for(int i=1; i<=q ;i++){
		cout << ans[i] << '\n';
	}
}