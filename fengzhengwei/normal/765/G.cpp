#pragma GCC optimize(2)
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize(3,"Ofast","inline")
#include<bits/stdc++.h>
#define ll long long
#define dd double
#define LL __int128
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
char ST;
const int xx=2e6+5;
char s[xx];
int n,m;
struct nod
{
	int p,q;
}e[xx];
namespace bf
{
	int rl[xx<<1];
	void ty()
	{
		LL nw=1;
		for(int i=1;i<=n;i++)
		{
			if(e[i].q>20)return;
			for(int j=1;j<=e[i].q;j++)
			{
				nw*=e[i].p;
				if(nw>2e6)return;
			}
		}
		int N=nw;
		//
		for(int i=0;i<=N+50;i++)rl[i]=1;
		for(int i=1;i<=n;i++)
			for(int j=0;j<=N+50;j+=e[i].p)rl[j]=0;
		int ans=0;
		//for(int i=0;i<N;i++)cout<<rl[i]<<" ";
		//puts("");
		for(int i=0;i<N;i++)
		{
			int cr=1;
			for(int j=1;j<=m;j++)
				if(s[j]-'0'!=rl[i+j-1])cr=0;
			ans+=cr;
		}
		cout<<ans<<"\n";
		exit(0);
	}
}
/*
11111110
1
97 3
*/
//9409
const int mod=1e9+7;
int ksm(int a,int b)
{
	int ans=1;
	while(b)
	{
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod,b>>=1;
	}
	return ans;
}
namespace one
{
	int rl[xx<<1];
	void solve()
	{
		if(e[1].p<=50)
		{
			int N=e[1].p;
			for(int i=0;i<=N+50;i++)rl[i]=1;
			for(int i=1;i<=n;i++)
				for(int j=0;j<=N+50;j+=e[i].p)rl[j]=0;
			int ans=0;
			//for(int i=0;i<N;i++)cout<<rl[i]<<" ";
			//puts("");
			for(int i=0;i<N;i++)
			{
				int cr=1;
				for(int j=1;j<=m;j++)
					if(s[j]-'0'!=rl[i+j-1])cr=0;
				ans+=cr;
			}
		//	cerr<<ans<<"$$\n";
			cout<<1ll*ans*ksm(e[1].p,e[1].q-1)%mod<<"\n";
		}
		else 
			cout<<ksm(e[1].p,e[1].q-1)<<"\n";
		exit(0);
	}
}
//
namespace small
{
	void solve()
	{
		int tt=0;
		for(int i=1;i<=m;i++)
			if(s[i]=='0')tt+=(1<<(i-1));
		ll ans=0;
		//0/11 0 
		for(int i=0;i<(1<<m);i++)// -1^(count(tt)-count(i))
		{
			if((tt&i)==i)
			{
				ll nw=1;
				for(int j=1;j<=n;j++)
				{
					if(e[j].p>=m)
						nw*=e[j].p-m+__builtin_popcountll(i),nw%=mod;
					else 
					{
						ll te=0;
						for(int k=0;k<e[j].p;k++)
						{
							int cr=1;
							for(int w=k;w<m;w+=e[j].p)
								cr&=(i>>w&1);
							te+=cr;
						}
						nw*=te,nw%=mod;
					}
				}
				ans+=1ll*(((__builtin_popcountll(tt)-__builtin_popcountll(i))&1)?mod-1:1)*nw,ans%=mod;
			//	cerr<<i<<" "<<nw<<"#$#$\n";
			}
		}
		//cerr<<ans<<"$$\n";
		ll other=1;
		for(int i=1;i<=n;i++)other*=ksm(e[i].p,e[i].q-1),other%=mod;
		cout<<1ll*ans*other%mod<<"\n";
		exit(0);
	}
}


namespace big
{
	ll C(ll n,ll m)
	{
		if(n<m||m<0||n<0)return 0;
		ll tt=1;
		for(int i=1;i<=m;i++)
			tt*=(n-i+1),tt%=mod;
		for(int i=1;i<=m;i++)
			tt*=ksm(i,mod-2),tt%=mod;
		return tt;
	}
	void solve()
	{
		ll tt=0;
		for(int i=1;i<=m;i++)
			if(s[i]=='0')tt+=(1ll<<(i-1));
		ll ans=0;
		ll ct=__builtin_popcountll(tt);
		for(int i=0;i<=ct;i++)
		{
			ll nw=1;
			ll gs=C(ct,i);
			for(int j=1;j<=n;j++)
			{
				if(e[j].p>=m)
					nw*=e[j].p-m+i,nw%=mod;
			}
			ans+=1ll*(((ct-i)&1)?mod-1:1)*nw%mod*gs,ans%=mod;
			
		}
		ll other=1;
		for(int i=1;i<=n;i++)other*=ksm(e[i].p,e[i].q-1),other%=mod;
		cout<<1ll*ans*other%mod<<"\n";
		exit(0);
	}
}

