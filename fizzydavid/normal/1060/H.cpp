//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
#ifndef LOCAL
#define cerr if(0)cout
#endif
typedef long long ll;
int d,mod,tot;
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
struct CMD
{
	bool op;
	int x,y,z;
	CMD(bool OP=0,int X=0,int Y=0,int Z=0):op(OP),x(X),y(Y),z(Z){}
};
vector<CMD> V;
void Add(int x,int y,int z)
{
	assert(x>=1&&x<=5000);
	assert(y>=1&&y<=5000);
	assert(z>=1&&z<=5000);
	printf("+ %d %d %d\n",x,y,z);
	V.PB(CMD(0,x,y,z));
}
void Pow(int x,int y)
{
	assert(x>=1&&x<=5000);
	assert(y>=1&&y<=5000);
	printf("^ %d %d\n",x,y);
	V.PB(CMD(1,x,y));
}
int id_zero;
int getnew()
{
	return ++tot;
}
int add(int x,int y)
{
	int z=getnew();
	Add(x,y,z);
	return z;
}
int powd(int x)
{
	int y=getnew();
	Pow(x,y);
	return y;
}
int dup(int x)
{
	int y=add(x,id_zero);
	return y;
}
int getnum(ll c)
{
	c=((c-1)%mod+mod)%mod;
	if(c==0)c=mod;
	int x=getnew(),y=getnew();
	while(c)
	{
		if(c&1)Add(x,y,x);
		Add(y,y,y);
		c>>=1;
	}
	return x;
}
int timesk(int y,ll c)
{
	c=((c-1)%mod+mod)%mod;
	int x=dup(y);y=dup(y);
	while(c)
	{
		if(c&1)Add(x,y,x);
		Add(y,y,y);
		c>>=1;
	}
	return x;
}
int mminus(int x,int y)
{
	int z=getnew();
	Add(x,timesk(y,mod-1),z);
	return z;
}
int coef[13],C[12][12];
set<int> db;
int getpow2(int x)
{
	static int a[13];
	a[0]=x;
	for(int i=1;i<=d;i++)a[i]=add(a[i-1],getnew());
	for(int i=0;i<=d;i++)a[i]=powd(a[i]);
	int ret=dup(id_zero);
	for(int i=0;i<=d;i++)
	{
		Add(ret,timesk(a[i],coef[i]),ret);
//		db.insert(V.size()-1);
	}
	return ret;
}
void gauss(int a[13][13],int m)
{
	for(int i=0;i<m;i++)
	{
		for(int j=i;j<m;j++)
		{
			if(a[j][i]%mod!=0)
			{
				for(int t=0;t<=m;t++)swap(a[i][t],a[j][t]);
				break;
			}
		}
		assert(a[i][i]%mod!=0);
		int inv=qpow(a[i][i],mod-2);
		for(int j=0;j<=m;j++)a[i][j]=1ll*a[i][j]*inv%mod;
		for(int j=0;j<m;j++)
		{
			if(i==j)continue;
			int coef=a[j][i];
			for(int t=0;t<=m;t++)
			{
				a[j][t]=(a[j][t]-1ll*a[i][t]*coef)%mod;
			}
		}
	}
}
void prework()
{
	for(int i=0;i<=11;i++)
	{
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	}
	id_zero=getnum(mod);
	static int a[13][13];
	for(int i=0;i<=d;i++)
	{
		int pw=1;
		for(int j=d;j>=0;j--)
		{
			a[j][i]=1ll*C[d][j]*pw%mod;
			pw=1ll*pw*i%mod;
		}
	}
	for(int i=0;i<=d;i++)a[i][d+1]=(i==2);
	gauss(a,d+1);
	for(int i=0;i<=d;i++)coef[i]=a[i][d+1];
//	cerr<<"coef:"<<endl;
//	for(int i=0;i<=d;i++)cerr<<coef[i]<<" ";cerr<<endl;
}
int main()
{
	cin>>d>>mod;
	tot=2;
	prework();
	int id_x2=getpow2(1);
	int id_y2=getpow2(2);
	int id_sum2=getpow2(add(1,2));
	int targ=timesk(mminus(mminus(id_sum2,id_x2),id_y2),qpow(2,mod-2));
	printf("f %d\n",targ);
	/*
	static int a[5011];
	int times=10;
	while(times--)
	{
		for(int i=0;i<=5000;i++)a[i]=1;
		int x=(1ll*rand()*RAND_MAX+rand())%mod,y=(1ll*rand()*RAND_MAX+rand())%mod;
		a[1]=x;a[2]=y;
		cerr<<"test:"<<x<<","<<y<<endl;
		int it=0;
		for(int i=0;i<V.size();i++)
		{
			//cerr<<V[i].op<<" "<<V[i].x<<" "<<V[i].y<<" "<<V[i].z<<endl;
			bool out=db.find(i)!=db.end();
			if(V[i].op==0)
			{
				if(out)cerr<<a[V[i].x]<<"+"<<a[V[i].y]<<endl;
				a[V[i].z]=(a[V[i].x]+a[V[i].y])%mod;
				if(out)cerr<<"a["<<V[i].x<<"]+a["<<V[i].y<<"] -> "<<V[i].z<<endl;
			}
			else
			{
				if(out)cerr<<a[V[i].x]<<"^d="<<qpow(a[V[i].x],d)<<endl;
				a[V[i].y]=qpow(a[V[i].x],d);
				if(out)cerr<<"a["<<V[i].x<<"]^d -> "<<V[i].y<<endl;
			}
			
		}
		cerr<<"x:"<<a[1]<<endl;
		cerr<<"0:"<<a[id_zero]<<endl;
		cerr<<"x:"<<a[1]<<endl;
		cerr<<"y:"<<a[2]<<endl;
		cerr<<"tg:"<<a[targ]<<endl;
		cerr<<"x2:"<<a[id_x2]<<endl;
		cerr<<"y2:"<<a[id_y2]<<endl;
		cerr<<"s2:"<<a[id_sum2]<<endl;
		assert(1ll*x*y%mod==a[targ]);
	}
	*/
	return 0;
}