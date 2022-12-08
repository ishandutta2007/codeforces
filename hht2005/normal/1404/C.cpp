#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10;
int a[maxn],ans[maxn],Min[maxn<<2],f[maxn<<2],pos[maxn<<2],c[maxn],n;
vector<int>P1[maxn],P2[maxn];
void tag(int p,int v) {
	f[p]+=v;
	Min[p]+=v;
}
void pushdown(int p) {
	if(f[p]) {
		tag(p<<1,f[p]);
		tag(p<<1|1,f[p]);
		f[p]=0;
	}
}
void updata(int p) {
	Min[p]=min(Min[p<<1],Min[p<<1|1]);
	if(Min[p<<1|1]<=Min[p<<1])pos[p]=pos[p<<1|1];
	else pos[p]=pos[p<<1];
}
void add(int p,int l,int r,int x,int y) {
	if(x<=l&&r<=y)return tag(p,-1);
	pushdown(p);
	int mid=(l+r)>>1;
	if(x<=mid)add(p<<1,l,mid,x,y);
	if(y>mid)add(p<<1|1,mid+1,r,x,y);
	updata(p);
}
void change(int p,int l,int r,int x,int v) {
	if(l==r) {
		Min[p]=v;
		pos[p]=x;
		return;
	}
	pushdown(p);
	int mid=(l+r)>>1;
	if(x<=mid)change(p<<1,l,mid,x,v);
	else change(p<<1|1,mid+1,r,x,v);
	updata(p);
}
void add(int x,int v) {
	for(int i=x;i<=n;i+=i&-i)c[i]+=v;
}
int sum(int x) {
	int ans=0;
	for(int i=x;i;i-=i&-i)ans+=c[i];
	return ans;
}
int main() {
	int q,x,y;
	scanf("%d%d",&n,&q);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i),a[i]=i-a[i];
	for(int i=1;i<=q;i++) {
		scanf("%d%d",&x,&y);
		P1[x+1].push_back(y);
		P2[x+1].push_back(i);
	}
	memset(Min,0x3f,sizeof(Min));
	memset(pos,-1,sizeof(pos));
	for(int i=n;i>=1;i--) {
		if(a[i]>=0)change(1,1,n,i,a[i]);
		while(Min[1]==0) {
			int P=pos[1];
			add(P,1);
			change(1,1,n,P,1e9);
			add(1,1,n,P+1,n);
		}
		for(int j=0;j<P1[i].size();j++)
			ans[P2[i][j]]=sum(n-P1[i][j]);
	}
	for(int i=1;i<=q;i++)
		printf("%d\n",ans[i]);
	return 0;
}