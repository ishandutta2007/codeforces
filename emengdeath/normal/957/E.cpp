#include<bits/stdc++.h>
using namespace std;
typedef double ld;
const int N=200000+123;
const int MAXN=1e9;
struct node{
	ld t1,t2;
	bool sig;
}a[N],b[N];
int tota,totb,totc,n,w;
long long ans;
ld c[N];
int sum[N];
int f[N*4];
bool cmp2(const node&a,const node&b){
	return a.t1<b.t1||(a.t1==b.t1&&a.t2<b.t2);
}
void ins(int l,int r,int s,ld ll,int sig){
	f[s]+=sig;
	if (l==r)return;
	if (c[(l+r)/2]>=ll)ins(l,(l+r)/2,s+s,ll,sig);
	else
		ins((l+r)/2+1,r,s+s+1,ll,sig);
}
void get(int l,int r,int s,ld ll){
	if (c[l]>ll||!f[s])return;
	if (c[r]<=ll){
		ans+=f[s];
		return;
	}
	if (l==r)return;
	get(l,(l+r)/2,s+s,ll),get((l+r)/2+1,r,s+s+1,ll);
}
void build(int l,int r,int s){
	if (l==r){
		f[s]=sum[l];
		return;
	}
	build(l,(l+r)/2,s+s),build((l+r)/2+1,r,s+s+1);
	f[s]=f[s+s]+f[s+s+1];
}
long long calc(long long x){
	return x*(x-1)/2;
}
void work(node*a,int tota){
	if (!tota)return;
	for (int i=1;i<=tota;i++)
		c[i]=a[i].t2;
	sort(c+1,c+tota+1);
	totc=1;
	sum[totc]=1;
	for (int i=2;i<=tota;i++)
		if (c[totc]!=c[i])c[++totc]=c[i],sum[totc]=1;else sum[totc]++;
	build(1,totc,1);
	sort(a+1,a+tota+1,cmp2);
	int l=1;
	for (int i=1;i<=tota;i++)
		if (a[i].t1!=a[l].t1||a[i].t2!=a[l].t2){
			int sum=0;
			for (int j=l;j<i;j++)if (a[j].sig==0)sum++;
			ans-=calc(sum);
			l=i;
		}
	int num=0;
	for (int j=l;j<=tota;j++)if (a[j].sig==0)num++;
	ans-=calc(num);
	l=1;
	for (int i=1;i<=tota;i++){
		while (l<=tota&&a[l].t1<a[i].t1)ins(1,totc,1,a[l].t2,-1),l++;
		if (a[i].sig==0)get(1,totc,1,a[i].t2);
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin>>n>>w;
	for (int i=1;i<=n;i++){
		ld x,v;
		cin>>x>>v;
		if (x<0){
			x=-x;
			++tota;
			a[tota].t2=x/(v-w);
			a[tota].t1=x/(v+w);
			a[tota].sig=0;
		}else{
			v=-v;
			++tota;
			a[tota].t2=x/(v+w);
			a[tota].t1=x/(v-w);
			++totb;
		 	b[totb].t2=x/(v-w);
			b[totb].t1=x/(v+w);
			b[totb].sig=0;
			a[tota].sig=1;
		}
	}
	work(a,tota);
	ans-=tota-totb;
	work(b,totb);
	ans-=totb;
	cout<<ans<<endl;
	return 0;
}