namespace sc
{
	map<ll,int>mp;
	ll tt;
	ll C(ll n,ll m)
	{
		if(n<m||m<0||n<0)return 0;
		ll tt=1;
		for(int i=1;i<=m;i++)
			tt*=(n-i+1),tt%=mod;
		for(int i=1;i<=m;i++)
			tt*=ksm(i,mod-2),tt%=mod;
		return tt;
	}
	ll St[80][80];
	int lim;
	ll num[80];
	//aaaa siz
	void dfs(int x,ll S)
	{
		if((tt&S)!=S)return;
		if(x==lim)
		{
			//mp[S]=1;
			num[__builtin_popcountll(S)]++;
			return;
		}
		for(int j=0;j<e[x].p;j++)
			dfs(x+1,S|St[x][j]);
	}
	void solve()
	{
		for(int i=1;i<=m;i++)
			if(s[i]=='0')tt+=(1ll<<(i-1));
		sort(e+1,e+n+1,[&](const nod&A,const nod&B){return A.p<B.p;});
		lim=n+1;
		for(int i=1;i<=n;i++)
		{
			if(e[i].p>=m)
			{
				lim=i;
				break;
			}
		}
		for(int i=1;i<lim;i++)
		{
			for(int j=0;j<e[i].p;j++)
			{
				for(int k=j;k<m;k+=e[i].p)
					St[i][j]|=(1ll<<k);
			}
		}
		dfs(1,0);
		//cerr<<mp.size()<<"$$\n";
		ll ans=0;
		ll tct=__builtin_popcountll(tt);
		for(int i=0;i<=tct;i++)
		{
			ll nw=1;
			for(int j=1;j<=n;j++)
			{
				if(e[j].p>=m)
					nw*=e[j].p-m+i,nw%=mod;
			}
			// sigma 
			ll sigm=0;
			for(int j=0;j<=i;j++)
				sigm+=C(tct-j,i-j)*num[j]%mod,sigm%=mod;
			ans+=1ll*(((tct-i)&1)?mod-1:1)*nw%mod*sigm,ans%=mod;
		}
		ll other=1;
		for(int i=1;i<=n;i++)other*=ksm(e[i].p,e[i].q-1),other%=mod;
		cout<<1ll*ans*other%mod<<"\n";
		exit(0);
	}
}
namespace dp
{
	ll tt;
	ll C(ll n,ll m)
	{
		if(n<m||m<0||n<0)return 0;
		ll tt=1;
		for(int i=1;i<=m;i++)
			tt*=(n-i+1),tt%=mod;
		for(int i=1;i<=m;i++)
			tt*=ksm(i,mod-2),tt%=mod;
		return tt;
	}
	ll St[80][80];
	int lim,nlim;
	ll num[80];
	const int Mod=1111101;
	struct Hash
	{
		struct nd{int val,next;ll I;}e[(int)Mod+Mod+5];
		int h[Mod-1],cnt,cl[Mod-1],tt;
		void cls()
		{
			for(int i=1;i<=tt;i++)h[cl[i]]=0;
			tt=cnt=0;
		}
		int find(const ll&F)
		{
			int v=F%Mod;
			int re=0;
			for(int i=h[v];i;i=e[i].next)if(e[i].I==F)return i;
			++cnt,e[cnt]={0,h[v],F},h[v]=cnt,cl[++tt]=v;
			return cnt;
		}
		int &operator[](const ll&F)
		{
			int id=find(F);
			return e[id].val;
		}
	}mp[2];
//	map<ll,int>mp[2];
	//
	void dfs(int x,ll S)
	{
		if((tt&S)!=S)return;
		if(x==lim)
		{
			num[__builtin_popcountll(S)]++;
			return;
		}
		for(int j=0;j<e[x].p;j++)
			dfs(x+1,S|St[x][j]);
	}
	void ad(int &a,int b){(a+=b)>=mod?a-=mod:a;};
	void ad(int &a,ll b){a=(a+b)%mod;};
	ll nv[xx],D[xx],ct[xx],val[xx];
	ll sim(ll A,int x)
	{
//		cerr<<A<<" "<<x<<"%%\n";
		if(x==nlim)return ct[__builtin_popcountll(A)];
//		return A;
		if(!val[x])return A;
//		cerr<<x<<" "<<nlim<<"$$\n";
		return (A&((-1ll)^val[x]))|(ct[__builtin_popcountll(A&val[x])]<<D[x]);
	}
	void solve()
	{
		ct[0]=0;
		for(int i=1;i<=40;i++)ct[i]=ct[i-1]<<1|1;
		for(int i=1;i<=m;i++)
			if(s[i]=='0')tt+=(1ll<<(i-1));
		sort(e+1,e+n+1,[&](const nod&A,const nod&B){return A.p<B.p;});
		lim=n+1;
		for(int i=1;i<=n;i++)
		{
			if(e[i].p>=m||e[i].p>20)
			{
				lim=i;
				break;
			}
		}
		nlim=n+1;
		for(int i=1;i<=n;i++)
		{
			if(e[i].p>=m)
			{
				nlim=i;
				break;
			}
		}
		for(int i=1;i<nlim;i++)
		{
			for(int j=0;j<e[i].p;j++)
			{
				for(int k=j;k<m;k+=e[i].p)
					St[i][j]|=(1ll<<k);
				if((tt&St[i][j])!=St[i][j])St[i][j]=0;
			}
		}
		for(int i=lim;i<nlim;i++)
		{
			D[i]=-1;
			for(int j=0;j<e[i].p;j++)
			{
				int re=0;
				for(int k=j;k<m;k+=e[i].p)++re;
				if(re==1)val[i]|=(1ll<<j),St[i][j]*=-1,(D[i]==-1?D[i]=j:0);// 
			}
//			cerr<<i<<" "<<val[i]<<" "<<lim<<" "<<nlim<<"$$\n";
		}
		mp[0][0]=1;
		int Nw=0,Ty=1;
//		cerr<<lim<<" "<<nlim<<"$$\n";
		for(int x=1;x<nlim;x++)
		{
			for(int j=1;j<=mp[Nw].cnt;j++)
//			for(auto &to:mp[Nw])
			{
				ll S=mp[Nw].e[j].I,v=mp[Nw].e[j].val;
//				ll S=to.first,v=to.second;
//				cerr<<x<<" "<<S<<" "<<v<<"%%\n";
				if(!val[x])
				{
					for(int j=0;j<e[x].p;j++)
					{
						
						if(St[x][j])ad(mp[Ty][sim(S|St[x][j],x+1)],v);
//						,cerr<<j<<"$$$\n";
					}
//				cerr<<x<<" "<<S<<" "<<v<<"$$$\n";
				}
				else 
				{
					int op=0;
					for(int j=0;j<e[x].p;j++)
					{
						op+=(St[x][j]<0);
						if(St[x][j]>0)ad(mp[Ty][sim(S|St[x][j],x+1)],v);
					}
					ll num=__builtin_popcountll(S&val[x]);
					ll tn=__builtin_popcountll(tt&val[x]);
					ad(mp[Ty][sim(S,x+1)],v*num);
					if(tn!=num)
					ad(mp[Ty][sim((S&((-1ll)^val[x]))|(ct[num+1]<<D[x]),x+1)],v*(tn-num));
				}
			}
//			mp[Nw].clear();
			mp[Nw].cls();
			swap(Nw,Ty);
		}
		
		// dp  
		for(int j=1;j<=mp[Nw].cnt;j++)
//			for(auto &to:mp[Nw])
		{
			ll S=mp[Nw].e[j].I,v=mp[Nw].e[j].val;
//			if((tt&S)!=S)continue;
			
//			if(S==tt)
//			cerr<<__builtin_popcountll(S)<<" "<<v<<"$$\n";
			(num[__builtin_popcountll(S)]+=v)%=mod;
		}
		//dfs(1,0);
		ll ans=0;
		ll tct=__builtin_popcountll(tt);
		for(int i=0;i<=tct;i++)
		{
			ll nw=1;
			for(int j=1;j<=n;j++)
			{
				if(e[j].p>=m)
					nw*=e[j].p-m+i,nw%=mod;
			}
			// sigma 
			ll sigm=0;
			for(int j=0;j<=i;j++)
				sigm+=C(tct-j,i-j)*num[j]%mod,sigm%=mod;
			ans+=1ll*(((tct-i)&1)?mod-1:1)*nw%mod*sigm,ans%=mod;
//			cerr<<i<<" "<<nw<<" "<<(nw%mod*sigm%mod)<<" "<<ans<<"$$\n"; 
		}
//		cerr<<ans<<"$$\n";
		ll other=1;
		for(int i=1;i<=n;i++)other*=ksm(e[i].p,e[i].q-1),other%=mod;
		cout<<1ll*ans*other%mod<<"\n";
		exit(0);
	}
}
void Test()
{
	bf::ty();
	//one
	//cerr<<"$$\n";
	/*if(n==1)
	{
		one::solve();
		exit(0);
	}*/
	
	if(m<=17&&n<=100)
	{
		small::solve();
		exit(0);
	}
	int cr=1;
	for(int i=1;i<=n;i++)
		if(e[i].p<m)cr=0;
	if(cr)
	{
		big::solve();
		exit(0);
	}
	//ok
	//
	//
	if(m<=29)
	sc::solve();
}
char ED;
int main(){
	cerr<<abs(&ST-&ED)/1024.0/1024<<"\n";
//	freopen("count.in","r",stdin);
//	freopen("count.out","w",stdout);
	scanf("%s",s+1);//
	m=strlen(s+1);
	n=read();
	for(int i=1;i<=n;i++)
		e[i].p=read(),e[i].q=read();
//	Test();
	dp::solve();
	pc('1',1);
	return 0;
}