#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;
const int MAXL = 5.3e5 + 5;
const int mod = 998244353;

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

namespace NTT
{
	const int g = 3;
	int omega[MAXL];
	
	inline void ntt(int n,int a[],bool rev = 0)
	{
		for(int i=0,j=0; i<n; ++i)
		{
			if(i>j) swap(a[i], a[j]);
			for(int k=n>>1; (j^=k) < k; k>>=1);
		}
		for(int len=2, step=n>>1; len<=n; len<<=1, step>>=1)
			for(int i=0, k=len>>1; i<n; i+=len)
				for(int j=i, cur=0; j < i+k; ++j, cur+=step)
				{
					ll tmp = (ll)omega[rev? n-cur: cur] * a[j+k];
					a[j+k] = (a[j] - tmp) %mod; a[j] = (a[j] + tmp) %mod;
				}
	}
	
	void mul(int n_,int a_[],int m_,int b_[],int res[])
	{
		int n = 1;
		while(n < n_ + m_ - 1) n <<= 1;
		static int a[MAXL], b[MAXL];
		for(int i=0; i<n_; ++i) a[i] = a_[i];
		for(int i=n_; i<n; ++i) a[i] = 0;
		for(int i=0; i<m_; ++i) b[i] = b_[i];
		for(int i=m_; i<n; ++i) b[i] = 0;
		
		static int lst_n = -1;
		if(n != lst_n)
		{
			lst_n = n;
			omega[0] = omega[n] = 1; omega[1] = pw(g, (mod-1)/n);
			for(int i=2; i<n; ++i) omega[i] = (ll)omega[i-1] * omega[1] %mod;
		}
		
		ntt(n,a); ntt(n,b);
		for(int i=0; i<n; ++i) res[i] = (ll)a[i] * b[i] %mod;
		ntt(n,res,1);
		ll invn = pw(n,mod-2);
		for(int i=0; i<n; ++i)
		{
			res[i] = res[i] * invn %mod;
			if(res[i] < 0) res[i] += mod;
		}
	}
}

int n,m,d;
char s[MAXN], t[MAXM];

int res[MAXN];
void get_res(char c)
{
	static int fob[MAXL];
	memset(fob,0,sizeof(fob));
	for(int i=1; i<=n; ++i) if(s[i] == c)
		++fob[max(i - d, 1)],
		--fob[min(i + d + 1, n+1)];
	fob[n+1] = 0; 
	for(int i=1; i<=n; ++i) fob[i] += fob[i-1];
	for(int i=1; i<=n; ++i) fob[i] = !fob[i];
	reverse(fob, fob+n+1);
	
	static int shift[MAXM];
	memset(shift,0,sizeof(shift));
	for(int i=1; i<=m; ++i) if(t[i] == c)
		shift[i-1] = 1;
	
	NTT::mul(m, shift, n, fob, fob);
	for(int i=1; i<=n; ++i)
		if(fob[n-i]) res[i] = 1;
}

int main(void)
{
	scanf("%d%d%d%s%s",&n,&m,&d,s+1,t+1);
	
	get_res('A'); get_res('T'); get_res('G'); get_res('C');
	
	int ans = 0;
	for(int i=1; i+m-1<=n; ++i)
		if(!res[i]) ++ans;
	printf("%d",ans);
	return 0;
}