#include<bits/stdc++.h>
#define ll long long 
#define dd double
using namespace std;
char gc(){static char buf[1<<20],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
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
	pc(x%10+'0',0);
}
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(op,0);
}
const int bs[5]={1,2,8,64,1024};
struct xxj
{
	int s[5];//01234
	xxj(){memset(s,0,sizeof(s));}
	bool checkone(int x)//10 
	{
		for(int i=4;i>=0;i--)if((x>>i&1)&&s[i])x^=s[i];
		return x!=0;
	}
	int count()const{int ans=0;for(int i=0;i<5;i++)ans+=(s[i]!=0);return ans;}
	bool checkmany(const xxj&x,xxj&lin){return (this->count()+x.count())==(lin=(*this+x)).count();}//10 
	bool ins(int x)//1 
	{
		if(!x)return 0;
//		for(int i=4;i>=0;i--)cout<<s[i]<<" ";
//		puts("");
		for(int i=4;i>=0;i--)if((x>>i&1)&&!s[i])return s[i]=x,1;else if(x>>i&1)x^=s[i];
//		cout<<x<<"!!\n";
		return 0;
	}
	xxj operator+(const int&w)const
	{
		xxj s=*this;s.ins(w);
		return s;
	}
	xxj operator+(const xxj&w)const
	{
		xxj s=*this;
		for(int i=0;i<5;i++)s.ins(w.s[i]);
		return s;
	}
	void cl()
	{
		for(int i=0;i<=4;i++)
			for(int j=0;j<i;j++)if((s[i]>>j&1)&&s[j])s[i]^=s[j];
	}
	int G()const
	{
		int ans=0;
		for(int i=0;i<5;i++)ans+=s[i]*bs[i];
		return ans;
	}
};
//1ban 
//1024 
const int mod=1e9+7;
struct hash
{
	// 
	struct nod{xxj key;int val;}e[50005];// 
	int is[50005];
	vector<int>Cls;
	void cls(){for(auto it:Cls)e[it].val=0,is[it]=0;Cls.clear();}
	int find(const xxj&w)const{int A=w.G();if(is[A])return A;return 0;}
	void nw(const xxj&w){int A=w.G();(!is[A]?e[A].key=w,Cls.push_back(A),is[A]=1:0);}
	int& operator[](const xxj&w){int A=find(w);return !A?nw(w),e[find(w)].val:e[A].val;}
}d[2];
// 
const int xx=1e5+5;
struct nod{int next,to,v;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y,int z){cnt++;e[cnt]={h[x],y,z};h[x]=cnt;}
int n,m,cr[xx],sum[xx],is;
struct OPER
{
	xxj to;
	int x,y,v;// 
};
vector<OPER>v;
xxj now;
int vis[xx],V[xx],dfn[xx],tx,ty,tv,Cst;
void dfs(int x,int y)
{
	vis[x]=1,dfn[x]=++Cst;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y||e[i].to==1)continue;
		if(cr[x]&&cr[e[i].to])
		{
			if(tx==x)ty=e[i].to;
			else if(ty==x)tx=e[i].to;
			tv=e[i].v;// 
		}
		if(!vis[e[i].to])sum[e[i].to]=sum[x]^e[i].v,dfs(e[i].to,x);
		else if(dfn[e[i].to]<dfn[x])
//		{
			
			is&=now.ins(sum[x]^sum[e[i].to]^e[i].v);
//			cerr<<x<<" "<<e[i].to<<" "<<(sum[x]^sum[e[i].to])<<" "<<is<<"!!\n";
//		}
	}
}
void ad(int &x,int y){(x+=y)>=mod?x-=mod:0;}
int main(){
	n=read(),m=read();
	for(int i=1;i<=m;i++)
	{
		int a=read(),b=read(),c=read();
		add(a,b,c),add(b,a,c);
	}
	for(int i=h[1];i;i=e[i].next)cr[e[i].to]=1,V[e[i].to]=e[i].v;
	for(int i=2;i<=n;i++)
	{
		if(cr[i]&&!vis[i])
		{
			//=0 
			is=1,now=xxj();
			tx=i,ty=0,tv=0,dfs(i,0);
//			cout<<is<<"!!\n";
			if(is)v.push_back({now,tx,ty,tv});
		}
	}
//	exit(0);
	int ni=0,ti=1;// 
	d[ni][xxj()]=1;
	for(auto it:v)
	{
		for(auto i:d[ni].Cls)
		{
			auto now=d[ni].e[i];
			ad(d[ti][now.key],now.val);// 
			xxj To;
			int ck=now.key.checkmany(it.to,To);
			To.cl();
			if(ck)
			{
				if(!it.y)
					ad(d[ti][To],now.val);// 
				else 
				{
					ad(d[ti][To],(now.val*2)%mod);// 
					if(To.ins(V[it.x]^V[it.y]^it.v))
					To.cl(),ad(d[ti][To],now.val);// 
				}
			}
		}
		d[ni].cls();
		swap(ni,ti);
	}
	int ans=0;
	for(auto i:d[ni].Cls)
		ad(ans,d[ni].e[i].val);
	cout<<ans<<"\n";
	pc('1',1);
	return 0;
}