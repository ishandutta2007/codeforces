#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
int c[maxn],a[maxn],b[maxn],fa[maxn],f[maxn],siz[maxn],x[maxn],y[maxn],d[maxn],sk[maxn],top;
vector<int>g[maxn];
map<int,map<int,int> >in;
int get(int x) {
	while(x!=fa[x])x=fa[x];
	return x;
}
int getd(int x) {
	int c=0;
	while(x!=fa[x])c^=d[x],x=fa[x];
	return c;
}
void merge(int a,int b,int t) {
	top++;
	if(siz[a]<siz[b]) {
		d[a]=t;
		fa[a]=b;
		siz[b]+=siz[a];
		sk[top]=a;
	} else {
		d[b]=t;
		fa[b]=a;
		siz[a]+=siz[b];
		sk[top]=b;
	}
}
int main() {
	int n,m,k,cnt=0,ans=0,sum=0;
	scanf("%d%d%d",&n,&m,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",c+i),fa[i]=i,siz[i]=1;
	for(int i=1;i<=m;i++) {
		scanf("%d%d",a+i,b+i);
		if(c[a[i]]==c[b[i]]) {
			int p=get(a[i]),q=get(b[i]),t=getd(a[i])^getd(b[i])^1;
			if(p!=q)merge(p,q,t);
			else if(t)f[c[a[i]]]=1;
		}
	}
	for(int i=1;i<=m;i++) {
		if(c[a[i]]!=c[b[i]]&&!f[c[a[i]]]&&!f[c[b[i]]]) {
			int p=c[a[i]],q=c[b[i]];
			if(p>q)swap(p,q);
			if(!in[p][q])in[p][q]=++cnt,x[cnt]=p,y[cnt]=q;
			g[in[p][q]].push_back(i);
		}
	}
	for(int i=1;i<=cnt;i++) {
		top=0;
		for(int j:g[i]) {
			int p=get(a[j]),q=get(b[j]),t=getd(a[j])^getd(b[j])^1;
			if(p!=q)merge(p,q,t);
			else if(t) {
				ans++;
				break;
			}
		}
		while(top) {
			siz[fa[sk[top]]]-=siz[sk[top]];
			d[sk[top]]=0;
			fa[sk[top]]=sk[top];
			top--;
		}
	}
	for(int i=1;i<=k;i++)
		if(!f[i])sum++;
	printf("%lld\n",1ll*sum*(sum-1)/2-ans);
	return 0;
}