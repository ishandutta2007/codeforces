#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int tr[N][26],fail[N],en[N],q[N],dfn[N],siz[N],c[N],dfns,tot;
long long ans[N];
string s[N];
struct node {
	int k,id,v;
	node(){}
	node(int K,int ID,int V) {
		k=K,id=ID,v=V;
	}
};
vector<int>S[N];
vector<node>pos[N];
void dfs(int x) {
	dfn[x]=++dfns;
	siz[x]=1;
	for(int y:S[x]) {
		dfs(y);
		siz[x]+=siz[y];
	}
}
void add(int x,int v) {
	for(int i=x;i<=tot+1;i+=i&-i)
		c[i]+=v;
}
int qry(int x) {
	int sum=0;
	for(int i=x;i;i-=i&-i)
		sum+=c[i];
	return sum;
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		cin>>s[i];
		int p=0;
		for(int j=0;j<int(s[i].size());j++) {
			int c=s[i][j]-'a';
			if(!tr[p][c])tr[p][c]=++tot;
			p=tr[p][c];
		}
		en[i]=p;
	}
	int h=1,e=0;
	for(int i=0;i<26;i++)
		if(tr[0][i]) {
			fail[q[++e]=tr[0][i]]=0;
			S[fail[q[e]]].push_back(q[e]);
		}
	while(h<=e) {
		int x=q[h++];
		for(int i=0;i<26;i++)
			if(tr[x][i]) {
				q[++e]=tr[x][i];
				fail[q[e]]=tr[fail[x]][i];
				S[fail[q[e]]].push_back(q[e]);
			} else tr[x][i]=tr[fail[x]][i];
	}
	dfs(0);
	int l,r,k;
	for(int i=1;i<=m;i++) {
		scanf("%d%d%d",&l,&r,&k);
		pos[l-1].push_back(node(k,i,-1));
		pos[r].push_back(node(k,i,1));
	}
	for(int i=1;i<=n;i++) {
		int p=0;
		for(int j=0;j<int(s[i].size());j++) {
			int c=s[i][j]-'a';
			p=tr[p][c];
			add(dfn[p],1);
		}
		for(node j:pos[i]) {
			int x=en[j.k];
			ans[j.id]+=j.v*(qry(dfn[x]+siz[x]-1)-qry(dfn[x]-1));
		}
	}
	for(int i=1;i<=m;i++)
		printf("%lld\n",ans[i]);
	return 0;
}