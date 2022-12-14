#include<iostream>
#include<cstring>
#include<cstdio>
#include<vector>
#define MN 100000
#define MM 50
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
char st[MN+5];long long sum[MN+5],Ans[MN+5];
int n,m,cnt=0,lt[MN+5],rt[MN+5];
struct ques{int l,r,id;};
vector<ques> v[MN+5],V[MN+5];

namespace TRIE
{
	#define MX 100000	
	int cnt,c[MX+5][26],val[MX+5];
	void init(int len)
	{
		cnt=1;++len;
		for(int i=1;i<=len;++i) val[i]=0,memset(c[i],0,sizeof(c[i])); 	
	}
	void ins(char*s,int l,int r)
	{	
		int x=1;
		for(int i=l;i<=r;++i)
		{
			if(!c[x][s[i]-'a']) c[x][s[i]-'a']=++cnt;
			x=c[x][s[i]-'a'];	
		}
		++val[x];
	}
	long long Calc(char*s,int l,int r)
	{
		long long res=0;int x=1;	
		for(int i=l;i<=r;++i) 
			if(!c[x][s[i]-'a']) return res;
			else res+=val[x=c[x][s[i]-'a']];
		return res;
	}
	#undef MX
}

namespace SAM
{
	#define MX 200000
	int n,cnt,last,c[MX+5][26],step[MX+5],fail[MX+5],v[MX+5],rk[MX+5];
	long long val[MX+5],sum[MX+5];
	void init(int len)
	{
		cnt=last=1;n=len;
		for(int i=1;i<=n<<1;++i)
			memset(c[i],0,sizeof(c[i])),step[i]=fail[i]=v[i]=val[i]=0;
	}
	void insert(int x)
	{
		int p=last,np=++cnt;step[np]=step[p]+1;val[np]=1;
		for(;p&&!c[p][x];p=fail[p]) c[p][x]=np;
		if(!p) fail[np]=1;
		else 
		{
			int q=c[p][x];
			if(step[q]==step[p]+1) fail[np]=q;
			else 
			{
				int nq=++cnt;step[nq]=step[p]+1;
				memcpy(c[nq],c[q],sizeof(c[q]));
				fail[nq]=fail[q];fail[np]=fail[q]=nq;
				for(;c[p][x]==q;p=fail[p]) c[p][x]=nq;
			}	
		}
		last=np;
	}
	void Build()
	{
		for(int i=1;i<=cnt;++i) ++v[step[i]];
		for(int i=1;i<=n;++i) v[i]+=v[i-1];
		for(int i=1;i<=cnt;++i) rk[v[step[i]]--]=i;
		for(int i=cnt;i;--i) val[fail[rk[i]]]+=val[rk[i]];val[1]=0;
		for(int i=cnt;i;sum[rk[i]]+=val[rk[i]],--i) for(int j=0;j<26;++j) if(c[rk[i]][j]) sum[rk[i]]+=sum[c[rk[i]][j]]; 
	}
	int Calc(char*s,int l,int r)
	{
		int x=1;
		for(int i=l;i<=r;++i)
			if(!c[x][s[i]-'a']) return 0;
			else x=c[x][s[i]-'a'];	
		return val[x];
	}
	#undef MX
}

int main()
{	
	n=read();m=read();
	for(int i=1,j=1;i<=n;++i) 
	{
		lt[i]=j;scanf("%s",st+j);
		int len=strlen(st+j);rt[i]=j+len-1;j+=len;
	}
	for(int i=1;i<=m;++i)
	{
		int l=read(),r=read(),K=read();	
		if(rt[K]-lt[K]+1>MM) V[K].push_back((ques){l,r,i});	
		else v[l-1].push_back((ques){K,-1,i}),
			 v[r].push_back((ques){K,1,i});	
	}
	for(int i=1;i<=n;++i) if(V[i].size())
	{
		int len=rt[i]-lt[i]+1;SAM::init(len);
		for(int j=lt[i];j<=rt[i];++j) SAM::insert(st[j]-'a');
		SAM::Build();
		for(int j=1;j<=n;++j) sum[j]=sum[j-1]+SAM::Calc(st,lt[j],rt[j]);
		for(int j=0;j<V[i].size();++j) Ans[V[i][j].id]=sum[V[i][j].r]-sum[V[i][j].l-1];
	}
	TRIE::init(n);
	for(int i=1;i<=n;++i)
	{
		TRIE::ins(st,lt[i],rt[i]);
		for(int j=0;j<v[i].size();++j)
		{ 
			long long res=0;
			for(int ii=lt[v[i][j].l];ii<=rt[v[i][j].l];++ii) res+=TRIE::Calc(st,ii,rt[v[i][j].l]);
			Ans[v[i][j].id]+=v[i][j].r*res; 
		}
	}
	for(int i=1;i<=m;++i) printf("%lld\n",Ans[i]);
	return 0;
}