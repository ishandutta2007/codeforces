#include<bits/stdc++.h>
using namespace std;
const int N=400010;
int a[N],ans[N],Min;
vector<int>S[N];
void add(int p,int l,int r,int x,int v) {
	if(r<=x) {
		auto it=upper_bound(S[p].begin(),S[p].end(),v);
		if(it!=S[p].end())ans[p]=min(ans[p],*it-v);
		if(it!=S[p].begin())ans[p]=min(ans[p],v-*--it);
		if(Min<=ans[p])return;
	}
	if(l==r) {
		Min=min(Min,ans[p]);
		return;
	}
	int mid=(l+r)>>1;
	if(x>mid)add(p<<1|1,mid+1,r,x,v);
	add(p<<1,l,mid,x,v);
	ans[p]=min(ans[p],min(ans[p<<1],ans[p<<1|1]));
	Min=min(Min,ans[p]);
}
int qry(int p,int l,int r,int x,int y) {
	if(x<=l&&r<=y)return ans[p];
	int mid=(l+r)>>1,Min=1e9;
	if(x<=mid)Min=min(Min,qry(p<<1,l,mid,x,y));
	if(y>mid)Min=min(Min,qry(p<<1|1,mid+1,r,x,y));
	return Min;
}
void build(int p,int l,int r) {
	ans[p]=1e9;
	for(int i=l;i<=r;i++)
		S[p].push_back(a[i]);
	sort(S[p].begin(),S[p].end());
	if(l==r)return;
	int mid=(l+r)>>1;
	build(p<<1,l,mid);
	build(p<<1|1,mid+1,r);
}
int Ans[N];
vector<pair<int,int> >Q[N];
int main() {
	int n,m,x,y;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	scanf("%d",&m);
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&x,&y);
		Q[y].push_back(make_pair(x,i));
	}
	build(1,1,n);
	for(int i=1;i<=n;i++) {
		Min=1e9;
		add(1,1,n,i-1,a[i]);
		for(auto j:Q[i])
			Ans[j.second]=qry(1,1,n,j.first,i);
	}
	for(int i=1;i<=m;i++)
		printf("%d\n",Ans[i]);
	return 0;
}