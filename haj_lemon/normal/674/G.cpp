#include<bits/stdc++.h>
#define pb emplace_back
#define N 150010
#define mr make_pair
#define vii vector<pair<int,int> >
using namespace std;
struct Info{int l,r,ta;vii s;}t[N*4];
int n,Q,p,a[N],opt,l,r,x;
vii add(vii x,vii y){
	vii z=x;
	for (int i=0;i<y.size();i++){
		bool q=1;
		for (int j=0;j<x.size();j++)if (y[i].first==x[j].first)x[j].second+=y[i].second,q=0;
		if (q)x.pb(y[i]);
		if (x.size()>p){
			int mi=n;
			for (auto j:x)mi=min(mi,j.second);
			z.clear();
			for (int j=0;j<x.size();j++){x[j].second-=mi;if (x[j].second!=0)z.pb(x[j]);}
			x=z;
		}else z=x;
	}
	return z;
}
void build(int nu,int l,int r){
	t[nu].l=l;t[nu].r=r;t[nu].ta=0;
	if (l!=r){
		build(nu*2,l,(l+r)/2);build(nu*2+1,(l+r)/2+1,r);
		t[nu].s=add(t[nu*2].s,t[nu*2+1].s);
	}else t[nu].s.pb(mr(a[l],1));
}
void ya(int nu){
	if (t[nu].ta){
		if (t[nu].l!=t[nu].r){t[nu*2].ta=t[nu].ta;t[nu*2+1].ta=t[nu].ta;}
		t[nu].s.clear();
		t[nu].s.pb(mr(t[nu].ta,t[nu].r-t[nu].l+1));
		t[nu].ta=0;
	}
}
void chan(int nu,int l,int r,int x){
	ya(nu);
	if (t[nu].l==l&&t[nu].r==r){t[nu].ta=x;return ;}
	int mid=(t[nu].l+t[nu].r)/2;
	if (l<=mid) chan(nu*2,l,min(mid,r),x);
	if (r>mid) chan(nu*2+1,max(mid+1,l),r,x);
	ya(nu*2);ya(nu*2+1);
	t[nu].s=add(t[nu*2].s,t[nu*2+1].s);
}
vii que(int nu,int l,int r){
	ya(nu);
	if (t[nu].l==l&&t[nu].r==r)return t[nu].s;
	int mid=(t[nu].l+t[nu].r)/2;
	if (l>mid) return que(nu*2+1,l,r);
	if (r<=mid) return que(nu*2,l,r);
	return add(que(nu*2,l,mid),que(nu*2+1,mid+1,r));
}
int main(){
	cin>>n>>Q>>p;
	p=100/p;
	for (int i=1;i<=n;i++)cin>>a[i];
	build(1,1,n);
	vii an=t[1].s;
	for (int i=1;i<=Q;i++){
		cin>>opt>>l>>r;
		if (opt==1){cin>>x;chan(1,l,r,x);}
		else{
			vii an=que(1,l,r);
			cout<<an.size();for (int i=0;i<an.size();i++)cout<<' '<<an[i].first;cout<<'\n';
		}
	}
	return 0;
}