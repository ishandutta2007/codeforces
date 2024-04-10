#include<bits/stdc++.h>
using namespace std;
#define End {puts("-1");return 0;}
const int N=1e5+10;
int a[N],b[N],c[N],fa[N],f[N];
int get(int x) {
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
int main() {
	int n,m,cnt=0;
	char S[3];
	scanf("%d%d",&n,&m);
	if(n%2==0)End;
	for(int i=1;i<=n;i++)
		fa[i]=i;
	for(int i=1;i<=m;i++) {
		scanf("%d%d%s",a+i,b+i,S);
		if(S[0]=='S') {
			c[i]=1;
			if(get(a[i])!=get(b[i])) {
				cnt++;
				fa[fa[a[i]]]=fa[b[i]];
			}
		}
	}
	if(cnt<n/2)End;
	for(int i=1;i<=m;i++)
		if(c[i]==0&&get(a[i])!=get(b[i])) {
			cnt++;
			fa[fa[a[i]]]=fa[b[i]];
			f[i]=1;
		}
	if(cnt!=n-1)End;
	for(int i=1;i<=n;i++)fa[i]=i;
	cnt=0;
	for(int i=1;i<=m;i++)
		if(f[i]) {
			cnt++;
			fa[fa[a[i]]]=fa[b[i]];
		}
	for(int i=1;i<=m;i++)
		if(!f[i]&&c[i]==0&&get(a[i])!=get(b[i])) {
			fa[fa[a[i]]]=fa[b[i]];
			cnt++;
			f[i]=1;
			if(cnt==n/2)break;
		}
	if(cnt<n/2)End;
	for(int i=1;i<=m;i++)
		if(c[i]&&get(a[i])!=get(b[i])) {
			fa[fa[a[i]]]=fa[b[i]];
			f[i]=1;
		}
	printf("%d\n",n-1);
	for(int i=1;i<=m;i++)
		if(f[i])printf("%d ",i);
	puts("");
	return 0;
}