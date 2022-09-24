#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
typedef pair<int,int> pr;
int n,m,jc[1000005]={1},ny[1000005]={1},ans=0,X[1000005],Y[1000005];
int C(int x,int y){
	if(x<y||y<0||x<0)return 0;
	return 1ll*jc[x]*ny[y]%mod*ny[x-y]%mod;
}
int Power(int x,int y){
	int r=1;
	while(y){
		if(y&1)r=1ll*r*x%mod;
		x=1ll*x*x%mod,y>>=1;
	}
	return r;
}
int c[1000005][2],s[1000005],rnk[1000005],root=0;
unsigned int randseed=19260817;
int Rand() {
	return randseed=(randseed*7+13)^(randseed/13-7);
}
void Pushup(int x) {
	s[x]=s[c[x][0]]+1+s[c[x][1]];
}
pr Split(int x,int k){
	if(!x)return {0,0};
	if(s[c[x][0]]>=k){
		pr o=Split(c[x][0],k);
		return c[x][0]=o.second,Pushup(x),(pr){o.first,x};
	}
	else {
		pr o=Split(c[x][1],k-s[c[x][0]]-1);
		return c[x][1]=o.first,Pushup(x),(pr){x,o.second};
	}
}
int Merge(int x,int y) {
	if(!x||!y)return x+y;
	if(rnk[x]<rnk[y])return c[x][1]=Merge(c[x][1],y),Pushup(x),x;
	else return c[y][0]=Merge(x,c[y][0]),Pushup(y),y;
}
int Build(int l,int r){
	if(l>r)return 0;
	if(l==r)return s[l]=1,rnk[l]=Rand(),l;
	int mid=(l+r)/2,p1=Build(l,mid),p2=Build(mid+1,r);
	return Merge(p1,p2);
}
int Find(int x){
	pr o=Split(root,x-1),oo=Split(o.second,1);
	int ret=oo.first;
	return root=Merge(o.first,Merge(oo.first,oo.second)),ret;
}
void Shift(int x,int y){
	pr o=Split(root,x-1),oo=Split(o.second,y-x),ooo=Split(oo.second,1);
	root=Merge(Merge(o.first,ooo.first),Merge(oo.first,ooo.second));
}
void Return(int x,int y){
	pr o=Split(root,x-1),oo=Split(o.second,1),ooo=Split(oo.second,y-x);
	root=Merge(Merge(o.first,ooo.first),Merge(oo.first,ooo.second));
}
void Solve(){
	scanf("%d%d",&n,&m);
	int K=n-1;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&X[i],&Y[i]);
	}
	map<int,int> o;
	for(int i=1,curmx=0;i<=m;i++){
		int x=X[i],y=Find(Y[i]);
		if(!o[y])K--,o[y]=1;
		Shift(Y[i],X[i]);
	}
	cout<<C(n+K,n)<<'\n';
	for(int i=m;i>=1;i--){
		Return(Y[i],X[i]);
	}
}
int main(){
	for(int i=1;i<=400000;i++)jc[i]=1ll*jc[i-1]*i%mod;
	ny[400000]=Power(jc[400000],mod-2);
	for(int i=399999;i;i--)ny[i]=1ll*ny[i+1]*(i+1)%mod;
	root=Build(1,200000);
	int t;
	scanf("%d",&t);
	while(t--)Solve();
	return 0;////
}