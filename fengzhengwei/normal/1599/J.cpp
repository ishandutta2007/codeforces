// LUOGU_RID: 91777852
#include<bits/stdc++.h>
namespace ifzw{
#define ll long long 
#define dd double
#define LL __int128
#define ld long double
#define ull unsigned ll 
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
	static char buf[1<<16],*s=buf,*t=(buf+(1<<16));
	(op||((*s++=c)&&(s==t)))&&(fwrite(buf,1,s-buf,stdout),s=buf);
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
//struct nod
//{
//	int a[105];
//}e[105];
const int xx=1e3+5;
int n,a[xx];
void _wa(){puts("NO");exit(0);}
void _ac(vector<int>v)
{
//	for(auto it:v)cerr<<it<<" ";
//	puts("");
	puts("YES");
	assert(v.size());
	set<int>s;
	for(int i=1;i<=n;i++)s.insert(a[i]);
	for(int i=0;i<(int)v.size();i++)
		for(int j=i+1;j<(int)v.size();j++)if(s.count(v[i]+v[j]))s.erase(v[i]+v[j]);
//	cerr<<s.size()<<" "<<n-v.size()<<"#\n";
	assert(s.size()<=n-v.size());
	while(s.size())v.push_back(*s.begin()-v[0]),s.erase(s.begin());
	v.resize(n);
	for(auto it:v)cout<<it<<" ";
	puts("");
	exit(0);
}
void run(int a,int b,int c)
{
	int d=(a+b+c)/2;
	_ac({d-a,d-b,d-c});
}
// n>30  30  
int t[12000005];
vector<int>v[24];
int s[16777219];
int lb(int x){return x&-x;}
void re(int A,int B)
{
	// 
	vector<int>nw;
//	nw.push_back(0);
	vector<int>v1,v2;
	for(int i=0;i<24;i++)
		if(A>>i&1)v1.push_back(a[i+1]);
	for(int i=0;i<24;i++)
		if(B>>i&1)v2.push_back(a[i+1]);
	vector<int>ty;
	for(int i=0;i<(int)v1.size();i++)
	{
		ty.push_back(v1[i]);
		ty.push_back(v2[i]);
	}
	nw.push_back(ty.back());
	for(int i=0;i<(int)ty.size()-1;i++)
		nw.push_back((nw.back()-ty[i])*(-1));
//	cerr<<ty.size()<<"#\n";
	_ac(nw);
}
int main(){
//	freopen("a.in","r",stdin);
//	freopen("b.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1,[&](int x,int y){return (x&1)<(y&1);});
	if(n==2)
	{
		if(a[1]!=a[2])_wa();
		puts("YES");
		cout<<0<<" "<<a[1]<<"\n";
		exit(0);
	}
	// sz  
	// 3  
	if((a[1]&1)==0)
	{
		if((a[2]&1)==0&&(a[3]&1)==0)
			run(a[1],a[2],a[3]);
		else 
		{
			if((a[n]&1)&&(a[n-1]&1))run(a[1],a[n],a[n-1]);
		}
	}
	//check  
	// 24  C(24,12)  2.7e7  0~1e6*24 
	// 22  
	int m=min(n,24);
	for(int i=1;i<(1<<m);i++)s[i]=s[i-lb(i)]+a[__lg(lb(i))+1];
	for(int i=0;i<(1<<m);i++)
		v[__builtin_popcount(i)].push_back(i);
	for(int i=1;i<=m;i++)
	{
		for(auto it:v[i])
		{
			if(t[s[it]])
			{
				assert((t[s[it]]&it)==0);
				re(it,t[s[it]]);
				assert(0);
			}
			t[s[it]]=it;
		}
		for(auto it:v[i])
			t[s[it]]=0;
	}
	_wa();
//	for(int i=1;i<=n;i++)e[i].a[n+i]=1;
//	for(int i=1;i<=n;i++)e[i].a[i]=1;
//	for(int i=1;i<n;i++)e[i].a[i+1]=1;
//	e[n].a[1]=1;
//	
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n+n;j++)cout<<e[i].a[j]<<" \n"[j==n+n];
//	puts("");
//	
//	for(int i=1;i<=n;i++)
//	{
//		int j=i;
//		while(j<=n&&!e[j].a[i])++j;
//		if(j>n)continue;
//		swap(e[i],e[j]);
//		if(e[i].a[i]==-1)
//			for(int j=1;j<=n+n;j++)e[i].a[j]*=-1;
//		for(int j=1;j<=n;j++)
//		{
//			if(e[j].a[i]&&i!=j)
//			{
//				int lp=e[j].a[i];
//				for(int k=1;k<=n+n;k++)
//					e[j].a[k]-=e[i].a[k]*lp;
//			}
//		}
//	}
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=n+n;j++)cout<<e[i].a[j]<<" \n"[j==n+n];
//	puts("");
	pc('1',1);
	return 0;
}
/*

1 0 0 0 0 0 0 0 0 1 1 -1 1 -1 1 -1 1 -1 1 0
0 1 0 0 0 0 0 0 0 -1 0 1 -1 1 -1 1 -1 1 -1 0
0 0 1 0 0 0 0 0 0 1 0 0 1 -1 1 -1 1 -1 1 0
0 0 0 1 0 0 0 0 0 -1 0 0 0 1 -1 1 -1 1 -1 0
0 0 0 0 1 0 0 0 0 1 0 0 0 0 1 -1 1 -1 1 0
0 0 0 0 0 1 0 0 0 -1 0 0 0 0 0 1 -1 1 -1 0
0 0 0 0 0 0 1 0 0 1 0 0 0 0 0 0 1 -1 1 0
0 0 0 0 0 0 0 1 0 -1 0 0 0 0 0 0 0 1 -1 0
0 0 0 0 0 0 0 0 1 1 0 0 0 0 0 0 0 0 1 0
0 0 0 0 0 0 0 0 0 0 -1 1 -1 1 -1 1 -1 1 -1 1

*/


}signed main(){return ifzw::main();}