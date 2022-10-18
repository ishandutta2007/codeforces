#include <bits/stdc++.h>
#define maxn 200005
#define ll long long
int n;
ll ans,sum[maxn<<1];
std::set<int>set[maxn];
char s[maxn];
const int inf=1e8;
struct suffixTree {
    int link[maxn<<1],len[maxn<<1],start[maxn<<1],s[maxn<<1],n,tail,now,rem,ch[maxn<<1][27],
	dfn[maxn<<1],rc[maxn],ref[maxn<<1],idx,depth[maxn<<1],anc[maxn<<1][19],d[maxn<<1];
    suffixTree ():n(0),tail(1),now(1),rem(0),idx(0) {len[0]=inf;}
    void reset(){std::memset(ch,0,sizeof(ch));n=0;tail=1;now=1;rem=0;idx=0;len[0]=inf;}
    int newnode(int st,int le){
        link[++tail]=1;start[tail]=st;len[tail]=le;return tail;
    }void extend(int x){
        s[++n]=x;rem++;
        for (int last=1;rem;){
            while (rem>len[ch[now][s[n-rem+1]]]) 
                rem-=len[now=ch[now][s[n-rem+1]]];
            int &v=ch[now][s[n-rem+1]];int c=s[start[v]+rem-1];
            if (!v||x==c){
                link[last]=now;last=now;
                if (!v) v=newnode(n,inf);
                else break; 
            }else{ 
                int u=newnode(start[v],rem-1);
                ch[u][c]=v;ch[u][x]=newnode(n,inf);
                start[v]+=rem-1;len[v]-=rem-1; 
                link[last]=v=u;last=u;
            } if (now==1) rem--;else now=link[now];
        }
	}
	ll dfs(int u){
        ll ans=std::min(len[u],n-start[u]+1);
        for(int i=0;i<=26;++i)
        	if(ch[u][i])ans+=dfs(ch[u][i]);
        return ans;
    }
	int dfs1(int u,int f=0){
        dfn[u]=++idx;ref[idx]=u;
        d[u]=d[f]+1;
        depth[u]=depth[f]+std::min(len[u],n-start[u]);
        anc[u][0]=f;
		for(int i=1;i<=17;++i)anc[u][i]=anc[anc[u][i-1]][i-1];
        int flag=0;
        for(int i=0;i<=26;++i)
        	if(ch[u][i])flag=dfs1(ch[u][i],u);
        if(!flag){
        	//printf("rc %d = %d\n",n-depth[u],dfn[u]);
			rc[n-depth[u]]=dfn[u];
		}
        return 1;
    }int lca(int x,int y){
        int u=ref[x],v=ref[y];
        if(d[u]<d[v])std::swap(u,v);
        for(int i=17;i>=0;i--)if(d[anc[u][i]]>=d[v])u=anc[u][i];
        if(u==v)return u;
        for(int i=17;i>=0;i--)if(anc[u][i]!=anc[v][i]){u=anc[u][i];v=anc[v][i];}
        return depth[anc[u][0]];
    }
}sft,rev,st;

ll calc(int l,int r){
	st.reset();
	for(int i=l;i<=r;++i)st.extend(s[i]-'a');
	return st.dfs(1);
}

void dfs(int u){
	int flag=0;sum[u]=0;
	if(sft.depth[u]==0&&sft.d[u]==2)return;
	for(int i=0;i<=26;++i){
		int v=sft.ch[u][i];
		if(!v||!sft.depth[v])continue;
		dfs(v);flag=1;
		if(set[u].size()<set[v].size()){
			std::swap(set[u],set[v]);
			std::swap(sum[u],sum[v]);
		}
			
		for(int x:set[v]){
			int len=0;
			auto pre=set[u].lower_bound(x);
			if(pre!=set[u].begin()){
				pre--;
				len=std::max(len,rev.lca(*pre,x));
				
			}
			auto nxt=set[u].upper_bound(x);
			if(nxt!=set[u].end())
				len=std::max(len,rev.lca(*nxt,x));
			sum[u]+=rev.depth[rev.ref[x]]-len;
			set[u].insert(x);
		}
	}if(!flag){
		if(sft.depth[u]+2<=n){
			set[u].insert(rev.rc[sft.depth[u]+2]);
			sum[u]+=rev.depth[rev.ref[rev.rc[sft.depth[u]+2]]];
		}
		
	}
	if(sft.depth[u])
		ans+=(sft.depth[u]-sft.depth[sft.anc[u][0]])*sum[u];

}

int main(){
	scanf("%s",s+1);n=std::strlen(s+1);
	for(int i=1;i<=n;++i)sft.extend(s[i]-'a');
	ans+=sft.dfs(1)+calc(1,n-1)+calc(2,n);
	sft.extend(26);
	for(int i=1;i<=n;++i)rev.extend(s[n-i+1]-'a');rev.extend(26);
	sft.dfs1(1);rev.dfs1(1);
	dfs(1);
	printf("%lld",ans+2);
	return 0;
}