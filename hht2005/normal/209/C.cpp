#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int fa[N],siz[N],deg[N],cnt[N];
int get(int x) {
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void merge(int a,int b) {
	int p=get(a),q=get(b);
	siz[p]++;
	if(p==q)return;
	siz[p]+=siz[q];
	fa[q]=p;
}
int main() {
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		fa[i]=i,siz[i]=0;
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&a,&b);
		deg[a]++,deg[b]++;
		merge(a,b);
	}
	int A=0,B=0,C=0;
	for(int i=1;i<=n;i++) {
		if(i!=1&&!siz[get(i)])continue;
		if(deg[i]&1)cnt[get(i)]++;
		A+=deg[i]&1;
	}
	for(int i=1;i<=n;i++) {
		if(i!=1&&!siz[get(i)])continue;
		if(fa[i]==i) {
			if(!cnt[i])B++;
			else C++;
		}
	}
	if(B+C>1)printf("%d\n",A/2+B);
	else printf("%d\n",A/2);
	return 0;
}