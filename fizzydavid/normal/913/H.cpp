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
const int mod=998244353;
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
int n,C[103][103];
int a[33];
ll iv;
struct func
{
	vector<int> v;
	int l;
	ll calc(int x)
	{
		int ret=0,bs=1;
		for(int i=0;i<v.size();i++)ret=(ret+1ll*v[i]*bs)%mod,bs=1ll*bs*x%mod;
		return ret;
	}
	func itg(ll coef)
	{
		func ret;
		ret.l=l;
		ret.v.PB(0);
		for(int i=0;i<v.size();i++)ret.v.PB(1ll*v[i]*qpow(i+1,mod-2)%mod*iv%mod);
		ret.v[0]=(mod-ret.calc(l)+coef)%mod;
		return ret;
	}
	func operator-(const func &t)const
	{
		func ret;
		ret.l=max(l,t.l);
		ret.v.resize(max(v.size(),t.v.size()));
		for(int i=0;i<ret.v.size();i++)
		{
			int x=0;
			if(i<v.size())x+=v[i];
			if(i<t.v.size())x-=t.v[i];
			ret.v[i]=(x+mod)%mod;
		}
		return ret;
	}
	func operator>>(int x)
	{
		func ret;
		int pw[100];
		pw[0]=1;
		for(int j=1;j<=v.size();j++)pw[j]=1ll*pw[j-1]*(mod-x%mod)%mod;	
		ret.l=l+x;
		ret.v.resize(v.size());
		for(int i=0;i<v.size();i++)
		{
			if(v[i]==0)continue;
			for(int j=0;j<=i;j++)
			{
				ret.v[j]=(ret.v[j]+1ll*C[i][j]*pw[i-j]%mod*v[i])%mod;
			}
		}
		return ret;
	}
};
func makefunc(int l,vector<int>v)
{
	func ret;
	ret.l=l;
	ret.v=v;
	return ret;
}
vector<func> v,nv,tv;
void out(vector<func> &v)
{
	cerr<<"size="<<v.size()<<endl;
		for(int j=0;j<v.size();j++)
		{
			cerr<<v[j].l<<" ";
			for(int k=0;k<v[j].v.size();k++)cerr<<v[j].v[k]<<",";
			cerr<<endl;
		}
		cerr<<endl;
}
const ll PW=1000000;
ll lm[33];
int main()
{
	for(int i=0;i<=100;i++)
	{
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	}
	iv=qpow(PW,mod-2);
	v.PB(makefunc(0,{1}));
	cin>>n;
	for(int i=0;i<n;i++)
	{
		double x;
		cin>>x;
		lm[i]=int(x*PW+0.5);
	}
	for(int i=n-2;i>=0;i--)lm[i]=min(lm[i],lm[i+1]);
	for(int i=0;i<n;i++)
	{
//		cerr<<"-------------i="<<i<<endl;
//		out(v);
		int lim=lm[i];
		for(int j=0;j<v.size();j++)
		{
			if(j>0)v[j]=v[j].itg(v[j-1].calc(v[j].l));
			else v[j]=v[j].itg(0);
		}
		nv.clear();
		nv.PB(makefunc(0,{0}));
		for(int j=0;j<v.size();j++)
		{
			nv.PB(v[j]>>PW);
		}
		int i1=0,i2=0;
		tv.clear();
		while(true)
		{
			tv.PB(v[i1]-nv[i2]);
			if(i1+1==v.size()&&i2+1==nv.size())break;
			if(i1+1<v.size()&&(i2+1==nv.size()||v[i1+1].l<=nv[i2+1].l))i1++;
			else i2++;
		}
//		out(tv);
		v.clear();
		for(int i=0;i<tv.size();i++)
		{
			if(i+1==tv.size()||tv[i].l<tv[i+1].l)
			{
				v.PB(tv[i]);
			}
		}
		int id=-1;
		for(int j=0;j<v.size();j++)if(v[j].l<lim)id=j;
		assert(id!=-1);
		int p=v[id].calc(lim);
		v.resize(id+1);
		v.PB(makefunc(lim,{p}));
	}
//	out(v);
	cout<<v[int(v.size())-1].calc(1000000000)<<endl;
	return 0;
}