#include<cstdio>
#include<cmath>
#include<iostream>
typedef long long ll;
const int MAXN = 1e5 + 5;
const int LB = 31 + 5;
using namespace std;

ll gcd(ll a,ll b){ return b? gcd(b,a%b): a;}

ll a[MAXN],p[LB];
int cnt=0,b[MAXN][LB],q[LB],can=0;

inline void gao(ll x)
{
	ll sx=sqrt(x);
	for(int i=2; i<=sx && x>1; ++i)
	{
		if(x%i==0)
		{
			p[++cnt]=i;
			while(x%i==0) ++b[0][cnt], x/=i;
		}
	}
	if(x>1)
	{
		p[++cnt]=x;
		++b[0][cnt];
	}
}

inline void ins(int pos)
{
	can=1;
	for(int i=1; i<=cnt; ++i)
	{
		q[i]+=b[pos][i];
		if(q[i]<b[0][i]) can=0;
	}
}

inline void del(int pos)
{
	can=1;
	for(int i=1; i<=cnt; ++i)
	{
		q[i]-=b[pos][i];
		if(q[i]<b[0][i]) can=0;
	}
}

int main(void)
{
	int n;
	ll k;
	cin>>n>>k;
	for(int i=1; i<=n; ++i)
	{
		cin>>a[i];
		a[i] = gcd(a[i],k);
	}
	
	gao(k);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=cnt && a[i]>1; ++j)
			while(a[i]%p[j]==0) ++b[i][j], a[i]/=p[j];
	
	ins(1);
	ll ans=0;
	for(int l=1,r=1; l<=n; ++l)
	{
		while(!can)
		{
			if(++r>n) break;
			ins(r);
		}
		if(r>n) break;
		if(r<l) r=l;
		
		ans+=(ll)n-r+1;
		//printf("%d %d\n",l,r);
		del(l);
	}
	
	cout<<ans;
	return 0;
}