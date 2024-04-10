#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,m,ch[100005][26],tot,edp[100005],fail[100005],is[100005];
int dfn[100005],sign,size[100005],c[100005];
ll ans[100005],sum[100005];
char str[100005];
string s[100005];
struct P{
	int l,r,k,id,dlt;
};
vector<int> g[100005];
vector<P> o[100005],O[100005];
void dfs(int x,int fa){
	dfn[x]=++sign,size[x]=1;
	for(int y:g[x])if(y^fa)dfs(y,x),size[x]+=size[y];
}
void dfs2(int x,int fa){
	for(int y:g[x])if(y^fa)dfs2(y,x),is[x]+=is[y];
}
void U(int x,int k){
	while(x<=tot+1)c[x]+=k,x+=x&-x;
}
int Q(int x){
	int r=0;
	while(x)r+=c[x],x-=x&-x;
	return r;
}
void Solve1(int id){
	for(int i=0,now=0;i<s[id].length();i++)now=ch[now][s[id][i]-'a'],is[now]=1;
	dfs2(0,0);
	for(int i=1;i<=m;i++)sum[i]=sum[i-1]+is[edp[i]];
	for(P i:o[id])ans[i.id]=sum[i.r]-sum[i.l-1];
	for(int i=1;i<=tot;i++)is[i]=0;
}
void Solve2(int id){
	for(P w:O[id]){
		for(int i=0,now=0;i<s[w.k].length();i++){
			now=ch[now][s[w.k][i]-'a'];
			ans[w.id]+=w.dlt*Q(dfn[now]);
		}
	}
}
int main() {
	scanf("%d%d",&m,&n);
	for(int i=1,len,now; i<=m; i++) {
		scanf("%s",str),len=strlen(str),now=0,s[i]=str;
		for(int i=0; i<len; i++) {
			int w=str[i]-'a';
			if(!ch[now][w])ch[now][w]=++tot;
			now=ch[now][w];
		}
		edp[i]=now;
	}
	queue<int> q;
	for(int i=0; i<26; i++)if(ch[0][i])q.push(ch[0][i]);
	while(!q.empty()) {
		int x=q.front();
		q.pop(),g[fail[x]].push_back(x);
		for(int i=0; i<26; i++) {
			int y=ch[x][i];
			if(y)fail[y]=ch[fail[x]][i],q.push(y);
			else ch[x][i]=ch[fail[x]][i];
		}
	}
	dfs(0,0);
	for(int i=1,l,r,k;i<=n;i++){
		scanf("%d%d%d",&l,&r,&k);
		if(s[k].length()>=250)o[k].push_back({l,r,k,i,0});
		else O[l-1].push_back({l,r,k,i,-1}),O[r].push_back({l,r,k,i,1});
	}
	for(int i=1;i<=m;i++){
		U(dfn[edp[i]],1),U(dfn[edp[i]]+size[edp[i]],-1);
		if(o[i].size()&&s[i].length()>=250)Solve1(i);
		if(O[i].size())Solve2(i);
	}
	for(int i=1;i<=n;i++)printf("%lld\n",ans[i]);
}