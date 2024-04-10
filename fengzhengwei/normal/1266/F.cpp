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
	pc(x%10+'0',0);
}
void wts(int x,char op)
{
	if(x<0)x=-x,pc('-',0);
	wt(x),pc(op,0);
}
int n;
const int xx=5e5+5;
struct nod{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y){cnt++;e[cnt]={h[x],y};h[x]=cnt;}
int F[xx],md[xx],se[xx],dep[xx],f[xx];//mdse 
void dfs(int x,int y)
{
	f[x]=y,dep[x]=dep[y]+1,md[x]=0,se[x]=0;
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		dfs(e[i].to,x);
		if(md[e[i].to]+1>md[x])se[x]=md[x],md[x]=md[e[i].to]+1;
		else if(md[e[i].to]+1>se[x])se[x]=md[e[i].to]+1;
	}
}
void dfss(int x,int y)
{
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		if(md[x]==md[e[i].to]+1)F[e[i].to]=max(F[x]+1,se[x]+1);
		else F[e[i].to]=max(F[x]+1,md[x]+1);
		dfss(e[i].to,x);
	}
}
int ans[xx],suf[xx];//ansmax 
void ad(int &a,int b){a=max(a,b);}
vector<int>Q[xx];//i->i+1 
multiset<int>rans;
multiset<int>son[xx];
int val[xx];
//val i+val fi -1max V max 
void Pr(int x,int y)
{
	vector<int>lin;
	if(f[x])lin.push_back(F[x]);
	for(int i=h[x];i;i=e[i].next)
	{
		if(e[i].to==y)continue;
		Pr(e[i].to,x);
		lin.push_back(md[e[i].to]+1);
	}
	sort(lin.begin(),lin.end());
	// 
//	cout<<x<<" !!!\n";
//	for(auto it:lin)cout<<it<<" ";
//	puts("");
	for(int i=0;i<lin.size();i++)
	{
		if(lin.size()-i==1)break;// 
//		cerr<<x<<" "<<lin[i]*2<<"!!\n";
		ad(suf[lin[i]*2],lin.size()-i);// 
		if(i!=lin.size()-1&&lin[i]+1<=lin[i+1])// 
		ad(suf[lin[i]*2+1],lin.size()-i);
		Q[lin[i]].push_back(x);
	}
	val[x]=lin.size();
	for(int i=h[x];i;i=e[i].next)
		if(e[i].to!=y)son[x].insert(val[e[i].to]);
	if(son[x].size())rans.insert(val[x]+*--son[x].end()-2);
}
void Er(int x){if(son[x].size())rans.erase(rans.find(val[x]+*--son[x].end()-2));}
void In(int x){if(son[x].size())rans.insert(val[x]+*--son[x].end()-2);}
signed main(){
	n=read();
	for(int i=1;i<n;i++)
	{
		int a=read(),b=read();
		add(a,b),add(b,a);
	}
	dfs(1,0),dfss(1,0);
	//ans 
	suf[n]=1;
	Pr(1,0);
	for(int i=n-1;i>=1;i--)suf[i]=max(suf[i],suf[i+1]),ans[i]=max(ans[i],suf[i]);
	ans[n]=1;
//	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
//	puts("");
	//1ans+1 
//	for(auto it:rans)cout<<it<<" ";
//	puts("");
	for(int i=1;i<=n;i++)
	{
		if(i%2==0)
		{
			if(rans.size())ad(ans[i],*--rans.end());
			for(auto it:Q[i/2])
			{
				if(f[it])
				{
					Er(f[it]);
					son[f[it]].erase(son[f[it]].find(val[it]));
					son[f[it]].insert(val[it]-1);
					In(f[it]);
				}
				Er(it);
				val[it]--;
				In(it);
//				cout<<it<<"!@ASD\n";
//				for(auto _it:rans)cout<<_it<<" ";
//				puts("");
			}
		}
	}
	ans[1]++;// 
	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	puts("");
	pc('1',1);
	return 0;
}
/*
10
1 2
2 3
3 4
4 5
3 6
6 7
7 8
6 9
9 10

4 4 3 4 3 2 2 2 1 1
*/