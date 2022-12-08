#include<bits/stdc++.h>
using namespace std;
#define bh(i,j) (((i)-1)*m+(j))
const int N=1e6+10;
vector<int>S[N];
int a[N],c[N],p[N],fa[N],val[N];
int cmp(int a,int b) {
	return c[a]<c[b];
}
int get(int x) {
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void merge(int a,int b) {
	int p=get(a),q=get(b);
	if(p==q)return;
	if(S[p].size()<S[q].size())swap(p,q);
	for(int i:S[q])
		S[p].push_back(i);
	fa[q]=p;
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",a+bh(i,j));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			fa[bh(i,j)]=bh(i,j);
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++) {
			c[j]=a[bh(i,j)];
			p[j]=j;
		}
		sort(p+1,p+m+1,cmp);
		sort(c+1,c+m+1);
		for(int j=2;j<=m;j++) {
			if(c[j]==c[j-1])merge(bh(i,p[j-1]),bh(i,p[j]));
			else S[get(bh(i,p[j]))].push_back(bh(i,p[j-1]));
		}
	}
	for(int j=1;j<=m;j++) {
		for(int i=1;i<=n;i++) {
			c[i]=a[bh(i,j)];
			p[i]=i;
		}
		sort(p+1,p+n+1,cmp);
		sort(c+1,c+n+1);
		for(int i=2;i<=n;i++) {
			if(c[i]==c[i-1])merge(bh(p[i-1],j),bh(p[i],j));
			else S[get(bh(p[i],j))].push_back(bh(p[i-1],j));
		}
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) {
			c[bh(i,j)]=a[bh(i,j)];
			p[bh(i,j)]=bh(i,j);
		}
	sort(p+1,p+n*m+1,cmp);
	for(int I=1;I<=n*m;I++) {
		int i=p[I];
		if(fa[i]!=i)continue;
		for(int j:S[i])
			val[i]=max(val[i],val[get(j)]);
		val[i]++;
	}
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++)
			printf("%d ",val[get(bh(i,j))]);
		puts("");
	}
	return 0;  
}