#include<bits/stdc++.h>
#define lb long double
#define eps 1e-8
using namespace std;
int m,n,nf;
struct Po{lb x,y;}a[600010],da[600010];
struct Onfo{lb x;int fh;}f[6000010];
struct Info{Po x;int y;}b[600010];
Po operator +(Po x,Po y){return (Po){x.x+y.x,x.y+y.y};}
Po operator -(Po x,Po y){return (Po){x.x-y.x,x.y-y.y};}
Po operator *(Po x,lb y){return (Po){x.x*y,x.y*y};}
Po operator /(Po x,lb y){return (Po){x.x/y,x.y/y};}
lb operator *(Po x,Po y){return x.x*y.y-x.y*y.x;}
lb operator ^(Po x,Po y){return x.x*y.x+x.y*y.y;}
lb dis2(Po x){return x.x*x.x+x.y*x.y;}
lb dis(Po x){return sqrtl(dis2(x));}
int pa(int x){if (x>n) return x-n;return x;}
lb sum;
bool comp(const Onfo &a,const Onfo &b){if (abs(a.x-b.x)<eps) return a.fh<b.fh;return a.x<b.x;}
Info walk(Info x,lb y){
	while (dis(x.x-a[pa(x.y+1)])<y+eps){
		x.y=pa(x.y+1);y-=dis(x.x-a[x.y]);x.x=a[x.y];
	}
	x.x=(da[x.y]*y)+x.x;
	return x;
}
lb que(Po x,Po y,Po z){return dis(z-x)/dis(y-x);}
bool in(Po x,Po y,Po z){
	if (x.x>y.x)swap(x,y);
	if (z.x<x.x-eps||z.x>y.x+eps) return 0;
	if (x.y>y.y) swap(x,y);
	if (z.y<x.y-eps||z.y>y.y+eps) return 0;
	return 1;
}
void get(lb bt,lb r,Po be,Po di,lb ti){
	Po en=be+(di*ti);
	if (dis(be)<r+eps&&dis(en)<r+eps){f[++nf].x=bt;f[nf].fh=1;f[++nf].x=bt+ti;f[nf].fh=-1;return ;}
	if (fabs(be.x-en.x)<eps&&fabs(be.y-en.y)<eps)return ;
	Po ch=be+(en-be)*((((Po){0,0}-be)^(en-be))/dis2(en-be));
	if (dis(ch)>r+eps) return ;
	lb s=sqrtl(r*r-dis2(ch));
	Po an1=ch+((en-be)*(s/dis(en-be))),an2=ch-((en-be)*(s/dis(en-be)));
	if (dis(be)>r-eps&&dis(en)<r-eps){
		if (in(be,en,an1)){f[++nf].x=bt+que(be,en,an1)*ti;f[nf].fh=1;f[++nf].x=bt+ti;f[nf].fh=-1;}
		else {f[++nf].x=bt+que(be,en,an2)*ti;f[nf].fh=1;f[++nf].x=bt+ti;f[nf].fh=-1;}
		return ;
	}
	if (dis(be)<r-eps&&dis(en)>r-eps){
		if (in(be,en,an1)){f[++nf].x=bt;f[nf].fh=1;f[++nf].x=bt+que(be,en,an1)*ti;f[nf].fh=-1;}
		else {f[++nf].x=bt;f[nf].fh=1;f[++nf].x=bt+que(be,en,an2)*ti;f[nf].fh=-1;}
		return ;
	}
	if (dis(be)>r-eps&&dis(en)>r-eps){
		if (in(be,en,an1)){
			f[++nf].x=bt+que(be,en,an1)*ti;f[nf].fh=1;f[++nf].x=bt+que(be,en,an2)*ti;f[nf].fh=-1;
			if (f[nf-1].x>f[nf].x) swap(f[nf-1].x,f[nf].x);
		}
		return ;
	}
}
void get(Info x,Info y,lb z){
	lb nt=0;
	while (nt<sum-eps){
		lb xt=dis(a[pa(x.y+1)]-x.x),yt=dis(a[pa(y.y+1)]-y.x);
		if (xt>yt+eps){swap(x,y);swap(xt,yt);}
		get(nt,z,y.x-x.x,da[y.y]-da[x.y],min(xt,sum-nt));
		nt=nt+xt;
		if (fabs(xt-yt)>eps)y.x=y.x+(da[y.y]*xt);
		else {y.y=pa(y.y+1);y.x=a[y.y];}
		x.y=pa(x.y+1);x.x=a[x.y];
	}
}
bool pa(lb x){
	nf=0;
	for (int i=1;i<=m;i++)get(b[i],b[(i%m)+1],x);
	sort(f+1,f+nf+1,comp);
	for (int i=1,su=0;i<=nf;i++){
		su+=f[i].fh;
		if (su==m)return 1;
	}
	return 0;
}
int main(){
//	freopen("n.in","r",stdin);
//	freopen("n.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){scanf("%Lf %Lf",&a[i].x,&a[i].y);}
	for (int i=1;i<=n;i++)da[i]=(a[pa(i+1)]-a[i])/dis(a[pa(i+1)]-a[i]);
	for (int i=1;i<=n;i++) sum+=dis(a[i]-a[pa(i+1)]);
	sum/=m;
	if (n<m) printf("%.10Lf\n",sum);
	else{
		b[1].x=a[1];b[1].y=1;
		for (int i=2;i<=m;i++)b[i]=walk(b[i-1],sum);
		lb l=0,r=10000,mid;
		while (l+eps<r){
			mid=(l+r)/2;
			if (pa(mid))r=mid;else l=mid;
		}
		printf("%.10Lf\n",l);
	}
	return 0;
}