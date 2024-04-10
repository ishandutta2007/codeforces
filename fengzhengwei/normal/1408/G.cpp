#include<bits/stdc++.h>
#define ll long long
#define dd double
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
	wt(x),pc(op,0);
}
const int xx=3005;
int n,a[xx][xx];
// 
struct nod
{
	int x,y;
//	bool operator<(const nod&w)const{return v<w.v;}
};
vector<nod>v;
int siz[xx],num[xx],fa[xx];
int find(int x){return fa[x]==x?x:fa[x]=find(fa[x]);}
int ans[xx],cr,al;//alive 
int G(int x){return x*(x-1)/2;}
int ck(int x){x=find(x);if(G(siz[x])==num[x])return 1;return 0;}
int to[xx];
struct nd{int next,to;}e[xx<<1];
int cnt,h[xx],Cst; 
map<pair<int,int>,int>mp;// 
void add(int x,int y){/*cerr<<x<<" "<<y<<"!!\n";*/cnt++,e[cnt]={h[x],y},h[x]=cnt;}
void nw(int x)
{
	x=find(x),++Cst;
	for(int i=1;i<=n;i++)
	if(find(i)==x)
	{
		if(mp.find(make_pair(Cst,to[i]))==mp.end())add(Cst,to[i]),mp[make_pair(Cst,to[i])]=1;
		to[i]=Cst;
	}
}
const int mod=998244353;
int f[xx][xx],g[xx],Siz[xx];
void ad(int &a,int b){(a+=b)>=mod?a-=mod:0;}
void dfs(int x)
{
//	cout<<x<<" "<<"#$%$#\n";
	f[x][0]=1,Siz[x]=1;
	for(int i=h[x];i;i=e[i].next)
	{
		dfs(e[i].to);
		for(int j=0;j<=Siz[x]+Siz[e[i].to];j++)g[j]=0;
		for(int j=0;j<=Siz[x];j++)
			for(int k=0;k<=Siz[e[i].to];k++)
				ad(g[j+k],1ll*f[x][j]*f[e[i].to][k]%mod);
//		cout<<x<<" "<<Siz[x]<<" "<<Siz[e[i].to]<<" "<<f[x][0]<<" "<<f[e[i].to][1]<<"!!\n";
		for(int j=0;j<=Siz[x]+Siz[e[i].to];j++)f[x][j]=g[j];
	//	for(int j=0;j<=Siz[x]+Siz[e[i].to];j++)cout<<g[j]<<" ";
	//	puts("");
		Siz[x]+=Siz[e[i].to];
	}
	f[x][0]=0;// 
	f[x][1]++;
}
int main(){
	n=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)a[i][j]=read();
	v.resize(n*(n-1)/2);
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)v[a[i][j]-1]={i,j};
	for(int i=1;i<=n;i++)siz[i]=1,fa[i]=i,num[i]=0;
	al=cr=n;
//	sort(v.begin(),v.end());
	if(cr==al)ans[al]++;
	int Re=0;
	for(int i=1;i<=n;i++)to[i]=++Cst;
	//n^2 
	for(auto it:v)
	{
		if(find(it.x)==find(it.y))
		{
			cr-=ck(it.x),num[find(it.x)]++,cr+=ck(it.x),Re+=ck(it.x);
			if(ck(it.x))nw(it.x);
		}
		else 
		{
			al--;
			cr-=ck(it.x),cr-=ck(it.y);
			siz[find(it.y)]+=siz[find(it.x)];
			num[find(it.y)]+=num[find(it.x)];
			fa[find(it.x)]=find(it.y);
			num[find(it.x)]++;
			cr+=ck(it.x),Re+=ck(it.x);
			if(ck(it.x))nw(it.x);
		}
		if(cr==al)ans[al]++;
//		cout<<cr<<" "<<al<<"!!\n";
	}
	dfs(Cst);
//	cout<<Re<<"!!\n";
	for(int i=1;i<=n;i++)cout<<f[Cst][i]<<" ";
	puts("");
	pc('1',1);
	return 0;
}