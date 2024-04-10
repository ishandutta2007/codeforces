#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
vector<int>S[N];
using pii=pair<int,int>;
int tr[N][26],fail[N],q[N],en[N],siz[N],dfn[N],c[N],dfns;
int cnt[N],len[N],f[N],tot;
long long ans[N];
string s[N];
void ins(int x) {
	int n=s[x].size(),p=0;
	for(int i=0;i<n;i++) {
		int c=s[x][i]-'a';
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
void add(int x,int v) {
	for(int i=x;i<=tot+1;i+=i&-i)
		c[i]+=v;
}
int ask(int x) {
	int ans=0;
	for(int i=x;i;i-=i&-i)
		ans+=c[i];
	return ans;
}
int qry(int x) {
	int n=s[x].size(),p=0;
	long long ans=0;
	for(int i=0;i<n;i++) {
		p=tr[p][s[x][i]-'a'];
		ans+=ask(dfn[p]);
	}
	return ans;
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
vector<pii>Q[N],M[N];
signed main() {
	int n,m,l,r,k,L=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) {
		cin>>s[i];
		len[i]=s[i].size();
		L+=len[i];
		ins(i);
	}
	L=sqrt(L);
	build();
	for(int i=1;i<=m;i++) {
		scanf("%d%d%d",&l,&r,&k);
		if(len[k]<=L) {
			Q[r].push_back(make_pair(k,i));
			Q[l-1].push_back(make_pair(k,-i));
		} else {
			M[k].push_back(make_pair(l-1,-i));
			M[k].push_back(make_pair(r,i));
		}
	}
	for(int i=1;i<=n;i++) {
		add(dfn[en[i]],1);
		add(dfn[en[i]]+siz[en[i]],-1);
		for(auto j:Q[i]) {
			int sum=qry(j.first);
			if(j.second<0)ans[-j.second]-=sum;
			else ans[j.second]+=sum;
		}
	}
	for(int i=1;i<=n;i++) {
		if(M[i].empty())continue;
		memset(f,0,sizeof(f));
		sort(M[i].begin(),M[i].end());
		int k=0,p=0,n=s[i].size();
		for(int j=0;j<n;j++) {
			p=tr[p][s[i][j]-'a'];
			f[p]++;
		}
		for(int j=tot;j>=2;j--)
			f[fail[q[j]]]+=f[q[j]];
		long long sum=0;
		for(auto j:M[i]) {
			while(k<j.first)
				sum+=f[en[++k]];
			if(j.second<0)ans[-j.second]-=sum;
			else ans[j.second]+=sum;
		}
	}
	for(int i=1;i<=m;i++)
		printf("%lld\n",ans[i]);
	return 0;
}