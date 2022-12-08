#include<bits/stdc++.h>
using namespace std;
const int N=3e5+10;
int a[N],b[N],c[N],P[N],fa[N],siz[N],sk[N],ans[N],top,pos,cnt,n,m;
vector<int>S[N<<2];
int cmp(int a,int b) {
	return c[a]<c[b];
}
void add(int p,int l,int r,int x,int y) {
	if(x>y)return;
	if(x<=l&&r<=y) {
		S[p].push_back(x);
		return;
	}
	int mid=(l+r)>>1;
	if(x<=mid)add(p<<1,l,mid,x,y);
	if(y>mid)add(p<<1|1,mid+1,r,x,y);
}
void GO(int tmp) {
	while(top>tmp) {
		int x=sk[top],f=fa[x];
		cnt-=siz[f]&1;
		siz[f]-=siz[x];
		cnt+=siz[f]&1,cnt+=siz[x]&1;
		fa[x]=x;
		top--;
	}
}
int get(int x) {
	return fa[x]==x?x:get(fa[x]);
}
void merge(int a,int b) {
	int p=get(a),q=get(b);
	if(p==q)return;
	cnt-=siz[p]&1,cnt-=siz[q]&1;
	if(siz[p]<siz[q])swap(p,q);
	fa[q]=p;
	siz[p]+=siz[q];
	cnt+=siz[p]&1;
	sk[++top]=q;
}
void solve(int p,int l,int r) {
	int tmp=top;
	for(int i:S[p])
		merge(a[i],b[i]);
	if(l==r) {
		while(cnt&&pos<m) {
			pos++;
			if(P[pos]>l)continue;
			merge(a[P[pos]],b[P[pos]]);
			add(1,1,m,P[pos],l-1);
		}
		if(cnt)ans[l]=-1;
		else ans[l]=c[P[pos]];
		GO(tmp);
		return;
	}
	int mid=(l+r)>>1;
	solve(p<<1|1,mid+1,r);
	solve(p<<1,l,mid);
	GO(tmp);
}
int main() {
	scanf("%d%d",&n,&m);
	cnt=n;
	for(int i=1;i<=n;i++)
		fa[i]=i,siz[i]=1;
	for(int i=1;i<=m;i++) {
		scanf("%d%d%d",a+i,b+i,c+i);
		P[i]=i;
	}
	sort(P+1,P+m+1,cmp);
	solve(1,1,m);
	for(int i=1;i<=m;i++)
		printf("%d\n",ans[i]);
	return 0;
}