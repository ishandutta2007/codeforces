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
void wts(int x,char op)
{
	if(x<0)pc('-',0),x=-x;
	wt(x);pc(op,0);
}
namespace zhs
{
	const int xx=5e5+5,mod=998244353;
	
}
namespace pr
{
	const int xx=5e5+5,mod=998244353;
	int prim[xx],mn[xx],cnt;
	void pre(int n)
	{
		for(int i=2;i<=n;i++)
		{
			if(!mn[i])mn[i]=i,prim[++cnt]=i;
			for(int j=1;j<=cnt;j++)
			{
				if(prim[j]*i>n)break;
				mn[i*prim[j]]=prim[j];
				if(i%prim[j]==0)break;
			}
		}
	}
}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
// 
const int xx=5e5+5,mod=998244353;
ll ksm(ll a,ll b)
{
	ll ans=1;
	while(b)
	{
		if(b&1)ans*=a,ans%=mod;
		a*=a,a%=mod,b>>=1;
	}
	return ans;
}
int n,m,k,q,a[xx];
//char s[xx];
int ans[205][205];
//nABi->i+1 
int id[xx],p[xx],s[xx];
void calc(int n)
{
	int jc=1;
	for(int i=1;i<=n;i++)jc*=i,id[i]=i;
	while(jc--)
	{
		next_permutation(id+1,id+n+1);
		p[1]=id[1];
		for(int i=2;i<=n;i++)p[i]=max(p[i-1],id[i]);
		s[n]=id[n];
		for(int i=n-1;i>=1;i--)s[i]=min(s[i+1],id[i]);
		int cr=1;
		for(int i=1;i<n;i++)if(p[i]<s[i+1])cr=0;
		if(!cr)continue;
		int iv=0,ii=0;
		for(int i=1;i<n;i++)if(id[i]>id[i+1])ii++;
		for(int i=1;i<n;i++)
			for(int j=i+1;j<=n;j++)
			{
				if(id[i]>id[j])
				{
					iv++;
					if(iv>11)break;
				}
			}
		
		ans[iv][ii]++;
	}
}
//0~120 1 
int tab[12][11][11]=
{
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,

1,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,

0,0,0,0,0,0,0,0,0,0,0,
2,0,0,0,0,0,0,0,0,0,0,
0,1,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,

0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
3,1,0,0,0,0,0,0,0,0,0,
1,4,0,0,0,0,0,0,0,0,0,
0,3,0,0,0,0,0,0,0,0,0,
0,0,1,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,

0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
4,4,0,0,0,0,0,0,0,0,0,
2,12,2,0,0,0,0,0,0,0,0,
2,12,4,0,0,0,0,0,0,0,0,
0,9,6,0,0,0,0,0,0,0,0,
0,3,6,0,0,0,0,0,0,0,0,
0,0,4,0,0,0,0,0,0,0,0,
0,0,0,1,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,

0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
5,10,1,0,0,0,0,0,0,0,0,
3,28,13,0,0,0,0,0,0,0,0,
4,35,29,1,0,0,0,0,0,0,0,
3,35,41,4,0,0,0,0,0,0,0,
1,30,44,7,0,0,0,0,0,0,0,
0,17,45,7,0,0,0,0,0,0,0,
0,8,30,11,0,0,0,0,0,0,0,

0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
6,20,6,0,0,0,0,0,0,0,0,
4,55,50,3,0,0,0,0,0,0,0,
6,80,118,18,0,0,0,0,0,0,0,
6,95,186,48,0,0,0,0,0,0,0,
6,101,230,85,2,0,0,0,0,0,0,
2,94,260,113,4,0,0,0,0,0,0,

0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
7,35,21,1,0,0,0,0,0,0,0,
5,96,145,26,0,0,0,0,0,0,0,
8,155,358,124,3,0,0,0,0,0,0,
9,207,616,313,16,0,0,0,0,0,0,
11,250,859,567,53,0,0,0,0,0,0,

0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
8,56,56,8,0,0,0,0,0,0,0,
6,154,350,126,4,0,0,0,0,0,0,
10,268,898,552,48,0,0,0,0,0,0,
12,389,1654,1404,204,1,0,0,0,0,0,

0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
9,84,126,36,1,0,0,0,0,0,0,
7,232,742,448,43,0,0,0,0,0,0,
12,427,1967,1887,357,6,0,0,0,0,0,

0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
10,120,252,120,10,0,0,0,0,0,0,
8,333,1428,1302,252,5,0,0,0,0,0,

0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,
11,165,462,330,55,1,0,0,0,0,0
};
int ct=0;
ll v[12][12][30][30];
int ida,idb;
//12 
//ll jiec[50],ni[50];
ll jiec[xx],ni[xx];
ll c(ll n,ll m)
{
	if(n<m)return 0;
	if(m<0)return 0;
	ll ans=1;
	for(int i=1;i<=m;i++)ans*=(n-i+1),ans%=mod;
	ans*=ni[m],ans%=mod;
	return ans;
}
int Mx;
void dfs(int a,int b,int num,int len,int sum)
{
	if(!a&&!b)
	{
		Mx=max(Mx,len);
//		v[ida][idb].
//	cout<<a<<" "<<b<<" "<<len<<" "<<sum<<"!!\n";
		ct++;
		v[ida][idb][num][len]+=sum;
		v[ida][idb][num][len]%=mod;
		return;
	}
	if(!sum)return;
	for(int L=2;L<=12;L++)
	for(int j=1;j<=b;j++)
		for(int i=j;i<=a;i++)
		{
			if(!tab[L-1][i-1][j-1])continue;
			dfs(a-i,b-j,num+1,len+L,1ll*sum*tab[L-1][i-1][j-1]%mod);
		}
}
//ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
void pre()
{
	jiec[0]=1;
	#define xx 50
	for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
	#undef xx
}
int main(){
	pre();
	//+ 
//	freopen("a.out","w",stdout);
//	calc(read());
	//i-1iv12 
	//3e4/fn 
	//n 
	// 
	for(int a=1;a<=11;a++)
	{
		for(int b=1;b<=11;b++)
		{
			ida=a,idb=b;
			dfs(a,b,0,0,1);
		}
	}
//	cout<<Mx<<"\n";
	int T=read();
	while(T--)
	{
		ll A=read(),B=read(),C=read();
		ll ans=0;
		for(int i=1;i<=29;i++)
		for(int j=1;j<=29;j++)
		{
			if(!v[B][C][i][j])continue;
//			cout<<v[B][C][i]<<" "<<c(A,i)<<" "<<i<<"!!\n";
			ans+=v[B][C][i][j]*c(A-j+i+1-1,i+1-1)%mod;
			ans%=mod;
		}
		cout<<ans<<"\n";
	}
//	cout<<ct<<"!!\n";
//	for(int num=1;num<=11;num++)
//	{
//		cerr<<num<<"!!\n";
//		memset(ans,0,sizeof(ans));
//		calc(num);
//		for(int i=1;i<=11;i++)
//		{
//			for(int j=1;j<=11;j++)
//				cout<<ans[i][j]<<",";
//			puts("");
//		}
//		puts("");
//	}
//	int T=read();
//	while(T--)
//	{
//		n=read();
//		ll ans=0;
//		for(int i=1;i<=n;i++)a[i]=read();
//		cout<<ans<<"\n";
//	}
	pc('1',1);
	return 0;
}
/*
1211 
11	165	462	330	55	1

*/