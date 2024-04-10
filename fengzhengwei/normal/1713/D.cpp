#include<bits/stdc++.h>
#define ll long long
#define LL __int128
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
	wt(x);pc(op,0);
}
namespace ppprrr{const int xx=2,mod=2;ll ksm(ll a,ll b){ll ans=1;while(b){if(b&1)ans*=a,ans%=mod;a*=a,a%=mod,b>>=1;}return ans;}

ll jiec[xx],ni[xx];
ll C(ll n,ll m){return jiec[n]*ni[m]%mod*ni[n-m]%mod;}
void pre()
{
	jiec[0]=1;
	for(int i=1;i<xx;i++)jiec[i]=jiec[i-1]*i%mod;
	ni[xx-1]=ksm(jiec[xx-1],mod-2);
	for(int i=xx-2;i>=0;i--)ni[i]=ni[i+1]*(i+1)%mod;
}
	
int prim[xx],mn[xx],Cnt;
void pre(int n)
{
	for(int i=2;i<=n;i++)
	{
		if(!mn[i])mn[i]=i,prim[++Cnt]=i;
		for(int j=1;j<=Cnt;j++)
		{
			if(prim[j]*i>n)break;
			mn[i*prim[j]]=prim[j];
			if(i%prim[j]==0)break;
		}
	}
}


int lb(int x){return x&-x;}
ll sum[xx];
void Add(int x,int y){for(;x<xx;x+=lb(x))sum[x]+=y;}
ll ask(int x){ll ans=0;for(;x;x-=lb(x))ans+=sum[x];return ans;}

struct nod{int next,to;}e[xx<<1];
int cnt,h[xx];
void add(int x,int y){cnt++,e[cnt]={h[x],y},h[x]=cnt;}


}
int gcd(int a,int b){return !b?a:gcd(b,a%b);}
//co 
const int xx=1e6+5,mod=998244353;
//mod1e9+7998 
void ad(int &a,int b){(a+=b)>=mod?a-=mod:0;}
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
struct pr{int x,y;};
int n,m,k,q,a[xx],b[xx];
char s[xx];
mt19937 fhq_random(218);
template<int nd>struct fhq_val
{
	void split_v(int k,int a,int &x,int &y)
	{
		if(!k)return x=y=0,void();
		pd(k);
		if(val[k]<=a)x=k,split_v(c[k][1],a,c[k][1],y);
		else y=k,split_v(c[k][0],a,x,c[k][0]);
		upd(k);
	}
	void split_s(int k,int a,int &x,int &y)
	{
		if(!k)return x=y=0,void();
		pd(k);
		if(siz[c[k][0]]+1<=a)x=k,split_s(c[k][1],a-siz[c[k][0]]-1,c[k][1],y);
		else y=k,split_s(c[k][0],a,x,c[k][0]);
		upd(k);
	}
	int merge(int x,int y)
	{
		if(!x||!y)return x+y;
		pd(x),pd(y);
		if(rd[x]<rd[y])return c[x][1]=merge(c[x][1],y),upd(x),x;
		return c[y][0]=merge(x,c[y][0]),upd(y),y;
	}
	int tmerge(int a,int b)
	{
		if(!a||!b)return a+b;
		if(rd[a]>rd[b])swap(a,b);
		pd(a),pd(b);
		int x,y;
		split_v(b,val[a],x,y);
		c[a][0]=tmerge(c[a][0],x);
		c[a][1]=tmerge(c[a][1],y);
		upd(a);
		return a;
	}
	void ins(int &rt,ll v)
	{
		int x,y;
		split_v(rt,v,x,y);
		rt=merge(x,merge(nw(v),y));
	}
	void era(int &rt,ll v)//v 
	{
		int x,y,z;
		split_v(rt,v,x,z);
		split_v(x,v-1,x,y);
		y=merge(c[y][0],c[y][1]);
		rt=merge(x,merge(y,z));
	}
	void print(int k)
	{
		puts("Out the Fhq ");
		pr(k);
		puts("");
		puts("End");
	}
	//val 
	unsigned int rd[nd];
	int c[nd][2],siz[nd],cst;
	ll sum[nd],adt[nd],val[nd];
	void pr(int k)
	{
		pd(k); 
		if(c[k][0])pr(c[k][0]);
		cerr<<sum[k]<<" ";
		if(c[k][1])pr(c[k][1]);
	}
	void upd(int k)
	{
		if(!k)return;
		siz[k]=siz[c[k][0]]+siz[c[k][1]]+1;
		sum[k]=sum[c[k][0]]+sum[c[k][1]]+val[k];
	}
	int nw(ll v)
	{
		++cst;
		val[cst]=v,sum[cst]=v,rd[cst]=fhq_random(),siz[cst]=1;
		return cst;
	}
	void ad(int k,ll z)
	{
		if(k)sum[k]+=z*siz[k],adt[k]+=z,val[k]+=z;
	}
	int kth(int &rt,int k)
	{
		int x,y,z;
		split_s(rt,k-1,x,y);
		split_s(y,1,y,z);
		int ans=val[y];
		rt=merge(x,merge(y,z));
		return ans;
	}
	void pd(int k)
	{
		//if(adt[k])ad(c[k][0],adt[k]),ad(c[k][1],adt[k]),adt[k]=0;
	}
};
//fhq_val<xx>F;
random_device R;
mt19937 G(R());
int rd(int l,int r){return uniform_int_distribution<int>(l,r)(G);}
int rt;
int ask(int l,int r)
{
	cout<<"? "<<l<<" "<<r<<"\n";
	fflush(stdout);
	return read();
}
vector<int>rem;
void fir()
{
	assert(rem.size()%4==0);
	vector<int>nw;
	for(int i=0;i<rem.size();i+=4)
	{
		int L=rem[i],R=rem[i+1],A=rem[i+2],B=rem[i+3];
		int ty=ask(L,A);
		if(ty==0)
		{
			nw.push_back(R);
			nw.push_back(B);
		}
		else if(ty==1)
		{
			nw.push_back(L);
			nw.push_back(B);
		}
		else if(ty==2)
		{
			nw.push_back(R);
			nw.push_back(A);
		}
	}
	swap(nw,rem);
}
void sec()
{
	// 
	vector<int>nw;
	for(int i=0;i<rem.size();i+=2)
	{
		int L=rem[i],R=rem[i+1];
		int ty=ask(L,R);
		if(ty==0||ty==1)nw.push_back(L);
		else nw.push_back(R);
	}
	swap(nw,rem);
}
int main(){
	int T=read();
	while(T--)
	{
		n=read();
		rem.clear();
		for(int i=1;i<=(1<<n);i++)rem.push_back(i);
		while(rem.size()!=1)
		{
			if(rem.size()==2)sec();
			else 
			{
				fir();
				sec();
			}
		}
		cout<<"! "<<*rem.begin()<<"\n";
	fflush(stdout);
		
	}
	// 
//	for(int i=0;i<17;i++)
//		for(int j=1;j<=(1<<i);j++)a[j]++;
//	for(int i=1;i<=(1<<17);i++)F.ins(rt,i);
//	ll p=0;
//	// 2/3 n 
//	int n=(1<<16);
//	for(int i=1;i<=16;i+=2)
//	{
//		p+=(n>>i);
//	}
//	cout<<p<<"\n";
//	exit(0);
//	int rem=(1<<17);
//	int ct=0;
//	while(rem!=1)
//	{
//		int L=rd(1,rem),R=rd(1,rem);
//		if(L==R)continue;
//		L=F.kth(rt,L);
//		R=F.kth(rt,R);
//		++ct;
//		if(a[L]==a[R])
//		{
//			F.era(rt,L);
//			F.era(rt,R);
//			rem-=2;
//		}
//		else 
//		{
//			if(a[L]>a[R])F.era(rt,R);
//			else F.era(rt,L);
//			rem-=1;
//		}
//	}
//	cerr<<ct<<"%%\n";
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