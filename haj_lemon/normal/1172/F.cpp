#include<bits/stdc++.h>
#define ll long long
#define INF 10000000000000000ll
#define N 1000010
using namespace std;
template <typename T> void read(T &x){
	x=0;char ch=getchar();int fh=1;
	while (ch<'0'||ch>'9'){if (ch=='-')fh=-1;ch=getchar();}
	while (ch>='0'&&ch<='9')x=x*10+ch-'0',ch=getchar();
	x*=fh;
}
int m,n,p,a[N],l,r;
struct Onfo{ll l,r,anl;};
struct segment{int l,r;vector<Onfo> x;}t[N*4];
vector<Onfo> operator +(vector<Onfo> x,vector <Onfo> y){
	vector<Onfo> an,an2;an.clear();an2.clear();
	ll no=-INF;
	for (int i=0,j=0;;){
		if (x[i].r<y[j].r-x[i].anl+x[i].l){
			an.push_back((Onfo){no,x[i].r,no-x[i].l+x[i].anl-y[j].l+y[j].anl});
			no=x[i].r+1;i++;
			if (i==x.size())break;
			if (x[i].anl<y[j].l)j--;
		}else{
			if (x[i].r==y[j].r-x[i].anl+x[i].l){
				an.push_back((Onfo){no,x[i].r,no-x[i].l+x[i].anl-y[j].l+y[j].anl});
				no=x[i].r+1;i++;
				if (i==x.size())break;
				if (x[i].anl>y[j].r)j++;
				if (j==y.size())break;
			}else{
				an.push_back((Onfo){no,y[j].r-x[i].anl+x[i].l,no-x[i].l+x[i].anl-y[j].l+y[j].anl});
				no=y[j].r-x[i].anl+x[i].l+1;j++;
				if (j==y.size())break;
			}
		}
	}
	for (unsigned i=0;i<an.size();i++){
		if (i+1<an.size()&&an[i].l-an[i].anl==an[i+1].l-an[i+1].anl){
			an2.push_back((Onfo){an[i].l,an[i+1].r,an[i].anl});i++;
		}else an2.push_back(an[i]);
	}
	return an2;
}
void build(int nu,int l,int r){
	t[nu].l=l;t[nu].r=r;
	if (l==r){
		t[nu].x.push_back((Onfo){-INF,p-a[l]-1,-INF+a[l]});
		t[nu].x.push_back((Onfo){p-a[l],INF,0});
	}else{
		build(nu*2,l,(l+r)/2);build(nu*2+1,(l+r)/2+1,r);
		t[nu].x=t[nu*2].x+t[nu*2+1].x;
	}
}
ll que(int nu,int l,int r,ll x){
	if (t[nu].l==l&&t[nu].r==r){
		int l=0,r=t[nu].x.size()-1,mid;
		while (l<r){
			mid=(l+r+1)/2;
			if (t[nu].x[mid].l>x)r=mid-1;else l=mid;
		}
		return t[nu].x[l].anl+x-t[nu].x[l].l;
	}
	int mid=(t[nu].l+t[nu].r)/2;
	if (l>mid) return que(nu*2+1,l,r,x);
	if (r<=mid) return que(nu*2,l,r,x);
	ll y=que(nu*2,l,mid,x);
	return que(nu*2+1,mid+1,r,y);
}
int main(){
	read(n);read(m);read(p);
	for (int i=1;i<=n;i++)read(a[i]);
	build(1,1,n);
	for (int i=1;i<=m;i++){
		read(l);read(r);
		printf("%lld\n",que(1,l,r,0));
	}
	return 0;
}