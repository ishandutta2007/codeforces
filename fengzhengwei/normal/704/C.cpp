#include<bits/stdc++.h>
#define ll long long
#define dd long double
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
const int xx=1e5+5;
int n,m;
struct no{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y){cnt++;e[cnt]={h[x],y};h[x]=cnt;}
// 
int d[xx];
vector<int>id[xx];// 
int sz[xx],L[xx][2],vis[xx];
const int mod=1e9+7;
//=0=1 
struct nod{int s[2];};
vector<nod>v;
void get(int x,vector<int>&s)
{
	s.push_back(x);vis[x]=1;
	for(int i=h[x];i;i=e[i].next)if(!vis[e[i].to])get(e[i].to,s);
}
void ad(int &a,int b){(a+=b)>=mod?a-=mod:0;}
int f[xx][2][2];
void cls(int siz)
{
	for(int i=0;i<=siz+1;i++)
		for(int j=0;j<=1;j++)
			for(int k=0;k<=1;k++)f[i][j][k]=0;
}
int ist(int a,int b)
{
	for(int i=0;i<=1;i++)
	for(int j=0;j<=1;j++)
	if(abs(L[a][i])==abs(L[b][j]))return (L[a][i]>0)^(L[b][j]>0);
	assert(0);
	return 0;
}
void chain(vector<int>&s)
{
	int siz=s.size();
	assert(siz!=1);
	// 
	cls(siz);
	f[0][0][0]=1;
	if(sz[s[0]]==2)// 
	{
		f[0][1][0]=1;
		f[0][0][0]=1;
	}
	// 
	// 
	
	for(int i=0;i<siz-1;i++)
	{
		//(ban)0/1 
		int op=ist(s[i],s[i+1]);
//		cout<<op<<"!!asd\n";
		for(int j=0;j<=1;j++)
		{
			for(int k=0;k<=1;k++)
			{
//				cout<<i<<" "<<j<<" "<<k<<" "<<f[i][j][k]<<"!!\n";
				for(int Is=0;Is<=1;Is++)
					//=1=0  
					ad(f[i+1][Is^op][k^(j|Is)],f[i][j][k]);
				
			}
		}
	}
	//ok 
	if(sz[s[siz-1]]==2)
	{
		for(int j=0;j<=1;j++)
		{
			for(int k=0;k<=1;k++)
			{
				for(int Is=0;Is<=1;Is++)
					ad(f[siz][0][k^(j|Is)],f[siz-1][j][k]);
			}
		}
	}
	else 
	{
		for(int j=0;j<=1;j++)
		{
			for(int k=0;k<=1;k++)
			{
				for(int Is=0;Is<=0;Is++)
					ad(f[siz][0][k^(j|Is)],f[siz-1][j][k]);
			}
		}
	}
	v.push_back({f[siz][0][0],f[siz][0][1]});
}
void circle(vector<int>&s)
{
	int siz=s.size();
	if(siz==1)
	{
		int op=0;
		for(int i=0;i<=1;i++)
			op^=(L[s[0]][i]>0);
		if(!op)
			v.push_back({1,1});
		else v.push_back({0,2});
		return ;
	}
	// 
	//10 
	cls(siz);
	f[0][0][0]=1;
	s.push_back(s[0]);//siz 
	int ans[2]={0,0};
	for(int i=0;i<siz;i++)
	{
		int op=ist(s[i],s[i+1]);
		for(int j=0;j<=1;j++)
		{
			for(int k=0;k<=1;k++)
			{
				for(int Is=0;Is<=1;Is++)
					//=1=0  
					ad(f[i+1][Is^op][k^(j|Is)],f[i][j][k]);
			}
		}
	}
	ad(ans[0],f[siz][0][0]),ad(ans[1],f[siz][0][1]);
	cls(siz);
	f[0][1][0]=1;
	for(int i=0;i<siz;i++)
	{
		int op=ist(s[i],s[i+1]);
		for(int j=0;j<=1;j++)
		{
			for(int k=0;k<=1;k++)
			{
				for(int Is=0;Is<=1;Is++)
					//=1=0  
					ad(f[i+1][Is^op][k^(j|Is)],f[i][j][k]);
			}
		}
	}
	ad(ans[0],f[siz][1][0]),ad(ans[1],f[siz][1][1]);
	v.push_back({ans[0],ans[1]});
}
int g[xx][2];
int main(){
	n=read(),m=read();
	for(int i=1;i<=n;i++)
	{
		sz[i]=read();
		for(int j=0;j<sz[i];j++)
		{
			int a=read();
			L[i][j]=a;
			id[abs(a)].push_back(i);
		}
	}
	// 
	int num=0;
	for(int i=1;i<=m;i++)
	{
		if(!id[i].size())num++;
		if(id[i].size()==2)add(id[i][0],id[i][1]),add(id[i][1],id[i][0]),d[id[i][0]]++,d[id[i][1]]++;
		//=1a 
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		if(!d[i])
		{
			// 
			if(sz[i]==1)v.push_back({1,1});
			if(sz[i]==2)v.push_back({1,3});// 
			vis[i]=1;
			continue;
		}
		if(d[i]==1)
		{
			vector<int>N;
			get(i,N);
			chain(N);
//			for(auto it:N)cout<<it<<"!!\n";
//			puts("ADasd");
			continue;
		}
	}
	for(int i=1;i<=n;i++)
	{
		if(vis[i])continue;
		vector<int>N;
		get(i,N);
		circle(N);
	}
	cls(n+1);
//	for(auto it:v)
//		cout<<it.s[0]<<" "<<it.s[1]<<"!@!\n";
	g[0][0]=1;
	int i=0;
	for(auto it:v)
	{
		for(int j=0;j<=1;j++)
			for(int k=0;k<=1;k++)
				ad(g[i+1][j^k],1ll*g[i][j]*it.s[k]%mod);
		i++;
	}
	while(num--)ad(g[i][1],g[i][1]);
	cout<<g[i][1]<<"\n";
	pc('1',1);
	return 0;
}