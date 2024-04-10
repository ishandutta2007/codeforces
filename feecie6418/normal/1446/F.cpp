#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=acos(-1);
ll n,K,x[100005],y[100005],m,is[100005];
double b[200005];
struct Seg{
	double tl,tr;
	int l,r,id;
}a[100005];
struct BIT{
	int c[200005];
	int Q(int x) {
		int ret=0;
		while(x)ret+=c[x],x-=x&-x;
		return ret;
	}
	void U(int x,int y=1) {
		while(x<=m)c[x]+=y,x+=x&-x;
	}
}cl,cr;
ll Find(double R){
	m=0;
	ll ret=0;
	for(int i=1;i<=n;i++){
		a[i].id=i;
		if(x[i]*x[i]+y[i]*y[i]<=R*R){
			is[i]=0;
			continue;
		}
		double c=R/sqrt(x[i]*x[i]+y[i]*y[i]);
		a[i].tl=atan2(y[i],x[i])-acos(c),a[i].tr=atan2(y[i],x[i])+acos(c);
		if(a[i].tl<-pi)a[i].tl+=2*pi;
		if(a[i].tr>pi)a[i].tr-=2*pi;
		if(a[i].tl>a[i].tr)swap(a[i].tl,a[i].tr);
		b[++m]=a[i].tl,b[++m]=a[i].tr,is[i]=1;
	}
	sort(b+1,b+m+1);
	for(int i=1;i<=m;i++)cl.c[i]=cr.c[i]=0;
	for(int i=1;i<=n;i++)a[i].l=lower_bound(b+1,b+m+1,a[i].tl)-b,a[i].r=lower_bound(b+1,b+m+1,a[i].tr)-b;
	sort(a+1,a+n+1,[](Seg x,Seg y){return x.l<y.l;});
	for(int i=1;i<=n;i++){
		if(!is[a[i].id])continue;
		//cout<<a[i].l<<' '<<a[i].r<<'\n';
		ret+=cr.Q(a[i].r)-cr.Q(a[i].l);
		cl.U(a[i].l),cr.U(a[i].r);
	}
	return ret;
}
int main(){
	scanf("%lld%lld",&n,&K),K=n*(n-1)/2-K+1;
	for(int i=1;i<=n;i++)scanf("%lld%lld",&x[i],&y[i]);
	//cout<<Find(0.7)<<endl;
	//return 0;
	double l=0,r=1e5;
	while(r-l>1e-8){
		double mid=(l+r)/2;
		if(Find(mid)>=K)l=mid;
		else r=mid;
	}
	printf("%.10lf\n",(l+r)/2);
	return 0;
}