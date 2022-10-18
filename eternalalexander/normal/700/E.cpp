#include <bits/stdc++.h>
#define maxn 400005
const int inf=1e8;
int ch[maxn<<5][2],sum[maxn<<5],rt[maxn<<1],anc[maxn<<1][19],
sfx[maxn<<1],/*ref[maxn],*/f[maxn<<1],tl,d[maxn<<1],n,ans;
char s[maxn];

struct suffixTree {
    int link[maxn<<1],len[maxn<<1],start[maxn<<1],s[maxn<<1],n,tail,now,rem,ch[maxn<<1][27];
    suffixTree ():n(0),tail(1),now(1),rem(0) {len[0]=inf;}
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
}sft;

int insert(int rt,int l,int r,int p){
	int nrt=++tl;
	sum[nrt]=sum[rt]+1;
	if(l==r)return nrt;
	ch[nrt][0]=ch[rt][0];
	ch[nrt][1]=ch[rt][1];
	int mid=(l+r)>>1;
	if (p<=mid) ch[nrt][0]=insert(ch[rt][0],l,mid,p);
	else ch[nrt][1]=insert(ch[rt][1],mid+1,r,p);
	return nrt;
}

int merge(int u,int v) {
	if (!u || !v) return u+v;
	int nrt = ++tl;
	ch[nrt][0] = merge(ch[u][0],ch[v][0]);
	ch[nrt][1] = merge(ch[u][1],ch[v][1]);
	sum[nrt]=sum[u]+sum[v];
	return nrt;
}

int query(int rt,int L,int R,int l,int r){
	if(!rt||l>R||r<L)return 0;
	if(l<=L&&R<=r)return sum[rt];
	return query(ch[rt][0],L,(L+R)>>1,l,r) + query(ch[rt][1],((L+R)>>1)+1,R,l,r);
}

void dfs(int u,int f){
    int iL=1;
    anc[u][0]=f;
    d[u]=d[f]+std::min(sft.len[u],n-sft.start[u]+1);
    for(int i=1;i<=18;++i)
		anc[u][i]=anc[anc[u][i-1]][i-1];
	for(int i=0;i<=26;++i)
    	if(sft.ch[u][i]){ 
			dfs(sft.ch[u][i],u);
			iL=0; sfx[u]=sfx[sft.ch[u][i]];
			rt[u]=merge(rt[u],rt[sft.ch[u][i]]);
		}
    if (iL&&d[u]) {
		rt[u]=insert(rt[u],1,n,n-d[u]+1);
		sfx[u]=n-d[u]+1;
	//	ref[n-d+1]=u;
	}
} 

void dfs1(int u){
	if(u!=1&&!d[u])return;
	int x=u;
	for(int i=18;i>=0;i--)
		if(anc[x][i]&&query(rt[anc[x][i]],1,n,sfx[u],sfx[u]+d[u]-d[anc[x][i]])<2)
			x=anc[x][i];
	x=anc[x][0];
	if(x&&x!=1)f[u]=std::max(f[u],f[x]+1);
	for (int i=0;i<=26;++i) 
		if(sft.ch[u][i])dfs1(sft.ch[u][i]);
}

int main(){
	scanf("%d",&n);scanf("%s",s+1);
	for(int i=1;i<=n;++i)sft.extend(s[i]-'a');sft.extend(26); 
	dfs(1,0);dfs1(1);
	for(int i=1;i<=sft.tail;++i)ans=std::max(ans,f[i]);
	printf("%d",ans+1);
	return 0;
}