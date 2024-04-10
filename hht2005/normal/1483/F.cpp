#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10,mod=1e9+9;
int a[N],tr[N][26],fail[N],En[N],dep[N],tot,dfns;
int len[N],q[N],f[N],dfn[N],siz[N],c[N],las[N],cnt[N];
string s[N];
vector<int>S[N];
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
void dfs(int x) {
	dfn[x]=++dfns;
	siz[x]=1;
	for(int y:S[x]) {
		dfs(y);
		siz[x]+=siz[y];
	}
}
int main() {
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++) {
		cin>>s[i];
		int p=0;
		len[i]=s[i].size();
		for(int j=0;j<len[i];j++) {
			int c=s[i][j]-'a';
			if(!tr[p][c])tr[p][c]=++tot;
			dep[tr[p][c]]=dep[p]+1;
			p=tr[p][c];
		}
		En[p]=i;
		las[i]=p;
	}
	int h=1,e=0,ans=0;
	for(int i=0;i<26;i++)
		if(tr[0][i])q[++e]=tr[0][i];
	while(h<=e) {
		int x=q[h++];
		S[fail[x]].push_back(x);
		if(!En[x])En[x]=En[fail[x]];
		for(int i=0;i<26;i++)
			if(!tr[x][i])tr[x][i]=tr[fail[x]][i];
			else fail[q[++e]=tr[x][i]]=tr[fail[x]][i];
	}
	dfs(0);
	for(int i=1;i<=n;i++) {
		int p=0;
		for(int j=0;j<len[i];j++) {
			int c=s[i][j]-'a';
			p=tr[p][c];
			add(dfn[p],1);
			if(En[p]!=i)f[j]=En[p];
			else f[j]=En[fail[p]];
		}
		int pre=len[i];
		vector<int>V;
		for(int j=len[i]-1;j>=0;j--) {
			if(!f[j])continue;
			if(pre>j-len[f[j]]) {
				pre=j-len[f[j]];
				V.push_back(f[j]);
			}
		}
		for(int j:V)cnt[j]++;
		for(int j:V) {
			int L=dfn[las[j]],R=L+siz[las[j]]-1;
			if(qry(R)-qry(L-1)==cnt[j])ans++;
			cnt[j]=0;
		}
		p=0;
		for(int j=0;j<len[i];j++) {
			int c=s[i][j]-'a';
			p=tr[p][c];
			add(dfn[p],-1);
		}
	}
	printf("%d\n",ans);
	return 0;
}