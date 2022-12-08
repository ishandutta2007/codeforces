#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int a[N],b[N],R[N],P[N],c[N],las[N];
int fa[55][N],siz[55][N],d[55][N],sk[N],C[N],top,n,m,q;
vector<int>S[N<<2];
void add(int p,int l,int r,int x,int y,int v) {
	if(x>y)return;
	if(x<=l&&r<=y) {
		S[p].push_back(v);
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)add(p<<1,l,mid,x,y,v);
	if(y>mid)add(p<<1|1,mid+1,r,x,y,v);
}
void GO(int tmp) {
	while(top>tmp) {
		int x=sk[top],c=C[top],f=fa[c][x];
		siz[c][f]-=siz[c][x];
		fa[c][x]=x;
		top--;
	}
}
int get(int x,int c) {
	return fa[c][x]==x?x:get(fa[c][x],c);
}
int getD(int x,int c) {
	return fa[c][x]==x?0:getD(fa[c][x],c)^d[c][x];
}
int merge(int a,int b,int c) {
	int p=get(a,c),q=get(b,c);
	int dp=getD(a,c),dq=getD(b,c);
	if(p==q)return dp^dq;
	if(siz[c][p]<siz[c][q])swap(p,q);
	fa[c][q]=p;
	d[c][q]=dp^dq^1;
	siz[c][p]+=siz[c][q];
	sk[++top]=q;
	C[top]=c;
	return 1;
}
void solve(int p,int l,int r) {
	int tmp=top;
	for(int i:S[p])
		merge(a[P[i]],b[P[i]],c[i]);
	if(l==r) {
		if(!merge(a[P[l]],b[P[l]],c[l]))c[l]=las[P[l]],puts("NO");
		else las[P[l]]=c[l],puts("YES");
		if(c[l])add(1,1,q,l+1,R[l],l);
		GO(tmp);
		return;
	}
	int mid=(l+r)>>1;
	solve(p<<1,l,mid);
	solve(p<<1|1,mid+1,r);
	GO(tmp);
}
int main() {
	int k;
	scanf("%d%d%d%d",&n,&m,&k,&q);
	for(int i=1;i<=k;i++)
		for(int j=1;j<=n;j++)
			fa[i][j]=j,siz[i][j]=1;
	for(int i=1;i<=m;i++)
		scanf("%d%d",a+i,b+i);
	for(int i=1;i<=q;i++) {
		scanf("%d%d",P+i,c+i);
		if(las[P[i]])R[las[P[i]]]=i-1;
		las[P[i]]=i;
	}
	if(k==1) {
		for(int i=1;i<=q;i++) {
			if(merge(a[P[i]],b[P[i]],1))puts("YES");
			else puts("NO");
		}
		return 0;
	}
	for(int i=1;i<=m;i++)
		if(las[i])R[las[i]]=q;
	memset(las,0,sizeof(las));
	solve(1,1,q);
	return 0;
}