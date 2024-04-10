#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define add(x,y) x=(x+(y))%mo
#define dec(x,y) x=(x+mo-(y))%mo
#define sqr(x) ((x)*(x))
#define gc getchar()
#define pb push_back
#define N 600000
#define ll long long
#define mo 1000000007
#define inf 1000000000
#define Inf 1000000000000000000ll
#define eps 1e-8
using namespace std;
int n,m,x,y,b[N];
struct pr{ll x,p,a;}a[N];
pr operator +(pr x,pr y){
	return {x.x+y.x,(x.p+y.p)%mo,(x.a+y.a)%mo};
}
int fm(int x,ll y,int l,int r){
	if(l==r)return l;int rr=(l+r)/2;
	if(y<=a[x*2].x)return fm(x*2,y,l,rr);
	else return fm(x*2+1,y-a[x*2].x,rr+1,r);
}
void f(int x,int y,ll z,int l,int r){
	if((l==y)&&(r==y)){
		a[x]={z,z*y%mo,z*b[y]%mo};return;
	}int rr=(l+r)/2;
	if(y<=rr)f(x*2,y,z,l,rr);else f(x*2+1,y,z,rr+1,r);
	a[x]=a[x*2]+a[x*2+1];
}
pr q(int x,int l,int r,int L,int R){
	if((l==L)&&(r==R))return a[x];int rr=(L+R)/2;
	if(r<=rr)return q(x*2,l,r,L,rr);
	else if(l>rr)return q(x*2+1,l,r,rr+1,R);
	else return q(x*2,l,rr,L,rr)+q(x*2+1,rr+1,r,rr+1,R);
}
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n)scanf("%d",&b[i]);
	rep(i,1,n){
		scanf("%d",&x);f(1,i,x,1,n);
	}
	rep(i,1,m){
		scanf("%d%d",&x,&y);
		if(x<0)f(1,-x,y,1,n);else{
			ll tq=(q(1,x,y,1,n).x+1)/2;
			if(x>1)tq+=q(1,1,x-1,1,n).x;
			int rr=fm(1,tq,1,n);
			ll sp=(b[rr]-rr+mo)%mo;
			pr l=q(1,x,rr,1,n);
			pr r;if(rr<y)r=q(1,rr+1,y,1,n);else r={0,0,0};
			printf("%I64d\n",(l.x%mo*sp+l.p-l.a+r.a-r.x%mo*sp%mo-r.p+mo*3ll)%mo);
		}
	}
}