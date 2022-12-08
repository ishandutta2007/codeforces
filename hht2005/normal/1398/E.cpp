#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> pii;
#define x first
#define y second
#define mp make_pair
const int maxn=2e5+10;
int rnk[maxn],ls[maxn],rs[maxn],siz[maxn],val[maxn],s1[maxn],tp[maxn],tot,rt;
long long sum[maxn];
void updata(int p) {
	sum[p]=sum[ls[p]]+sum[rs[p]]+val[p];
	siz[p]=siz[ls[p]]+siz[rs[p]]+1;
	s1[p]=s1[ls[p]]+s1[rs[p]]+tp[p];
}
int merge(int x,int y) {
	if(!x||!y)return x^y;
	if(rnk[x]<rnk[y]) {
		rs[x]=merge(rs[x],y);
		updata(x);
		return x;
	} else {
		ls[y]=merge(x,ls[y]);
		updata(y);
		return y;
	}
}
pii split(int x,int k) {
	if(!x)return mp(0,0);
	pii t;
	if(val[x]>k) {
		t=split(ls[x],k);
		ls[x]=t.y;
		t.y=x;
	} else {
		t=split(rs[x],k);
		rs[x]=t.x;
		t.x=x;
	}
	updata(x);
	return t;
}
int New(int x,int tpy) {
	rnk[++tot]=rand();
	s1[tot]=tp[tot]=tpy;
	val[tot]=sum[tot]=x;
	ls[tot]=rs[tot]=0;
	siz[tot]=1;
	return tot;
}
void ins(int x,int tpy) {
	pii t=split(rt,x);
	rt=merge(merge(t.x,New(x,tpy)),t.y);
}
void del(int x) {
	pii t1=split(rt,x),t2=split(t1.x,x-1);
	rt=merge(t2.x,t1.y);
}
long long qry1(int p,int x) {
	if(!p)return 0;
	if(siz[rs[p]]>=x)return qry1(rs[p],x);
	else return qry1(ls[p],x-siz[rs[p]]-1)+sum[rs[p]]+val[p];
}
long long qry2(int p,int x) {
	if(!p)return 0;
	if(siz[rs[p]]>=x)return qry2(rs[p],x);
	else return qry2(ls[p],x-siz[rs[p]]-1)+s1[rs[p]]+tp[p];
}
long long qry(int p) {
	if(!p)return 0;
	if(siz[rs[p]]>s1[rs[p]])return qry(rs[p]);
	else if(!tp[p])return val[p];
	else return qry(ls[p]);
}
int main() {
	int n,tp,x,k=0;
	long long sum=0;
	scanf("%d",&n);
	while(n--) {
		scanf("%d%d",&tp,&x);
		if(tp)k+=x>0?1:-1;
		if(x<0)del(-x);
		else if(x>0)ins(x,tp);
		sum+=x;
		if(k&&qry2(rt,k)==k)printf("%lld\n",qry1(rt,k-1)+qry(rt)+sum);
		else printf("%lld\n",qry1(rt,k)+sum);
	}
	return 0;
}