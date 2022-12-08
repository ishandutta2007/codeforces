#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,M=1e9;
int val[N],ls[N*30],rs[N*30],siz[N*30],rt,tot,Siz;
long long sum[N*30],Sum;
void add(int &p,int l,int r,int x,int v) {
	if(!p)p=++tot;
	sum[p]+=v*x;
	siz[p]+=v;
	if(l==r)return;
	int mid=(l+r)>>1;
	if(x<=mid)add(ls[p],l,mid,x,v);
	else add(rs[p],mid+1,r,x,v);
}
void qry(int p,int l,int r,int x) {
	if(!p)return;
	if(r<=x) {
		Siz+=siz[p];
		Sum+=sum[p];
		return;
	}
	int mid=(l+r)>>1;
	qry(ls[p],l,mid,x);
	if(x>mid)qry(rs[p],mid+1,r,x);
}
int main() {
	int n,m,op;
	long long p;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		scanf("%d",val+i);
		add(rt,0,M,val[i],1);
	}
	while(m--) {
		scanf("%d%lld",&op,&p);
		if(op==1) {
			add(rt,0,M,val[p],-1);
			scanf("%d",val+p);
			add(rt,0,M,val[p],1);
		} else {
			double L=0,R=1e9;
			for(int i=0;i<=80;i++) {
				double mid=(L+R)/2;
				Sum=Siz=0;
				qry(rt,0,M,int(mid));
				if(Siz*mid-Sum>=p)R=mid;
				else L=mid;
			}
			if(1ll*M*siz[rt]-sum[rt]<p)L=(p-(1ll*M*siz[rt]-sum[rt]))/siz[rt]+M;
			printf("%.6f\n",L);
		}
	}
	return 0;
}