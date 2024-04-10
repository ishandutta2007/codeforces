#include <bits/stdc++.h>
#define maxn 200005
#define ll long long
const int mod = 1e9+7;
int phi[maxn],P[maxn],dfn[maxn],d[maxn],anc[maxn][19],seq[maxn],stk[maxn<<1],a[maxn],p[maxn],
ans[maxn],sum1[maxn],sum2[maxn],tl,t1,cnt,idx,n,u,v;
std::vector<int>ch[maxn],E[maxn];
void clear(int x){while(!E[x].empty())E[x].pop_back();}
int cmp(int a,int b){return dfn[a]<dfn[b];}

int qpow(int a,int b){
	if(b==0)return 1;
	ll d=qpow(a,b>>1);d=d*d%mod;
	if(b&1)d=d*a%mod;
	return d;
}int inv(int x){return qpow(x,mod-2);}

void sieve() {
	phi[1] = 1;
	for(int i=2;i<=n;++i){
		if(!phi[i]){phi[i]=i-1;P[++t1]=i;}
		for(int j=1;j<=t1&&i*P[j]<=n;++j){
			if(i%P[j])phi[i*P[j]]=phi[i]*phi[P[j]];
			else {phi[i*P[j]]=phi[i]*P[j];break;}
		}
	}
}

void dfs(int u,int f){
	anc[u][0]=f;d[u]=d[f]+1;dfn[u]=++idx;
	for(int i=1;i<=18;++i)anc[u][i]=anc[anc[u][i-1]][i-1];
	for(int v:ch[u])if(v!=f)dfs(v,u);
}

int lca(int u,int v){
	if (d[u] < d[v]) std::swap(u,v);
	for(int i=18;i>=0;i--)if(d[anc[u][i]]>=d[v])u=anc[u][i];
	if(u==v)return u;
	for(int i=18;i>=0;i--)if(anc[u][i]!=anc[v][i]){u=anc[u][i];v=anc[v][i];}
	return anc[u][0];
}

void build_virtual_tree(){
	stk[tl=1]=1;clear(1);
	std::sort(seq+1,seq+cnt+1,cmp);
	for(int i=1;i<=cnt;++i){
		if(seq[i]==1)continue;
		int l = lca(seq[i],stk[tl]);
		if (l!=stk[tl]){
			while(dfn[stk[tl-1]]>dfn[l]) {
				E[stk[tl-1]].push_back(stk[tl]);
				tl--;
			} if (l!=stk[tl-1]) {
				clear(l);
				E[l].push_back(stk[tl]);
				stk[tl]=l;
			} else 
				E[l].push_back(stk[tl--]);
		}
		clear(seq[i]); stk[++tl]=seq[i];
	}for(int i=1;i<tl;++i)E[stk[i]].push_back(stk[i+1]);
	
}

int dis(int u,int v){return d[u]+d[v]-2*d[lca(u,v)];}

void dfs1(int u,int pt){
	sum1[u]=a[u]%pt==0?phi[a[u]]:0;
	sum2[u]=0;
	for(int v:E[u]){
		dfs1(v,pt);
		int s2 = (sum2[v] + (ll)sum1[v]*dis(u,v)%mod)%mod;
		ans[pt] = 
		((ll)ans[pt] + (ll)sum1[v]*sum2[u]%mod + (ll)s2*sum1[u]%mod)%mod;
		sum1[u]=(sum1[u]+sum1[v])%mod;
		sum2[u]=(sum2[u]+s2)%mod;
	}
}
	

int main(){
	scanf("%d",&n);
	sieve();
	for(int i=1;i<=n;++i){
		scanf("%d",&a[i]);
		p[a[i]]=i;
	}for(int i=1;i<n;++i){
		scanf("%d%d",&u,&v);
		ch[u].push_back(v);
		ch[v].push_back(u);
	}dfs(1,0);
	int tot = 0;
	for (int i=n;i>=1;i--){
		cnt=0;
		for(int j=i;j<=n;j+=i)seq[++cnt]=p[j];
		build_virtual_tree();
		dfs1(1,i); ans[i] = ans[i]*2%mod;
		for (int j=i+i;j<=n;j+=i)ans[i]=(ans[i]-ans[j]+mod)%mod;
		tot = (tot + (ll)ans[i]*i%mod*inv(phi[i])%mod) % mod;
	} printf("%lld",(ll)tot*inv((ll)n*(n-1)%mod)%mod);
	return 0;
}