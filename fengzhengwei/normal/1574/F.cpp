// LUOGU_RID: 91666088
#include<bits/stdc++.h>
namespace ifzw{
#define ll long long 
#define dd double
#define LL __int128
#define ld long double
#define ull unsigned ll 
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
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
const int xx=3e5+5,mod=998244353;
vector<vector<int> >L;
int n,m,k,bel[xx],ban[xx],ct[xx],nx[xx];
ll f[xx];
int main(){
//	freopen("a.in","r",stdin);
//	freopen("b.out","w",stdout);
	n=read(),m=read(),k=read();
	L.resize(n);
	for(auto &v:L)
	{
		int c=read();
		v.resize(c);
		for(auto &it:v)it=read();
	}
	for(int i=1;i<=k;i++)L.push_back({i});
	sort(L.begin(),L.end(),[&](const vector<int>&A,const vector<int>&B){return A.size()>B.size();});
	//  1-2 2-3  1-2-3 
	for(auto &v:L)
	{
		int cr=0;
		for(auto it:v)if(ban[it])cr=1;
		int ls=-1;
		for(auto it:v)
		{
			if(ls!=-1&&(nx[ls]!=it&&nx[ls]!=0)){cr=1;break;}
			nx[ls]=it;
			ls=it;
		}
		if(cr)
			for(auto it:v)ban[it]=1;
	}
	for(int i=1;i<=k;i++)ct[nx[i]]++;
	vector<int>use;
	for(int i=1;i<=k;i++)
	{
		if(!ct[i])
		{
			int x=i,len=0,cr=0;
			while(x)
			{
				if(ct[x]>1||ban[x]){cr=1;break;}
				++len,x=nx[x];
			}
			if(!cr)use.push_back(len);
		}
	}
	vector<int>ls=use;
	sort(ls.begin(),ls.end());
	ls.resize(unique(ls.begin(),ls.end())-ls.begin());
	vector<int>N(ls.size());
	for(auto it:use)N[lower_bound(ls.begin(),ls.end(),it)-ls.begin()]++;
	f[0]=1;
	for(int i=0;i<=m;i++)
		for(int j=0;j<(int)ls.size();j++)(f[i+ls[j]]+=f[i]*N[j])%=mod;
	cout<<f[m]<<"\n"; 
	pc('1',1);
	return 0;
}



}signed main(){return ifzw::main();}