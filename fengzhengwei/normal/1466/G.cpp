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
void wts(int x,char c)
{
	if(x<0)pc('-',0),x=-x;
	wt(x),pc(c,0);
}
/*
 
*/
const int xx=1e6+5,yy=100005,mod=1e9+7,base=2011111;//da 
namespace ac 
{
	struct nod{int to[26],fail;}e[xx];//fail 
	int cst,in[xx],q[xx],v[xx],ans[xx],id;
	int g(int &x){return !x?x=++cst:x;}
	int ins(const char *s,int p)
	{
		int last=1;
		for(int i=0;i<p;i++)last=g(e[last].to[s[i]-'a']);
		return last;
	}
	void cl(){memset(e,0,sizeof(e[0])*(cst+1));cst=1;id=0;}
	void build()
	{
		int l=1,r=0;
		e[1].fail=1;
		for(int i=0;i<26;i++)if(!e[1].to[i])e[1].to[i]=1;else e[e[1].to[i]].fail=1,q[++r]=e[1].to[i];
		while(l<=r)
		{
			int x=q[l++];
			in[++id]=x;
			for(int i=0;i<26;i++)
			{
				if(!e[x].to[i])e[x].to[i]=e[e[x].fail].to[i];
				else e[e[x].to[i]].fail=e[e[x].fail].to[i],q[++r]=e[x].to[i];
			}
		}
	}
	void run(const char *s,int p)
	{
		int last=1;
		for(int i=0;i<p;i++)v[last=e[last].to[s[i]-'a']]++;
		for(int i=id;i>=1;i--)//cst1in0 
		{
			int x=in[i];
			ans[x]+=v[x];
			ans[e[x].fail]+=ans[x];
		}
	}
	void clans(){memset(ans,0,sizeof(ans[0])*(cst+1)),memset(v,0,sizeof(v[0])*(cst+1));}
}
char s0[105],t[100005];
char lin[xx];
struct qu
{
	string a;
	int id,to;
	bool operator<(const qu&w)const{return to<w.to;}
}q[yy];
vector<pair<string,int> >v[50];// 
int I[yy],ans[yy],V[yy],g[yy][26],ctv,ctg[26];
char T[xx<<1];
ll pw[xx<<1],sum[xx<<1];
ll get(const char *s,int p)
{
	ll res=0;
	for(int i=0;i<p;i++)res+=(s[i]-'a')*pw[i]%mod;
//	cerr<<res<<" "<<p<<"qq \n";
	return res%mod;
}
signed main(){
//	freopen("a.in","r",stdin);
	int n=read(),m=read();
	scanf("%s",s0);
	scanf("%s",t);
	int id=0,len=strlen(s0);
	while(len<1e6)len*=2,len++,id++;
	int tt=0;
	for(int i=1;i<=m;i++)
	{
		int to=read();
		scanf("%s",lin);
//		if(n==50001&&m==19760)
//		{
//			if(i==5915)
//			{
//				cout<<to<<' '<<id<<"\n"<<lin<<"\n";
//				exit(0);
//			}
//		}
		if(to<=id)
			v[to].push_back(make_pair(lin,i));
		else q[++tt]=(qu){lin,i,to};
	}
	string now=s0;
	for(int i=0;i<=id;i++)
	{
		ac::cl();
		for(auto it:v[i])
			I[it.second]=ac::ins(it.first.c_str(),it.first.size());
		ac::build();
		ac::run(now.c_str(),now.size());
		for(auto it:v[i])
			ans[it.second]=ac::ans[I[it.second]];
		ac::clans();
		if(i!=id)now=now+t[i]+now;
	}
	// 
	ac::cl();
	for(int i=1;i<=tt;i++)I[q[i].id]=ac::ins(q[i].a.c_str(),q[i].a.size());
	ac::build();
	pw[0]=1;
	for(int i=1;i<(xx<<1);i++)pw[i]=pw[i-1]*base%mod;
//	assert(now.size()>1e6);
	int sz=now.size();
	for(int i=0;i<sz;i++)T[i]=now[i];
	for(int i=0;i<sz;i++)sum[i]=(sum[i-1]+pw[i]*(T[i]-'a'))%mod;
//	assert(sz<=2000000);
	ac::run(T,sz);
	for(int i=1;i<=tt;i++)V[q[i].id]=ac::ans[I[q[i].id]];// 
	ac::clans();
	for(int j=0;j<26;j++)
	{
		for(int k=1;k<=tt;k++)
		{
			int len=q[k].a.size();
			ll now=get(q[k].a.c_str(),len);
//	cerr<<now<<"\n";
//			cerr<<
			for(int i=len-1;i>=0;i--)
			{
				if(len-i-1)
				{
					if(now*pw[sz-i]%mod==(sum[sz-1]-sum[sz-i-1]+pw[sz]*j+pw[sz+1]*sum[len-i-1-1]+mod)%mod)
					{
						
						g[q[k].id][j]++;
//						,cerr<<sz<<" "<<pw[sz+1]<<" "<<sum[len-i-1]<<"Q\n";
					}
				}
				else 
				{
					if(now*pw[sz-i]%mod==(sum[sz-1]-sum[sz-i-1]+pw[sz]*j+mod)%mod)
					{
						g[q[k].id][j]++;
					}
				}
			}
		}
//		for(int i=1;i<=tt;i++)g[q[i].id][j]=ac::ans[I[q[i].id]]-2*V[q[i].id];
	}
	sort(q+1,q+tt+1);
	ctv=1;
	int l=id;
	for(int i=1;i<=tt;i++)
	{
		while(l!=q[i].to)
		{
			ctv*=2,ctv%=mod;
			for(int j=0;j<26;j++)ctg[j]*=2,ctg[j]%=mod;//
			ctg[t[l++]-'a']++;
		}
		ll res=0;
		res+=1ll*ctv*V[q[i].id]%mod;
		for(int j=0;j<26;j++)res+=1ll*ctg[j]*g[q[i].id][j]%mod;
		ans[q[i].id]=res%mod;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<"\n";
	pc('1',1);
	return 0;
}