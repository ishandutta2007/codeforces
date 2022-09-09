#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXM = 50 + 5;
const int mod = 998244353;
const ll inv2 = (mod+1)/2;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}

inline ll pw(ll a,ll b)
{
	ll res = 1;
	while(b)
	{
		if(b&1) res=res*a%mod;
		a=a*a%mod; b>>=1;
	}
	return res;
}

namespace Poly
{
	const int N = 524288;
	const int g = 3;
	int omega[N];
	void init(void)
	{
		ll pwg = pw(g, (mod-1)/N);
		omega[0] = 1;
		for(int i=1; i<N; ++i)
			omega[i] = omega[i-1] * pwg %mod;
	}
	void dft(int *a,int n)
	{
		for(int i=0,j=0; i<n; ++i)
		{
			if(i<j) swap(a[i], a[j]);
			for(int k=n>>1; (j^=k)<k; k>>=1);
		}
		for(int k=1,step=N>>1; k<n; k<<=1, step>>=1)
			for(int i=0; i<n; i+=k<<1)
				for(int j=i,cur=0; j<i+k; ++j, cur+=step)
				{
					int tmp = (ll)a[j+k] * omega[cur] %mod;
					add_mod(a[j+k]=a[j], mod-tmp); add_mod(a[j], tmp);
				}
	}
	void idft(int *a,int n)
	{
		dft(a,n); reverse(a+1,a+n);
		ll ivn = 1;
		for(int i=1; i<n; i<<=1)
			ivn = ivn * inv2 %mod;
		for(int i=0; i<n; ++i)
			a[i] = a[i] * ivn %mod;
	}
	
	int a[N], b[N];
	vector<int> mul(const vector<int> &A,const vector<int> &B)
	{
		if(!A.size() || !B.size()) return {};
		vector<int> res((int)A.size() + (int)B.size() - 1);
		int n = 1; while(n < (int)res.size()) n <<= 1;
		for(int i=0; i<n; ++i)
			a[i] = i<(int)A.size()? A[i]: 0;
		for(int i=0; i<n; ++i)
			b[i] = i<(int)B.size()? B[i]: 0;
		dft(a,n); dft(b,n);
		for(int i=0; i<n; ++i)
			a[i] = (ll)a[i] * b[i] %mod;
		idft(a,n);
		for(int i=0; i<(int)res.size(); ++i)
			res[i] = a[i];
		return res;
	}
} using Poly::mul;

int main(void)
{
	Poly::init();
	
	int n,d,need;
	scanf("%d%d%d",&n,&d,&need);
	
	vector<int> F(d+1, 1);
	for(int i=1; i<n; ++i)
	{
		F = mul(F, F);
		int sum = 0;
		for(int j=(int)F.size()-1; j>=0; --j)
		{
			add_mod(sum, F[j]);
			if(j <= d)
				F[j] = ((ll)F[j] * (d-j) + sum) %mod;
		}
		F.resize(d+1);
	}
	
	F = mul(F, F);
	F.resize(need+1);
	printf("%d",F[need]);
	return 0;
}