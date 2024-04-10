#include <cassert>
#include <iostream>
#include <cstdio>

#define N 200050

using namespace std;

typedef long long LL;

struct Tree{
	int la,ra,siz;
	LL sum,lsum,rsum;
}tr[4*N];

int a[N],x,n;

Tree merge(Tree p1,Tree p2) {
	Tree tmp;
	
	tmp.la = p1.la; tmp.lsum = p1.lsum;
	if (p1.la == p1.siz && p2.la > 0) tmp.la += p2.la , tmp.lsum += p2.lsum;
	
	tmp.ra = p2.ra; tmp.rsum = p2.rsum;
	if (p2.ra == p2.siz && p1.ra > 0) tmp.ra += p1.ra , tmp.rsum += p1.rsum;
	
	tmp.siz = p1.siz + p2.siz;
	tmp.sum = max(p1.sum,p2.sum);
	
	if (p1.ra > 0) tmp.sum = max(tmp.sum,p1.rsum);
	if (p2.la > 0) tmp.sum = max(tmp.sum,p2.lsum); 
	
	assert(p1.ra != 0); assert(p2.la != 0);
	if (p1.ra > 0 && p2.la > 0)
		tmp.sum = max(p1.rsum + p2.lsum , tmp.sum);
	
	return tmp;
}

void build(int l,int r,int t) {
	if (l == r) {
		tr[t].la = tr[t].ra = tr[t].siz = 1;
		tr[t].sum = tr[t].lsum = tr[t].rsum = 1LL * a[l];
		return ;
	}
	int mid = (l + r) / 2;
	build(l,mid,2*t);
	build(mid+1,r,2*t+1);
	tr[t] = merge(tr[2*t],tr[2*t+1]);
}

void update(int l,int r,int t) {
	if (l == r) {
		tr[t].la = tr[t].ra = -1;
		tr[t].sum = tr[t].lsum = tr[t].rsum = -1LL;
		return ;
	}
	int mid = (l + r) / 2;
	if (x <= mid) 
		update(l,mid,2*t);
	else
		update(mid+1,r,2*t+1);
	tr[t] = merge(tr[2*t],tr[2*t+1]);
}

int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	
	build(1,n,1);
	
	for (int i=1;i<=n;i++) {
		scanf("%d",&x);
		update(1,n,1);
		if (tr[1].sum < 0) 
			printf("0\n");
		else
			printf("%I64d\n",tr[1].sum);
	}
	return 0;
}