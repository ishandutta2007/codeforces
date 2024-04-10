#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int maxn = 1e5;
const int MAXN = 1e5 + 5;
const int B = 17;
const int MAXB = B + 2;

int mu[MAXN], phi[MAXN];
ll sum_phi[MAXN];
vector<int> fac[MAXN];

namespace Divid
{
	int curl = 1, curr = 1;
	ll cur_res = 1;
	inline ll get(int l, int r)
	{
		auto getL = [&] (void)
		{
			return sum_phi[curr / curl];
		};
		
		auto getR = [&] (void)
		{
			ll res = 0;
			for (int x : fac[curr])
				if (x >= curl)
					res += phi[curr / x];
			return res;
		};
		
		while(curl > l) --curl, cur_res += getL();
		while(curr < r) ++curr, cur_res += getR();
		while(curl < l) cur_res -= getL(), ++curl;
		while(curr > r) cur_res -= getR(), --curr;
		return cur_res;
	}
}

ll f[MAXB][MAXN];

void divid(int k, int l, int r, int vl, int vr)
{
	using namespace Divid;
	if(l > r) return;
	
	int mid = (l+r)>>1;
	f[k][mid] = f[k-1][mid];
	int mni = mid;
	for(int i = min(mid - 1, vr); i >= vl; --i)
	{
		ll cur = f[k - 1][i] + get(i + 1, mid);
		if(cur < f[k][mid])
			f[k][mid] = cur, mni = i;
	}
	
	divid(k, l, mid-1, vl, mni);
	divid(k, mid+1, r, mni, vr);
}

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	if(d > B) printf("%d\n",n);
	else printf("%lld\n",f[d][n]);
}

int main(void)
{
	mu[1] = 1;
	for(int i=1; i<=maxn; ++i) phi[i] = i;
	for(int i=1; i<=maxn; ++i)
	{
		for(int j=i+i; j<=maxn; j+=i)
		{
			mu[j] -= mu[i];
			phi[j] -= phi[i];
		}
	}
	for(int i=1; i<=maxn; ++i)
		sum_phi[i] = sum_phi[i-1] + phi[i];
	
	for(int i=1; i<=maxn; ++i)
		for(int j=i; j<=maxn; j+=i)
			fac[j].push_back(i);
	
	memset(f[0], 0x3f, sizeof(f[0]));
	f[0][0] = 0;
	for(int k=1; k<=B;++k)
		divid(k, 0, maxn, 0, maxn);
	
	int T;
	scanf("%d",&T); 
	while (T--) solve();
}