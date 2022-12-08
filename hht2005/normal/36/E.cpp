#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
const int N=10010;
vector<pii>S[N];
int fa[N],siz[N],deg[N],sk[N],f[N+10],hea[N],top,n=10000,Tm;
int get(int x) {
	return x==fa[x]?x:fa[x]=get(fa[x]);
}
void merge(int a,int b) {
	int p=get(a),q=get(b);
	if(p==q)return;
	siz[p]+=siz[q];
	fa[q]=p;
}
void dfs(int x) {
	for(int &i=hea[x];i<S[x].size();i++) {
		// if(x==2)cerr<<":"<<y.second<<endl;
		pii y=S[x][i];
		if(f[y.second])continue;
		f[y.second]=1;
		dfs(y.first);
		sk[++top]=y.second;
	}
}
void calc(int i,int f) {
	// cerr<<deg[i]<<' '<<f<<endl;
	if(deg[i]!=0&&deg[i]!=2&&(!f||deg[i]!=4)) {
		puts("-1");
		exit(0);
	}
	int v[4]={0,0,0,0},m=0;
	for(int j=1;j<=n;j++)
		if(get(j)==i&&S[j].size()&1)
			v[m++]=j;
	if(v[0]) {
		// S[v[0]].push_back(make_pair(v[1],++Tm));
		// S[v[1]].push_back(make_pair(v[0],Tm));
	}
	if(v[2]) {
		S[v[2]].push_back(make_pair(v[3],++Tm));
		S[v[3]].push_back(make_pair(v[2],Tm));
	}
	if(v[0]) {
		// dfs(v[1]);
		dfs(v[0]);
	}
	else dfs(i);
}
int main() {
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	int m,a,b;
	scanf("%d",&m);
	for(int i=1;i<=n;i++)
		siz[fa[i]=i]=1;
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&a,&b);
		S[a].push_back(make_pair(b,i));
		S[b].push_back(make_pair(a,i));
		merge(a,b);
	}
	Tm=m;
	int cnt=0,Mx=0;
	for(int i=1;i<=n;i++) {
		if(siz[get(i)]==1)continue;
		if(S[i].size()&1)Mx=max(Mx,++deg[get(i)]);
		if(fa[i]==i)cnt++;
	}
	if(cnt>2) {
		puts("-1");
		return 0;
	}
	if(cnt==2) {
		if(Mx>2) {
			puts("-1");
			return 0;
		}
		for(int i=1;i<=n;i++) {
			if(siz[i]==1)continue;
			if(fa[i]==i) {
				calc(i,0);
				printf("%d\n",top);
				for(int i=top;i>=1;i--)
					printf("%d ",sk[i]);
				puts("");
				top=0;
			}
		}
		return 0;
	} else {
		for(int i=1;i<=n;i++) {
			if(siz[i]==1)continue;
			if(fa[i]==i)calc(i,1);
		}
	}
	int c[2]={0,0},f=0;
	for(int i=top;i>=1;i--) {
		if(sk[i]<=m)c[f]++;
		else f=1;
	}
	if(c[1]==0)c[0]--,c[1]++;
	if(c[0]==0) {
		puts("-1");
		return 0;
	}
	printf("%d\n",c[0]);
	for(int i=top;i>=1;i--)
		if(sk[i]<=m) {
			printf("%d ",sk[i]);
			c[0]--;
			if(c[0]==0)printf("\n%d\n",c[1]);
		}
	puts("");
	return 0;
}