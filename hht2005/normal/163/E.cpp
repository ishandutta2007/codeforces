#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int tr[N][26],fail[N],q[N],en[N],siz[N],dfn[N],c[N],dfns,cnt[N],tot;
char s[N];
vector<int>S[N];
void ins(int x) {
	int n=strlen(s+1),p=0;
	for(int i=1;i<=n;i++) {
		int c=s[i]-'a';
		if(!tr[p][c])tr[p][c]=++tot;
		p=tr[p][c];
	}
	en[x]=p;
}
void dfs(int x) {
	dfn[x]=++dfns;
	siz[x]=1;
	for(int y:S[x]) {
		dfs(y);
		siz[x]+=siz[y];
	}
}
void build() {
	int l=1,r=0;
	for(int i=0;i<26;i++)
		if(tr[0][i])
			q[++r]=tr[0][i];
	while(l<=r) {
		int x=q[l++];
		S[fail[x]].push_back(x);
		for(int i=0;i<26;i++)
			if(tr[x][i])fail[q[++r]=tr[x][i]]=tr[fail[x]][i];
			else tr[x][i]=tr[fail[x]][i];
	}
	dfs(0);
}
void add(int x,int v) {
	for(int i=x;i<=tot+1;i+=i&-i)
		c[i]+=v;
}
int qry(int x) {
	int ans=0;
	for(int i=x;i;i-=i&-i)
		ans+=c[i];
	return ans;
}
long long qry() {
	int p=0,n=strlen(s+1);
	long long ans=0;
	for(int i=1;i<=n;i++) {
		p=tr[p][s[i]-'a'];
		ans+=qry(dfn[p]);
	}
	return ans;
}
signed main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;i++) {
		scanf("%s",s+1);
		ins(i);
	}
	build();
	for(int i=1;i<=m;i++) {
		add(dfn[en[i]],1),add(dfn[en[i]]+siz[en[i]],-1);
		cnt[i]=1;
	}
	for(int i=1;i<=n;i++) {
		scanf("%s",s);
		if(*s=='?')printf("%lld\n",qry());
		else {
			int x;
			sscanf(s+1,"%d",&x);
			int x1=en[x];
			if(*s=='+') {
				if(!cnt[x])add(dfn[x1],1),add(dfn[x1]+siz[x1],-1),cnt[x]++;
			}
			if(*s=='-') {
				if(cnt[x])add(dfn[x1],-1),add(dfn[x1]+siz[x1],1),cnt[x]--;
			}
		}
	}
	return 0;
}