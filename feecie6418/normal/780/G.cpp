#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pr;
const int mod=1e9+7,inf=2e9;
struct Seg{
	int x,l,r,s;
}a[100005];
multiset<pr> b[100005];
int H,n,m,mnh[400005];
void Build(int p,int l,int r){
	mnh[p]=H+1;
	if(l==r)return b[l].insert(pr(H+1,1)),void();
	int mid=(l+r)/2;
	Build(p*2,l,mid),Build(p*2+1,mid+1,r);
}
int Find(int p,int l,int r,int x,int y,int z){
	if(mnh[p]>z)return 0;
	if(l==r){
		int ret=0;
		auto it=b[l].upper_bound(pr(z,inf));
		while(it!=b[l].begin()){
			--it;
			ret=(ret+(it->second))%mod;
			b[l].erase(it);
			it=b[l].upper_bound(pr(z,inf));
		}
		if(b[l].size())mnh[p]=b[l].begin()->first;
		else mnh[p]=inf;
		return ret;
	}
	int mid=(l+r)/2,ret=0;
	if(x<=mid)ret=(ret+Find(p*2,l,mid,x,y,z))%mod;
	if(mid<y)ret=(ret+Find(p*2+1,mid+1,r,x,y,z))%mod;
	mnh[p]=min(mnh[p*2],mnh[p*2+1]);
	return ret;
}
void Ins(int p,int l,int r,int x,int y,int z){
	if(l==r){
		b[l].insert(pr(z,y));
		mnh[p]=b[l].begin()->first;
		return ;
	}
	int mid=(l+r)/2;
	if(x<=mid)Ins(p*2,l,mid,x,y,z);
	else Ins(p*2+1,mid+1,r,x,y,z);
	mnh[p]=min(mnh[p*2],mnh[p*2+1]);
}
int main(){
	scanf("%d%d%d",&H,&n,&m);
	for(int i=1,x,l,r,s;i<=m;i++){
		scanf("%d%d%d%d",&x,&l,&r,&s);
		a[i]={x,l,r,s};
	}
	sort(a+1,a+m+1,[](Seg x,Seg y){return x.x>y.x;});
	Build(1,1,n);
	for(int i=1;i<=m;i++){
		int s=Find(1,1,n,a[i].l,a[i].r,a[i].x+a[i].s);
		if(a[i].l!=1)Ins(1,1,n,a[i].l-1,s,a[i].x);
		else Ins(1,1,n,a[i].r+1,s,a[i].x);
		if(a[i].r!=n)Ins(1,1,n,a[i].r+1,s,a[i].x);
		else Ins(1,1,n,a[i].l-1,s,a[i].x);
	}
	cout<<Find(1,1,n,1,n,H+1);
}