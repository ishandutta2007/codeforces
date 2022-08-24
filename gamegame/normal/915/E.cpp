#include<iostream>
#include<algorithm>
using namespace std;
int n,q;
const int ts=(1<<21);
int l[ts],r[ts],v[ts],sum[ts];
bool lazy[ts];
int a[600001];
int ql[300001],qr[300001],qk[300001];
void build(int id){
	if(id==1) l[id]=1,r[id]=2*q;
	else{
		int mid=(l[id/2]+r[id/2])/2;
		if(id%2==0) l[id]=l[id/2],r[id]=mid;
		else l[id]=mid,r[id]=r[id/2];
	}
	if(l[id]+1!=r[id]){
		build(id*2);
		build(id*2+1);
	}
}
void update(int id,int ll,int rr,int vv){
	if(a[l[id]]==ll && a[r[id]]==rr){
		lazy[id]=true;
		v[id]=vv;
		sum[id]=v[id]*(a[r[id]]-a[l[id]]);
		return;
	}
	if(lazy[id]){
		lazy[id]=false;
		lazy[id*2]=lazy[id*2+1]=true;
		v[id*2]=v[id*2+1]=v[id];
		sum[id*2]=v[id]*(a[r[id*2]]-a[l[id*2]]);
		sum[id*2+1]=v[id]*(a[r[id*2+1]]-a[l[id*2+1]]);
	}
	int mid=(l[id]+r[id])/2;
	if(rr<=a[mid]) update(id*2,ll,rr,vv);
	else if(ll>=a[mid]) update(id*2+1,ll,rr,vv);
	else{
		update(id*2,ll,a[mid],vv);
		update(id*2+1,a[mid],rr,vv);
	}
	sum[id]=sum[id*2]+sum[id*2+1];
}
int main(){
	ios::sync_with_stdio(false);
	cin >> n >> q;
	for(int i=1; i<=q ;i++){
		cin >> ql[i] >> qr[i] >> qk[i];
		a[i*2-1]=ql[i];
		a[i*2]=qr[i]+1;
	}
	sort(a+1,a+2*q+1);
	build(1);
	for(int i=1; i<=q ;i++){
		update(1,ql[i],qr[i]+1,2-qk[i]);
		cout << n-sum[1] << '\n';
	}
}