#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int mod = 998244353;

int a[MAXN];

void solve(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	int ans = 0;
	
	vector<int> f, lst;
	for(int i=n; i>=1; --i)
	{
		vector<int> p,q(1,1e9);
		auto chk = [&] (int x){ return x > 0 && a[i] / x >= a[i] % x;};
		for(int j=1; j*j<=a[i]; ++j)
		{
			if(chk(j)) p.push_back(j);
			int t = a[i] / j;
			if(q.back() != t && chk(t)) q.push_back(t);
			if(q.back() != t-1 && chk(t-1)) q.push_back(t-1);
		}
		while(p.size() && q.size() && q.back() <= p.back()) q.pop_back();
		reverse(q.begin(), q.end()); q.pop_back();
		p.insert(p.end(), q.begin(), q.end());
		
		vector<int> nf(p.size());
		nf[(int)p.size() - 1] = 1;
		for(int j=0, k=0; j<(int)f.size(); ++j) if(f[j])
		{
			while(k+1<(int)p.size() && p[k+1]<lst[j]) ++k;
			if(k+1<(int)p.size() && p[k+1] == lst[j] && a[i] % p[k+1] == 0) ++k;
			
			int cur;
			if(p[k] == lst[j]) cur = a[i] / p[k];
			else cur = (a[i] + p[k]) / (p[k] + 1);
			nf[k] += f[j];
			
			ans = (ans + (ll)(cur - 1) * i %mod * f[j]) %mod;
		}
		
		swap(f, nf); swap(lst, p);
	}
	
	printf("%d\n",ans);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}