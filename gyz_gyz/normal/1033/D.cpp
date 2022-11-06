#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define dep(i,x,y) for(int i=(x);i>=(y);i--)
#define N 100000
#define ll long long
#define pb push_back
#define add(x,y) x=(x+(y))%mo;
#define sqr(x) ((x)*(x))
#define mo 998244353
#define eps 1e-18
using namespace std;
int n,tot;ll x,ans,a[N],c[N];
struct pr{ll x;bool y;}b[N];
bool cmp(pr x,pr y){return x.x<y.x;}
ll gcd(ll x,ll y){
	if(!x)return y;return gcd(y%x,x);
}
ll fd(ll x){
	ll l=2,r=1500000000;
	for(ll m=(l+r+1)/2;l<r;m=(l+r+1)/2)if(m*m<=x)l=m;else r=m-1;
	return l;
}
ll Fd(ll x){
	ll l=2,r=1260000;
	for(ll m=(l+r+1)/2;l<r;m=(l+r+1)/2)if(m*m*m<=x)l=m;else r=m-1;
	return l;
}
ll FD(ll x){
	ll l=2,r=38000;
	for(ll m=(l+r+1)/2;l<r;m=(l+r+1)/2)if(m*m*m*m<=x)l=m;else r=m-1;
	return l;
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)scanf("%I64d",&a[i]);
	rep(i,1,n)rep(j,1,n){
		x=gcd(a[i],a[j]);
		if((x>1)&&(x<a[i]))c[i]=x;
	}
	rep(i,1,n){
		x=FD(a[i]);
		if(x*x*x*x==a[i]){
			b[++tot].x=x;b[++tot].x=x;b[++tot].x=x;b[++tot].x=x;
		}else{
			x=Fd(a[i]);
			if(x*x*x==a[i]){
				b[++tot].x=x;b[++tot].x=x;b[++tot].x=x;
			}else{
				x=fd(a[i]);
				if(x*x==a[i]){
					b[++tot].x=x;b[++tot].x=x;
				}else if(c[i])b[++tot].x=c[i],b[++tot].x=a[i]/c[i];
				else b[++tot].x=a[i],b[tot].y=1;
			}
		}
	}
	sort(b+1,b+tot+1,cmp);ans=1;x=2;
	rep(i,2,tot)if(b[i].x!=b[i-1].x){
		ans=ans*x%mo;if(b[i-1].y)ans=ans*x%mo;x=2;
	}else x++;
	ans=ans*x%mo;if(b[tot].y)ans=ans*x%mo;
	printf("%I64d",ans);
}