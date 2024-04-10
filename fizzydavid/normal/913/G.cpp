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
ll qmul(ll x,ll y,ll md)
{
	ll ret=x*y-ll((long double)1.0*x/md*y)*md;
	while(ret>=md)ret-=md;
	while(ret<0)ret+=md;
	return ret;
}
ll qpow(ll x,ll k,ll md){return k==0?1%md:qmul(qpow(qmul(x,x,md),k>>1,md),(k&1?x:1),md);}
int n;
ll tab[5]={-1,0,1,3,2};
int main()
{
	int Tn;
	cin>>Tn;
	while(Tn--)
	{
		ll X;
		cin>>X;
		X=X*10000000;
		ll x=X/262144+1;
		if(x%5==0)x++;
		ll md=5,ans=tab[int(x%5)];
		for(int i=1;i<18;i++)
		{
			md=md*5;
			for(int j=0;j<5;j++)
			{
				ll tmp=md/25*4*j+ans;
				if(qpow(2,tmp,md)==x%md)
				{
					ans=tmp;
					break;
				}
			}
		}
		ll Ans=ans+18;
		cout<<Ans<<endl;
//		cerr<<qpow(2,Ans,1000000000000000000ll);
	}
	return 0;
}