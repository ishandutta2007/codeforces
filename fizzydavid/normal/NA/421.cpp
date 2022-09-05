//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
const int mod=1e9+7;
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
const int maxn=200111;
const int maxTRIEn=1800111;
namespace KMP
{
	ll rdown(ll p,ll q){return q<0?rdown(-p,-q):(p>0?p/q:-(-p+q-1)/q);}
	ll rup(ll p,ll q){return -rdown(-p,q);}
	struct sub
	{
		int s,d,cnt;//d>0
		sub(int S=0,int D=0,int CNT=0){s=S;d=D;cnt=CNT;}
		int end()const{return s+(cnt-1)*d;}
		bool has(int x)const{return x>=s&&x<=end()&&(x-s)%d==0;}
		int calc(const sub &t)
		{
			if(d==t.d)
			{
				if((s-t.s)%d!=0)return 0;
				else return max(0,(min(end(),t.end())-max(s,t.s))/d+1);
			}
			else if(cnt==1)return t.has(s);
			else return has(t.s);
		}
		sub flip(int x){return sub(x-(s+(cnt-1)*d),d,cnt);}
	};
	vector<int> Fail[maxn],Slink[maxn];
	void construct(char s[],int n,int id)
	{
		vector<int> &fail=Fail[id],&slink=Slink[id];
		fail.resize(n+1);
		slink.resize(n+1);
		fail[0]=0;fail[1]=0;
		for(int i=2;i<=n;i++)
		{
			int &p=fail[i];
			p=fail[i-1];
			while(p&&s[p+1]!=s[i])p=fail[p];
			if(s[p+1]==s[i])p++;
		}
		for(int i=1;i<=n;i++)slink[i]=fail[i]==0?0:(i-fail[i]==fail[i]-fail[fail[i]]?slink[fail[i]]:fail[i]);
	}
	vector<sub> extract(int id,int x)
	{
		vector<int> &fail=Fail[id],&slink=Slink[id];
		assert(x<fail.size()&&x<slink.size());
		vector<sub> ret;
		while(x)
		{
			int d=x-fail[x];
			ret.PB(sub(slink[x]+d,d,(x-slink[x])/d));
			x=slink[x];
		}
		reverse(ret.begin(),ret.end());
		if(ret.back().cnt>1)ret.back().cnt--,ret.PB(sub(ret.back().end()+ret.back().d,1,1));
		return ret;
	}
	int query(int x,int xl,int y,int yl,int tot)
	{
		if(xl==0||yl==0||xl+yl<tot)return 0;
		vector<sub> vx=extract(x,xl);
		vector<sub> vy=extract(y,yl);
		for(int i=0;i<vy.size();i++)vy[i]=vy[i].flip(tot);
		reverse(vy.begin(),vy.end());
		int itx=0,ity=0,ret=0;
		while(itx<vx.size()&&ity<vy.size())
		{
			ret+=vx[itx].calc(vy[ity]);
			if(vx[itx].end()<=vy[ity].end())itx++;
			else ity++;
		}
		return ret;
	}
};
const ll hs_B=233;
const ll hs_mod=100000000000031ll;
int bit_tab[maxTRIEn];
void bit_add(int x,int coef)
{
	for(int i=x;i<maxTRIEn;i+=i&(-i))bit_tab[i]+=coef;
}
int bit_query(int x)
{
	int ret=0;
	for(int i=x;i;i-=i&(-i))ret+=bit_tab[i];
	return ret;
}
const int HashMsk=(1<<22)-1;
struct HashTable
{
	int hs[HashMsk],val[HashMsk];
	HashTable(){memset(hs,-1,sizeof(hs));memset(val,-1,sizeof(val));}
	int getpos(int p){return ((p<<5)^(p>>3))&HashMsk;}
	int find(int chs)
	{
		int p=getpos(chs);
		while(hs[p]!=-1&&hs[p]!=chs)p=(p+1)&HashMsk;
		return val[p];
	}
	int& get(int chs)
	{
		int p=getpos(chs);
		while(hs[p]!=-1&&hs[p]!=chs)p=(p+1)&HashMsk;
		if(hs[p]==-1)hs[p]=chs,val[p]=-1;
		return val[p];
	}
};
namespace AC
{
	//TRIE
	int tot=1;
	vector<pair<char,int> > go[maxTRIEn];
	HashTable gomp;
	ll hs[maxTRIEn];
	int fa[maxTRIEn],pc[maxTRIEn];
	pair<ll,int> hs_arr[maxTRIEn];
	
