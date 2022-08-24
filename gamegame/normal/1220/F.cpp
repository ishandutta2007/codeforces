#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n;
int a[400001];
int l[800001],r[800001];
int mx[1600001],lz[1600001];
void push(int id){
	mx[id*2]+=lz[id];
	mx[id*2+1]+=lz[id];
	lz[id*2]+=lz[id];
	lz[id*2+1]+=lz[id];
	lz[id]=0;
}
void upd(int id,int l,int r,int ql,int qr,int v){
	if(l>qr || r<ql) return;
	if(ql<=l && r<=qr){
		lz[id]+=v;mx[id]+=v;
		return;
	}
	push(id);
	int mid=(l+r)/2;
	upd(id*2,l,mid,ql,qr,v);
	upd(id*2+1,mid+1,r,ql,qr,v);
	mx[id]=max(mx[id*2],mx[id*2+1]);
}
int qry(int id,int l,int r,int ql,int qr){
	if(l>qr || r<ql) return 0;
	if(ql<=l && r<=qr) return mx[id];
	push(id);
	int mid=(l+r)/2;
	int v1=qry(id*2,l,mid,ql,qr);
	int v2=qry(id*2+1,mid+1,r,ql,qr);
	return max(v1,v2);
}
int ans,mi;
int main(){
	ios::sync_with_stdio(false);
	cin >> n;
	for(int i=1; i<=n ;i++){
		cin >> a[i];
		a[i+n]=a[i];
		r[i]=r[i+n]=2*n+1;
	}
	stack<int>s;
	for(int i=1; i<=2*n ;i++){
		while(!s.empty() && a[s.top()]>a[i]){
			r[s.top()]=i;
			s.pop();
		}
		if(!s.empty()) l[i]=s.top();
		s.push(i);
	}
	for(int i=1; i<=n ;i++){
		if(a[i]!=1) upd(1,1,2*n,l[i]+1,r[i]-1,1);
	}
	ans=qry(1,1,2*n,1,n);
	mi=0;
	for(int i=1; i<=n-1 ;i++){
		if(a[i]==1) continue;
		upd(1,1,2*n,l[i]+1,r[i]-1,-1);
		upd(1,1,2*n,l[i+n]+1,r[i+n]-1,1);
		int cur=qry(1,1,2*n,i+1,n+i);
		if(cur<ans){
			ans=cur;mi=i;
		}
	}
	cout << ans+1 << ' ' << mi << endl;
}