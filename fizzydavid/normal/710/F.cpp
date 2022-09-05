//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back 
#define MP make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
//My own input/output stream
#define geti(x) x=getnum()
#define getii(x,y) geti(x),geti(y)
#define getiii(x,y,z) getii(x,y),geti(z)
#define puti(x) putnum(x),putsp()
#define putii(x,y) puti(x),putnum(y),putsp()
#define putiii(x,y,z) putii(x,y),putnum(z),putsp()
#define putsi(x) putnum(x),putendl()
#define putsii(x,y) puti(x),putnum(y),putendl()
#define putsiii(x,y,z) putii(x,y),putnum(z),putendl()
inline ll getnum()
{
	register ll r=0;register bool ng=0;register char c;c=getchar();
	while(c!='-'&&(c<'0'||c>'9'))c=getchar();
	if(c=='-')ng=1,c=getchar();
	while(c!=' '&&c!='\n')r=r*10+c-'0',c=getchar();
	if(ng)r=-r;return r;
}
template <class T> inline void putnum(T x)
{
	if(x<0)putchar('-'),x=-x;
	register short a[20]={},sz=0;
	while(x>0)a[sz++]=x%10,x/=10;
	if(sz==0)putchar('0');
	for(int i=sz-1;i>=0;i--)putchar('0'+a[i]);
}
inline void putsp(){putchar(' ');}
inline void putendl(){putchar('\n');}
inline char mygetchar(){register char c=getchar();while(c==' '||c=='\n')c=getchar();return c;}
const char alphabase='a';
const int maxn=700000;
struct suffix_automaton
{
	map<int,int> go[maxn];
	int par[maxn],len[maxn];
	int tot,last;
	vector<int>con[maxn];
	suffix_automaton()
	{
		init();
	}
	void init()
	{
		memset(par,0,sizeof(par));
		memset(len,0,sizeof(len));
		tot=1;
		last=1;
	}
	void watch()
	{
		cout<<"tot="<<tot<<" last="<<last<<endl;
		for(int i=1;i<=tot;i++)
		{
			cout<<go[i][0]<<","<<go[i][1]<<","<<go[i][2]<<" "<<par[i]<<" "<<len[i]<<endl;
		}
	}
	void add(char cc)
	{
		int c=cc-alphabase;
		int p=last;
		if(go[p].find(c)!=go[p].end())
		{
			int q=go[p][c];
			if(len[q]==len[p]+1)
			{
				last=q;
				return;
			}
			int nq=++tot;
			len[nq]=len[p]+1;
			par[nq]=par[q];
			par[q]=nq;
			go[nq]=go[q];
			for(;p&&go[p][c]==q;p=par[p])go[p][c]=nq;
			last=nq;
			return;
		}
		int np=++tot;
		last=np;
		len[np]=len[p]+1;
		for(;p&&!go[p][c];p=par[p])go[p][c]=np;
		if(!p)
		{
			par[np]=1;
			return;
		}
		int q=go[p][c];
		if(len[q]==len[p]+1)
		{
			par[np]=q;
			return;
		}
		int nq=++tot;
		len[nq]=len[p]+1;
		par[nq]=par[q];
		par[q]=nq;
		par[np]=nq;
		go[nq]=go[q];
		for(;p&&go[p][c]==q;p=par[p])go[p][c]=nq;
		if(tot>600000)cout<<tot<<endl;
	}
/*	void debug(int p,string s)
	{
		cout<<s<<endl;
		for(int i=0;i<26;i++)
		{
			if(!go[p][i])continue;
			debug(go[p][i],s+char('a'+i));
		}
	}*/
	int insert(char s[],int n)
	{
		last=1;
		for(int i=0;i<n;i++)
		{
			add(s[i]);
//			watch();
//			debug(1,"");
		}
//		watch();
		return last;
	}
	int getpos(char s[],int n)
	{
		int p=1;
		for(int i=0;i<n;i++)
		{
			if(!go[p][s[i]-alphabase])return 0;
			else p=go[p][s[i]-alphabase];
		}
		return p;
	}
	void build_tree()
	{
		for(int i=1;i<=tot;i++)con[i].clear();
		for(int i=2;i<=tot;i++)con[par[i]].PB(i);
	}
	int dfntot,dl[maxn],dr[maxn];
	void dfs(int p)
	{
		dl[p]=++dfntot;
		for(int i=0;i<con[p].size();i++)
			dfs(con[p][i]);
		dr[p]=dfntot;
	}
	void dfs()
	{
		dfntot=0;
		dfs(1);
	}

}sa;
int cnt[maxn];
int pre[maxn];
char s[300111];
int n,len;
const int B=1732;
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		int cmd;
		scanf("%d %s",&cmd,s);
		len=strlen(s);
		if(cmd==4)
		{
			int alpha;
			cin>>len>>alpha;
			for(int i=0;i<len;i++)s[i]=rand()%alpha+'a';
		}
		if(cmd==1)cnt[sa.insert(s,len)]++;
		else if(cmd==2)cnt[sa.getpos(s,len)]--;
		else
		{
			if(sa.tot==1)
			{
				puts("0");
				fflush(stdout);
				continue;
			}
			if(len<B)
			{
				sa.insert(s,len);
				ll ans=0;
				int p=1;
				for(int i=0;i<len;i++)
				{
//					cout<<"i="<<i<<endl;
					p=sa.go[p][s[i]-'a'];
					int np=p;
					while(np)
					{
//						cout<<"np="<<np<<" "<<cnt[np]<<endl;
						ans+=cnt[np];
						np=sa.par[np];
					}
				}
				putsi(ans);
			}
			else
			{
				sa.insert(s,len);
				sa.build_tree();
				sa.dfs();
				memset(pre,0,sizeof(pre));
				for(int i=1;i<=sa.tot;i++)
				{
					pre[sa.dl[i]]+=cnt[i];
					pre[sa.dr[i]+1]-=cnt[i];
				}
				for(int i=1;i<=sa.tot;i++)pre[i]+=pre[i-1];
				ll ans=0;
				int p=1;
				for(int i=0;i<len;i++)
				{
					p=sa.go[p][s[i]-'a'];
					ans+=pre[sa.dl[p]];
				}
				putsi(ans);
			}
		}
		fflush(stdout);
	}
}