	int insert(int p,int c)
	{
		int &q=gomp.get(p<<8|c);
		if(q==-1)
		{
			q=++tot,fa[q]=p,pc[q]=c,hs[q]=(hs[p]*hs_B+c+1)%hs_mod;
			go[p].PB(MP(c,q));
			assert(tot<maxTRIEn);
		}
		return q;
	}
	int fail[maxTRIEn];
	vector<int> con[maxTRIEn];//store fail tree
	int fdfn[maxTRIEn],fdfnr[maxTRIEn],dfntot;
	void fdfs(int x)
	{
		fdfn[x]=++dfntot;
		for(int i=0;i<con[x].size();i++)
		{
			int u=con[x][i];
			fdfs(u);
		}
		fdfnr[x]=dfntot;
	}
	
	//HLD
	int son[maxTRIEn],top[maxTRIEn],lv[maxTRIEn];
	set<int> st[maxTRIEn];
	int dfs(int x)
	{
		int sz=1,mx=0;
		son[x]=0;
		for(int t=0;t<go[x].size();t++)
		{
			int u=go[x][t].SS;
			lv[u]=lv[x]+1;
			int szu=dfs(u);
			sz+=szu;
			if(szu>mx)son[x]=u,mx=szu;
		}
		return sz;
	}
	void dfs2(int x,int tp)
	{
		top[x]=tp;
		if(son[x])dfs2(son[x],tp);
		for(int t=0;t<go[x].size();t++)
		{
			int u=go[x][t].SS;
			if(u==son[x])continue;
			dfs2(u,u);
		}
	}
	void construct_HLD()
	{
		lv[1]=0;
		dfs(1);
		dfs2(1,1);
	}
	void HLDflip(int x)
	{
		int g=top[x];
		if(st[g].find(lv[x])==st[g].end())st[g].insert(lv[x]);
		else st[g].erase(lv[x]);
	}
	int HLDquery(int x)
	{
		while(x)
		{
			if(st[top[x]].size()>0&&*st[top[x]].begin()<=lv[x])return *(--st[top[x]].lower_bound(lv[x]+1));
			x=fa[top[x]];
		}
		return 0;
	}
	
