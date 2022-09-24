#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=998244353;
int n,q,a[3][500005];
ll f[3][500005],s[3][500005],cursum=0,t[2000005];
ll t2[2000005],A[500005],mxa[2000005],mxt[2000005],F[2000005];
vector<int> qq[500005];
multiset<ll> tt[500005];
void Upd(int p,int l,int r,int x){
	if(x<l)return ;
	if(l==r){
		if(!tt[l].size()||l==1){
			t[p]=-1e18;
		}
		else {
			t[p]=f[1][l-1]+*--tt[l].end()-s[1][l-1];
			//cout<<"P:"<<p<<' '<<t[p]<<'\n';
		}
		return ;
	}
	int mid=(l+r)/2;
	if(x<=mid)Upd(p*2,l,mid,x);
	if(mid<x)Upd(p*2+1,mid+1,r,x);
	t[p]=max(t[p*2],t[p*2+1]);
	//cout<<"P:"<<p<<' '<<t[p]<<'\n';
}
ll Query(int p,int l,int r,int x,int y){
	if(x<=l&&r<=y)return t[p];
	int mid=(l+r)/2;
	if(x>mid)return Query(p*2+1,mid+1,r,x,y);
	if(y<=mid)return Query(p*2,l,mid,x,y);
	return max(Query(p*2,l,mid,x,y),Query(p*2+1,mid+1,r,x,y));
}
int L[500005],R[500005],X[500005];
void Build(int p,int l,int r){
	if(l==r){
		t[p]=t2[p]=-1e18;
		mxa[p]=-1e18;
		mxt[p]=-1e18;
		return ;
	}
	int mid=(l+r)/2;
	Build(p*2,l,mid),Build(p*2+1,mid+1,r);
	t[p]=max(t[p*2],t[p*2+1]);
	t2[p]=max(t2[p*2],t2[p*2+1]);
	mxa[p]=max(mxa[p*2],mxa[p*2+1]);
	mxt[p]=max(mxt[p*2],mxt[p*2+1]);
}
ll Get(int p,int l,int r,ll lmx){
	if(l==r)return max(mxt[p],lmx)+mxa[p];
	if(lmx>=mxt[p])return mxa[p]+lmx;
	int mid=(l+r)/2;
	if(lmx>=mxt[p*2]){
		return max(mxa[p*2]+lmx,Get(p*2+1,mid+1,r,lmx));
	}
	return max(F[p],Get(p*2,l,mid,lmx));
}
void Upd2(int p,int l,int r,int x){
	if(x<l)return ;
	if(l==r){
		if(!tt[l].size()){
			t2[p]=mxt[p]=-1e18;
		}
		else {
			mxt[p]=*--tt[l].end();
			t2[p]=A[x]+mxt[p];
		}
		mxa[p]=A[x];
		//cout<<"P:"<<p<<' '<<t2[p]<<'\n';
		return ;
	}
	int mid=(l+r)/2;
	if(x<=mid)Upd2(p*2,l,mid,x);
	if(mid<x)Upd2(p*2+1,mid+1,r,x);
	mxa[p]=max(mxa[p*2],mxa[p*2+1]);
	mxt[p]=max(mxt[p*2],mxt[p*2+1]);
	t2[p]=max(t2[p*2],F[p]=Get(p*2+1,mid+1,r,mxt[p*2]));
	//cout<<"P:"<<p<<' '<<t2[p]<<' '<<mxt[p*2]<<'\n';
}
int main(){
	scanf("%d%d",&n,&q);
	for(int i=0;i<3;i++){
		for(int j=1;j<=n;j++)scanf("%d",&a[i][j]),s[i][j]=s[i][j-1]+a[i][j];
	}
	for(int i=1,l,r,x;i<=q;i++){
		scanf("%d%d%d",&l,&r,&x);
		L[i]=l,R[i]=r,X[i]=x;
		qq[l].push_back(i),qq[r+1].push_back(-i);
	}
	Build(1,1,n);// 
	ll ans=-1e18;
	for(int i=1;i<=n;i++){
		A[i]=s[0][i]-s[1][i-1];
		Upd2(1,1,n,i);
		for(int j:qq[i]){
			if(j>0){
				tt[L[j]].insert(-X[j]);
				Upd(1,1,n,L[j]);
				Upd2(1,1,n,L[j]);
			}
			if(j<0){
				tt[L[-j]].erase(tt[L[-j]].find(-X[-j]));
				Upd(1,1,n,L[-j]);
				Upd2(1,1,n,L[-j]);
			}
		}
		f[1][i]=-1e18;
		f[1][i]=max(f[1][i],Query(1,1,n,1,i)+s[1][i]);
		//cout<<"F:"<<i<<' '<<f[1][i]<<'\n';
		// 
		f[1][i]=max(f[1][i],t2[1]+s[1][i]);
		ans=max(ans,f[1][i]+s[2][n]-s[2][i-1]);
		//cout<<"Ff:"<<i<<' '<<f[1][i]<<'\n';
	}
	cout<<ans;
}
/*
9 10
9 0 1 -1 8 7 8 1 -1 
8 7 5 7 1 3 6 8 2 
1 0 1 7 3 5 -1 5 0 
4 6 10
4 7 1
6 7 11
8 9 1
3 5 18
4 7 18
2 7 14
8 8 11
5 6 20
1 6 11
*/