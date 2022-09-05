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
const int B=333;
int n,m;
int fail[100111],go[100111][26],tot=1;
int ed[100111];
vector<int> v[100111],con[100111],iv[100111],edv[100111];
char s[100111];
int par[100111],pc[100111],q[100111],qn;
void init()
{
	q[qn++]=1;
	for(int i=0;i<qn;i++)
	{
		int u=q[i];
		for(int j=0;j<26;j++)if(go[u][j])
		{
			q[qn++]=go[u][j];
			par[go[u][j]]=u;
			pc[go[u][j]]=j;
		}
	}
	for(int i=1;i<qn;i++)
	{
		int x=q[i];
		if(par[x]==1)fail[x]=1;
		else
		{
			int p=fail[par[x]];
			while(p!=1&&!go[p][pc[x]])p=fail[p];
			if(go[p][pc[x]])fail[x]=go[p][pc[x]];
			else fail[x]=p;
		}
		con[fail[x]].PB(x);
	}
}
vector<pair<pair<int,int>,int> >qr[100111];
ll ans[100111];
int tab[100111];
ll pre[100111];
const int BB=333;
struct data
{
	int sum[100111+B],psum[BB];
	data(){memset(sum,0,sizeof(sum));memset(psum,0,sizeof(psum));}
	void add(int x,int v)
	{
		sum[x]+=v;
		for(int i=x+1;i%B!=0;i++)sum[i]+=v;
		for(int i=x/B+1;i<BB;i++)psum[i]+=v;
	}
	int query(int x)
	{
		return psum[x/B]+sum[x];
	}
}rikka;
void dfs(int x)
{
	for(int i=0;i<edv[x].size();i++)
	{
		rikka.add(edv[x][i],1);
	}
	for(int i=0;i<con[x].size();i++)
	{
		int u=con[x][i];
		dfs(u);
	}
	for(int i=0;i<iv[x].size();i++)
	{
		int id=iv[x][i];
		if(v[id].size()>B)continue;
		for(int j=0;j<qr[id].size();j++)
		{
			ans[qr[id][j].SS]+=rikka.query(qr[id][j].FF.SS);
			ans[qr[id][j].SS]-=rikka.query(qr[id][j].FF.FF-1);
		}
	}
	for(int i=0;i<edv[x].size();i++)
	{
		rikka.add(edv[x][i],-1);
	}
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
	{
		scanf("%s",s);
		int l=strlen(s);
		int p=1;
		for(int j=0;j<l;j++)
		{
			if(!go[p][s[j]-'a'])go[p][s[j]-'a']=++tot;
			p=go[p][s[j]-'a'];
			v[i].PB(p);
			iv[p].PB(i);
		}
		ed[i]=p;
		edv[p].PB(i);
	}
	init();
	for(int i=1;i<=m;i++)
	{
		int l,r,k;
		scanf("%d%d%d",&l,&r,&k);
		qr[k].PB(MP(MP(l,r),i));
	}
	for(int i=1;i<=n;i++)
	{
		if(v[i].size()>B)
		{
			memset(tab,0,sizeof(tab));
			for(int j=0;j<v[i].size();j++)tab[v[i][j]]++;
			for(int j=qn-1;j>=1;j--)tab[fail[q[j]]]+=tab[q[j]];
			for(int j=1;j<=n;j++)pre[j]=pre[j-1]+tab[ed[j]];
			for(int j=0;j<qr[i].size();j++)
			{
				ans[qr[i][j].SS]=pre[qr[i][j].FF.SS]-pre[qr[i][j].FF.FF-1];
			}
		}
	}
	dfs(1);
	for(int i=1;i<=m;i++)printf("%I64d\n",ans[i]);
	return 0;
}