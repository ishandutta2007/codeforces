#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10;
vector<int>S[N];
int a[N],b[N],x[N],y[N],fa[N],f[N],ST[N],TT[N],cnt;
inline int get(int x) {
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
signed main() {
	int n,m,s,t,ds,dt;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) {
		scanf("%d%d",a+i,b+i);
		S[a[i]].push_back(b[i]);
		S[b[i]].push_back(a[i]);
	}
	scanf("%d%d%d%d",&s,&t,&ds,&dt);
	for(int i=1;i<=n;i++)fa[i]=i;
	for(int i=1;i<=m;i++) {
		if(a[i]==s||a[i]==t||b[i]==s||b[i]==t)continue;
		if(get(a[i])==get(b[i]))continue;
		x[++cnt]=a[i],y[cnt]=b[i];
		fa[get(a[i])]=get(b[i]);
	}
	for(int y:S[s])f[get(y)]|=1,ST[get(y)]=y;
	for(int y:S[t])f[get(y)]|=2,TT[get(y)]=y;
	int FL=0;
	for(int i=1;i<=n;i++) {
		if(s==i||t==i)continue;
		if(fa[i]!=i)continue;
		if(f[i]==1||(f[i]==3&&!FL)) {
			ds--;
			x[++cnt]=ST[i];
			y[cnt]=s;
		}
		if(f[i]==2||(f[i]==3&&!FL)) {
			dt--;
			x[++cnt]=TT[i];
			y[cnt]=t;
		}
		if(f[i]==3&&FL) {
			if(ds>dt) {
				ds--;
				x[++cnt]=ST[i];
				y[cnt]=s;
			} else {
				dt--;
				x[++cnt]=TT[i];
				y[cnt]=t;
			}
		}
		if(f[i]==3)FL=1;
	}
	if(!FL) {
		ds--,dt--;
		x[++cnt]=s,y[cnt]=t;
	}
	if(ds<0||dt<0)puts("No");
	else {
		puts("Yes");
		for(int i=1;i<n;i++)
			printf("%d %d\n",x[i],y[i]);
	}
	return 0;
}