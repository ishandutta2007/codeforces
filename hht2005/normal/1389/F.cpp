#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
vector<int>pos[maxn<<1];
int t[maxn],l[maxn],r[maxn],c[maxn<<1],tag[2][maxn<<3],Max[2][maxn<<3];
void add(int p,int l,int r,int x,int y,int v,int f) {
	if(x>y)return;
	if(x<=l&&r<=y) {
		tag[f][p]+=v;
		Max[f][p]+=v;
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)add(p<<1,l,mid,x,y,v,f);
	if(y>mid)add(p<<1|1,mid+1,r,x,y,v,f);
	Max[f][p]=max(Max[f][p<<1],Max[f][p<<1|1])+tag[f][p];
}
int qry(int p,int l,int r,int x,int y,int f) {
	if(x>y)return 0;
	if(x<=l&&r<=y)return Max[f][p];
	int mid=(l+r)>>1,maxx=0;
	if(x<=mid)maxx=max(maxx,qry(p<<1,l,mid,x,y,f));
	else maxx=max(maxx,qry(p<<1|1,mid+1,r,x,y,f));
	return maxx+tag[f][p];
}
int main() {
	int n,m=0;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		scanf("%d%d%d",l+i,r+i,t+i);
		c[++m]=l[i],c[++m]=r[i];
	}
	sort(c+1,c+m+1);
	m=unique(c+1,c+m+1)-c-1;
	for(int i=1;i<=n;i++) {
		l[i]=lower_bound(c+1,c+m+1,l[i])-c;
		r[i]=lower_bound(c+1,c+m+1,r[i])-c;
		pos[r[i]].push_back(i);
	}
	for(int i=1;i<=m;i++) {
		for(int k:pos[i])
			add(1,1,m+1,1,l[k],1,t[k]-1);
		int t=max(Max[0][1],Max[1][1]);
		add(1,1,m+1,i+1,i+1,t,0);
		add(1,1,m+1,i+1,i+1,t,1);
	}
	printf("%d\n",max(Max[1][1],Max[0][1]));
	return 0;
}