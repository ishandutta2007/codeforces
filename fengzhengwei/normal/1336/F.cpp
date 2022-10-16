#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
//#define getchar gc
ll read()
{
	char c;
	ll w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	ll ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
void pc(char c,int op)
{
	static char buf[1<<16],*s=buf,*t=buf+(1<<16);
	(op||((*s++=c)&&s==t))&&(fwrite(buf,1,s-buf,stdout),s=buf);
}
void wt(int x)
{
	if(x>9)wt(x/10);
	pc('0'+x%10,0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
const int xx=2e5+5;
int lg[xx];
int lb(int x){return x&-x;}
void pre()
{
	lg[0]=-1;
	for(int i=1;i<xx;i++)lg[i]=lg[i-1]+(i==lb(i));
}
namespace Sz//case 
{
	int sum[xx];
	void add(int x,int y){assert(x);for(;x<xx;x+=lb(x))sum[x]+=y;}
	int ask(int x){int ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}
	int ask(int x,int y){return ask(y)-ask(x-1);}
}
struct T// 
{
	struct nod{int next,to;}e[xx<<1];
	int cnt,h[xx];
	vector<int>Cl;
	void add(int x,int y){/*cerr<<x<<" "<<y<<"!!!\n",*/Cl.push_back(x),Cl.push_back(y),cnt++,e[cnt]={h[x],y},h[x]=cnt;}
	void cls(){for(auto it:Cl)h[it]=0;Cl.clear();cnt=0;}
	void dfs(int x,int y);
	int lca(int x,int y);//  
	int jump(int x,int y);//xy 
}t1,t2;//t2 
int f[xx][21],dfx[xx],dep[xx],size[xx],id[xx],totone,n,m,K;//K 
void T::dfs(int x,int y)
{
	dfx[x]=++totone,id[totone]=x,f[x][0]=y,dep[x]=dep[y]+1,size[x]=1;
	for(int i=1;i<=20;i++)f[x][i]=f[f[x][i-1]][i-1];
	for(int i=h[x];i;i=e[i].next)
		if(e[i].to!=y)dfs(e[i].to,x),size[x]+=size[e[i].to];
}
int T::lca(int x,int y)
{
	if(!x||!y)return x+y;
	if(dep[x]<dep[y])swap(x,y);
	while(dep[x]!=dep[y])x=f[x][lg[dep[x]-dep[y]]];
	if(x==y)return x;
	for(int i=lg[dep[x]];i>=0;i--)(f[x][i]^f[y][i])?(x=f[x][i],y=f[y][i]):0;
	return f[x][0];
}
int T::jump(int x,int y)
{
	if(!y)return x;
	for(int i=lg[y];i>=0;i--)if(y>>i&1)x=f[x][i];
	return x;
}
struct nod
{
	int x,y;
	bool operator<(const nod&w)const{return dfx[x]<dfx[w.x];}
};
struct seg
{
	struct pt{int l,r,sum;}e[xx*64];
	int cst;
	void cls(){memset(e,0,sizeof(e[0])*(cst+1));cst=0;}
	void ins1(int &k,int l,int r,int x)// 
	{
		++cst;e[cst]=e[k];k=cst;e[k].sum++;
		if(l==r)return;
		int mid=l+r>>1;
		if(x<=mid)ins1(e[k].l,l,mid,x);
		else ins1(e[k].r,mid+1,r,x);
	}
	void ins2(int &k,int l,int r,int x)//  
	{
		if(!k)k=++cst;e[k].sum++;
		if(l==r)return;
		int mid=l+r>>1;
		if(x<=mid)ins2(e[k].l,l,mid,x);
		else ins2(e[k].r,mid+1,r,x);
	}
	void upd(int k){e[k].sum=e[e[k].l].sum+e[e[k].r].sum;}
	int merge(int x,int y)// 
	{
		if(!x||!y)return x+y;
		e[x].l=merge(e[x].l,e[y].l);
		e[x].r=merge(e[x].r,e[y].r);
		e[x].sum+=e[y].sum;
		return x;
		// 
	}
	int ask(int k,int l,int r,int x,int y)
	{
		if(x>y||!k)return 0;
		if(x<=l&&r<=y)return e[k].sum;
		int mid=l+r>>1,res=0;
		if(x<=mid)res+=ask(e[k].l,l,mid,x,y);
		if(mid<y)res+=ask(e[k].r,mid+1,r,x,y);
		return res;
	}
	int A(int k,int x,int y){return ask(k,1,n,x,y);}
	int A(int rt1,int rt2,int x,int y){return ask(rt2,1,n,x,y)-ask(rt1,1,n,x,y);}//rootroot-1 
};
ll ans;
int dis(int x,int y){return abs(dep[x]-dep[y]);}// 
namespace C1
{
	nod q[xx];
	int root[xx];
	vector<int>v[xx];
	seg S;
	void solve()
	{
		sort(q+1,q+m+1);
		// 
		for(int i=1;i<=m;i++)
		{
			v[q[i].x].push_back(q[i].y);
			v[q[i].y].push_back(q[i].x);
		}
		for(int i=1;i<=n;i++)
		{
			root[i]=root[i-1];
			for(auto it:v[id[i]])S.ins1(root[i],1,n,dfx[it]);
		}
		for(int i=1;i<=m;i++)
		{
			int x=q[i].x,y=q[i].y,L=t1.lca(x,y);
			if(dis(x,L)>=K)
			{
				int up=t1.jump(x,dis(x,L)-K);
				ans+=S.A(root[dfx[up]-1],root[dfx[up]+size[up]-1],dfx[L]+size[L],n);
//			cout<<i<<" "<<ans<<" "<<up<<" "<<L<<"!!\n";
				ans+=S.A(root[dfx[up]-1],root[dfx[up]+size[up]-1],1,dfx[L]-1);
//			cout<<i<<" "<<ans<<" "<<up<<"!!\n";
			}
			if(dis(y,L)>=K)
			{
				int up=t1.jump(y,dis(y,L)-K);
				ans+=S.A(root[dfx[up]-1],root[dfx[up]+size[up]-1],dfx[L]+size[L],n);
				ans+=S.A(root[dfx[up]-1],root[dfx[up]+size[up]-1],1,dfx[L]-1);
//			cout<<i<<" "<<ans<<" "<<up<<"!!\n";
			}
		}
	}
}
vector<nod>V[xx];//lca=L 
int stk[xx],top;
namespace C2
{
	vector<nod>to[xx];//s= 
	vector<nod>nw[xx];
	seg S;
	int root[xx];
	void merge(int x,int y)//x,xslca 
	{
		if(nw[x].size()<nw[y].size())swap(nw[x],nw[y]),swap(root[x],root[y]);
//		cerr<<x<<" "<<nw[x].size()<<" "<<nw[y].size()<<"!!\n";
		for(auto it:nw[y])
		{
//		cout<<x<<" "<<y<<" "<<it.x<<" "<<it.y<<" "<<ans<<"!!\n";
			int L=t1.lca(it.x,it.y);
			//RlcaLcaLLCA 
//			assert(L==R);//x 
			nw[x].push_back(it);
			if(dep[x]+dep[it.y]-dep[L]-dep[L]<K)continue;
			int to=L;
			if(dis(L,x)<K)to=t1.jump(it.y,dis(L,it.y)-(K-dis(L,x)));
			ans+=S.A(root[x],dfx[to],dfx[to]+size[to]-1);
//			cout<<it.x<<" asdasd "<<it.y<<" "<<x<<" "<<y<<" "<<to<<" "<<root[x]<<" "<<S.A(root[x],dfx[3],dfx[3])<<"!!\n";
//			cout<<L<<" "<<x<<" "<<K<<" "<<to<<" "<<root[y]<<" "<<ans<<" "<<dfx[to]<<" "<<dfx[to]+size[to]-1<<" "<<dfx[4]<<" "<<S.A(root[y],dfx[to],dfx[to]+size[to]-1)<<" "<<S.A(root[y],1,n)<<"!!\n";
		}
		root[x]=S.merge(root[x],root[y]);
//		puts("SSS");
	}
	void dfs(int x,int y)
	{
		root[x]=0;
		for(auto it:to[x])
		{
			root[0]=0;
			nw[0].clear(),nw[0].push_back(it);
			S.ins2(root[0],1,n,dfx[it.y]);
			merge(x,0);
//			cerr<<it.y<<" "<<root[x]<<" qq "<<S.A(root[x],dfx[3],dfx[3])<<"!!\n";
//		cout<<x<<" "<<y<<" "<<it.x<<" qq "<<it.y<<" "<<ans<<"!!\n";
		}
		for(int i=t2.h[x];i;i=t2.e[i].next)
		{
			if(t2.e[i].to==y)continue;
			dfs(t2.e[i].to,x),merge(x,t2.e[i].to);
		}
//		cout<<x<<" "<<y<<"!!ASD\n";
	}
	void solve(int rt)
	{
		S.cls();
//		R=rt;//1 
		to[0].clear();
		dfs(rt,1-(rt==1));//rt=11 
//		puts("DFgdas");
		
	}
}
namespace C3
{
	void solve(vector<nod>&v,int rt)
	{
		for(auto it:v)
		{
			if(dis(it.x,rt)>=K)
			{
				int to=t1.jump(it.x,dis(it.x,rt)-K);
//			cout<<rt<<" "<<it.x<<" "<<dis(it.x,rt)<<" "<<to<<"\n";
				ans+=Sz::ask(dfx[to],dfx[to]+size[to]-1);
			}
			Sz::add(dfx[it.y],1);
		}
		for(auto it:v)Sz::add(dfx[it.y],-1);
	}
}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("a.out","w",stdout);
	pre();
	n=read(),m=read(),K=read();
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		t1.add(a,b),t1.add(b,a);
	}
	t1.dfs(1,0);
//	for(int i=1;i<=n;i++)cout<<dfx[i]<<"!\n";
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read();if(dfx[a]>dfx[b])swap(a,b);
		C1::q[i].x=a,C1::q[i].y=b;
		V[t1.lca(a,b)].push_back({a,b});
	}
	C1::solve();
//	cout<<ans<<"\n";
//	exit(0);
	for(int i=1;i<=n;i++)sort(V[i].begin(),V[i].end());
	for(int lc=1;lc<=n;lc++)
	{
		t2.cls();
		stk[top=1]=1;int rt=0;
		vector<int>er;
		er.push_back(1);
		for(auto it:V[lc])
		{
			int L=t1.lca(stk[top],it.x);
			rt=t1.lca(rt,it.x);
			C2::to[it.x].push_back(it);
			er.push_back(it.x),er.push_back(L);
//			cerr<<it.x<<"$#%%^\n";
			if(it.x==stk[top])continue;
			while(dep[stk[top]]>dep[L])
			{
				if(dep[stk[top-1]]<dep[L])
				{
					t2.add(L,stk[top]),t2.add(stk[top],L);
					stk[top]=L;
					break;
				}
				t2.add(stk[top-1],stk[top]),t2.add(stk[top],stk[top-1]);
				top--;
			}
			stk[++top]=it.x;
		}
//		puts("ED");
//		cout<<top<<" "<<stk[top]<<" "<<stk[top-1]<<"!!\n";
		while(top!=1)
			t2.add(stk[top-1],stk[top]),t2.add(stk[top],stk[top-1]),top--;
		C2::solve(rt);
//		cout<<lc<<" qq "<<ans<<"!!\n";
//		exit(0);
		C3::solve(V[lc],lc);//LCA 
//		cout<<lc<<" qq "<<ans<<"!!\n";
//		for(int i=1;i<=n;i++)C2::to[i].clear();
		for(auto it:er)C2::to[it].clear(),C2::nw[it].clear();
	}
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}