	int q[maxTRIEn],qn;
	void construct()
	{
		construct_HLD();
		for(int i=1;i<=tot;i++)hs_arr[i]=MP(hs[i],i);
		sort(hs_arr+1,hs_arr+tot+1);
		qn=0;q[qn++]=1;
		for(int i=0;i<qn;i++)
		{
			int x=q[i];
			for(int j=0;j<go[x].size();j++)
			{
				q[qn++]=go[x][j].SS;
			}
		}
		fail[1]=1;
		for(int i=1;i<qn;i++)
		{
			int x=q[i];
			int &p=fail[x];
			if(fa[x]==1)p=1;
			else
			{
				p=fail[fa[x]];
				while(p!=1&&gomp.find(p<<8|pc[x])==-1)p=fail[p];
				if(gomp.find(p<<8|pc[x])!=-1)p=gomp.find(p<<8|pc[x]);
			}
			con[fail[x]].PB(x);
		}
		fdfs(1);
	}
	int qans[maxTRIEn],qans2[maxTRIEn];
	vector<pair<int,int> > qr[maxTRIEn],qr2[maxTRIEn];
	void dfs_solve_p1(int x)
	{
		bit_add(fdfn[x],1);
		for(int i=0;i<qr[x].size();i++)
		{
			int pos=qr[x][i].FF;
			qans[qr[x][i].SS]+=bit_query(fdfnr[pos])-bit_query(fdfn[pos]-1);
		}
		for(int i=0;i<go[x].size();i++)dfs_solve_p1(go[x][i].SS);
		bit_add(fdfn[x],-1);
	}
	void dfs_solve_p2(int x,ll hs=0,ll hs_bs=1)
	{
		int p=lower_bound(hs_arr+1,hs_arr+tot+1,MP(hs,0))-hs_arr;
		if(hs_arr[p].FF==hs)HLDflip(hs_arr[p].SS);
		for(int i=0;i<qr2[x].size();i++)
		{
			qans2[qr2[x][i].SS]=HLDquery(qr2[x][i].FF);
		}
		for(int i=0;i<go[x].size();i++)dfs_solve_p2(go[x][i].SS,(hs+hs_bs*(go[x][i].FF+1))%hs_mod,hs_bs*hs_B%hs_mod);
		if(hs_arr[p].FF==hs)HLDflip(hs_arr[p].SS);
	}
	void add_query(int ui,int vi,int si,int ti,int id)
	{
		qr[ui].PB(MP(ti,id));
		qr[vi].PB(MP(si,id));
		qr2[si].PB(MP(ui,id*2));
		qr2[ti].PB(MP(vi,id*2+1));
	}
	pair<int,pair<int,int> > get_query(int id)
	{
		return MP(qans[id],MP(qans2[id*2],qans2[id*2+1]));
	}
	void solve()
	{
		memset(qans,0,sizeof(qans));
		dfs_solve_p1(1);
		dfs_solve_p2(1);
	}
};
int n,m,q;
vector<pair<int,char> > con[maxn];
vector<pair<int,int> > qr[maxn];
int qu[maxn],qv[maxn],qx[maxn],uid[maxn],vid[maxn];
vector<int> sid[maxn];
int cur_rt,cur_lv;
int dlv[maxn],sz[maxn],arr[maxn],an,gr[maxn],id[maxn];
void pdfs(int x,int pre=-1)
{
	sz[x]=1;arr[an++]=x;dlv[x]=cur_lv+1;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i].FF;
		if(u==pre||dlv[u]<cur_lv)continue;
		pdfs(u,x);
		sz[x]+=sz[u];
	}
}
int findrt(int x)
{
	an=0;
	pdfs(x);
	int ret=x;
	for(int i=0;i<an;i++)if(sz[arr[i]]*2>=sz[x]&&sz[arr[i]]<sz[ret])ret=arr[i];
	return ret;
}
void dfs(int x,int pre,int g)
{
	gr[x]=g;
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i].FF;
		if(u==pre||dlv[u]<cur_lv)continue;
		id[u]=AC::insert(id[x],con[x][i].SS-'a');
		dfs(u,x,pre==-1?u:g);
	}
}
void solve(int X,int lv)
{
	cur_lv=lv;
	int rt=findrt(X);
	cur_rt=rt;
	dlv[rt]=lv;
	id[rt]=1;
	dfs(rt,-1,rt);
	static bool vis[maxn];
	for(int i=0;i<an;i++)vis[arr[i]]=1;
	for(int i=0;i<an;i++)
	{
		int x=arr[i];
		for(int j=0;j<qr[x].size();j++)
		{
			int y=qr[x][j].FF;
			if(vis[y]&&gr[y]!=gr[x])
			{
				uid[qr[x][j].SS]=id[x];
				vid[qr[x][j].SS]=id[y];
			}
		}
	}
	for(int i=0;i<an;i++)vis[arr[i]]=0;
	for(int i=0;i<con[rt].size();i++)
	{
		int u=con[rt][i].FF;
		if(dlv[u]<lv)continue;
		solve(u,lv+1);
	}
}
char s[maxn];
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<n;i++)
	{
		int x,y;
		char c;
		scanf("%d %d %c",&x,&y,&c);
		con[x].PB(MP(y,c));
		con[y].PB(MP(x,c));
	}
	for(int i=1;i<=m;i++)
	{
		scanf("%s",s+1);
		int l=strlen(s+1);
		int p;
		p=1;sid[i].PB(1);
		for(int j=1;j<=l;j++)p=AC::insert(p,s[j]-'a'),sid[i].PB(p);
		KMP::construct(s,l,i);
		reverse(s+1,s+l+1);
		p=1;sid[i+m].PB(1);
		for(int j=1;j<=l;j++)p=AC::insert(p,s[j]-'a'),sid[i+m].PB(p);
		KMP::construct(s,l,i+m);
		reverse(s+1,s+l+1);
	}
	for(int i=1;i<=q;i++)
	{
		int u,v,x;
		scanf("%d%d%d",&u,&v,&x);
		qr[u].PB(MP(v,i));
		qu[i]=u;qv[i]=v;qx[i]=x;
	}
	solve(1,0);
	AC::construct();
	for(int i=1;i<=q;i++)
	{
		AC::add_query(uid[i],vid[i],sid[qx[i]].back(),sid[qx[i]+m].back(),i);
	}
	AC::solve();
	for(int i=1;i<=q;i++)
	{
		pair<int,pair<int,int> > pp=AC::get_query(i);
	}
	for(int i=1;i<=q;i++)
	{
		pair<int,pair<int,int> > pp=AC::get_query(i);
		int ans=pp.FF;
		ans+=KMP::query(qx[i],pp.SS.FF,qx[i]+m,pp.SS.SS,sid[qx[i]].size()-1);
		printf("%d\n",ans);
	}
	return 0;
}