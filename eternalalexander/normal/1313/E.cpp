#include <bits/stdc++.h>
#define maxn 1500005
#define maxN 500005
#define maxM 1000005
typedef long long ll;
const int inf=1e8;
int n,m,c[maxN],d[maxN];
char a[maxN],b[maxN],s[maxM];
ll ans=0;
struct query{
	int l,i,d;
};query qr(int l,int i,int d){query q;q.l=l;q.i=i;q.d=d;return q;}
std::vector<query>q[maxN];
struct BIT {
	ll sum[maxM];
	void add(int p,int v){p++;while(p<=m+1){sum[p]+=v;p+=p&-p;}}
	ll query(int p){p++;ll ans=0;while(p){ans+=sum[p];p-=p&-p;}return ans;}
}cnt,sum;

struct suffixTree {
	int link[maxn<<1],len[maxn<<1],start[maxn<<1],s[maxn<<1],tail,n,rem,now,depth[maxn<<1],
	lcp[maxn<<1],vis[maxn<<1],fa[maxn<<1],rnk[maxn<<1];
	int ch[maxn<<1][28];
	suffixTree ():tail(1),n(0),rem(0),now(1) {len[0]=inf;}
	int newnode(int st,int le){
		link[++tail]=1;start[tail]=st;len[tail]=le;return tail;
	}void reset(){
		std::memset(vis,-1,sizeof(vis));
		std::memset(ch,0,sizeof(ch));
		vis[0]=0;
		tail=1;n=0;rem=0;now=1;len[0]=inf;
	}
	void extend(int x){
		s[++n]=x;rem++;
		for(register int last=1;rem;){
			while (rem>len[ch[now][s[n-rem+1]]]) rem-=len[now=ch[now][s[n-rem+1]]];
			int &v=ch[now][s[n-rem+1]];int c=s[start[v]+rem-1];
			if (!v||x==c){
				link[last]=now;last=now;
				if (!v) v=newnode(n-rem+1,inf);
				else break;
			}else{
				int u=newnode(start[v],rem-1);
				ch[u][c]=v;ch[u][x]=newnode(n,inf);
				start[v]+=rem-1;len[v]-=rem-1;
				link[last]=v=u;last=u;
			} if (now==1) rem--;else now=link[now];
		}
	}
	void dfs(int u,int f,int key){
		depth[u]=depth[f]+std::min(len[u],n-start[u]+1);
		fa[u]=f;
		int flg=1;
		for(register int i=0;i<=27;++i)if(ch[u][i]){dfs(ch[u][i],u,key);flg=0;}
		if(flg){
			rnk[n-depth[u]+1]=u;
			if(n-depth[u]+1==key)vis[u]=depth[u];
		}
		if(vis[u]!=-1)vis[f]=depth[f];
	}void work(int lim){
		for(int i=1;i<=lim;++i){
			int u=rnk[i];
			while(vis[fa[u]]==-1)u=fa[u];
			int v=rnk[i];
			while(vis[fa[v]]==-1){vis[v]=vis[fa[u]];v=fa[v];}
			vis[u]=vis[fa[u]];
			lcp[i]=vis[u];
		}
	}
			
}s1;

void prework(){
	std::memset(s1.vis,-1,sizeof(s1.vis));
	for(int i=1;i<=n;++i)s1.extend(a[i]-'a');s1.extend(26);
	for(int i=1;i<=m;++i)s1.extend(s[i]-'a');s1.extend(27);
	s1.dfs(1,0,n+2);s1.work(n);
	for(int i=1;i<=n;++i)c[i]=s1.lcp[i];
	s1.reset();
	for(int i=1;i<=n;++i)s1.extend(b[n-i+1]-'a');s1.extend(26);
	for(int i=1;i<=m;++i)s1.extend(s[m-i+1]-'a');s1.extend(27);
	s1.dfs(1,0,n+2);s1.work(n);
	for(int i=1;i<=n;++i)d[i]=s1.lcp[n-i+1];
}

int main(){
//	freopen("in.txt","r",stdin); 
	scanf("%d%d%s%s%s",&n,&m,a+1,b+1,s+1);
	prework();
//	for(int i=1;i<=n;++i)printf("%d ",c[i]);printf("\n");
	//for(int i=1;i<=n;++i)printf("%d ",d[i]);printf("\n");
	for(int i=1;i<=n;++i){if(c[i]==m)c[i]--;if(d[i]==m)d[i]--;}
	for(int i=1;i<=n;++i){
		q[i].push_back(qr(c[i],i,1));
		if(i+m-1<=n)q[i+m-1].push_back(qr(c[i],i,-1));
	}
	for(register int i=n;i>=1;i--){
		cnt.add(m-d[i],1);sum.add(m-d[i],m-d[i]-1);
		for(query j:q[i])
			ans+=j.d*(cnt.query(j.l)*j.l-sum.query(j.l));
	}printf("%lld",ans);
	return 0;
}