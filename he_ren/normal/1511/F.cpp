#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 8 + 5;
const int MAXL = 5 + 5;
const int mod = 998244353;

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

vector<int> Berlekamp_Massey(const vector<int> &a)
{
	int n = (int)a.size(), d = 0, ld = 1, len = 0, m = 0;
	vector<int> res(n), lst(n), tmp;
	res[0] = 1;
	for(int i=0; i<n; ++i)
	{
		++m; d = 0;
		for(int j=0; j<=len; ++j)
			d = (d + (ll)res[j] * a[i-j]) %mod;
		if(d == 0) continue;
		tmp = res;
		ll k = (ll)pw(ld, mod-2) * d %mod;
		for(int j=m; j<n; ++j)
			res[j] = (res[j] - (ll)k * lst[j-m]) %mod;
		if(len >= i-len+1) continue;
		len = i-len+1; lst = tmp; ld = d; m = 0;
	}
	res.resize(len+1); res.erase(res.begin());
	for(int i=0; i<len; ++i)
		add_mod(res[i] = -res[i], mod);
	return res;
}

namespace Linear_Rec
{
	inline vector<int> combine(const vector<int> &a,const vector<int> &b,const vector<int> &tr)
	{
		vector<int> res((int)a.size() + (int)b.size() - 1);
		for(int i=0; i<(int)a.size(); ++i)
			for(int j=0; j<(int)b.size(); ++j)
				res[i+j] = (res[i+j] + (ll)a[i] * b[j]) %mod;
		for(int i=(int)res.size()-1; i>=(int)tr.size(); --i)
			for(int j=0; j<(int)tr.size(); ++j)
				add_mod(res[i - j - 1], (ll)res[i] * tr[j] %mod);
		res.resize(tr.size());
		return res;
	}
}

inline int linear_rec(const vector<int> &s,const vector<int> &tr,int k)
{
	using namespace Linear_Rec;
	
	int n = (int)tr.size();
	vector<int> res(n), a(n);
	res[0] = a[1] = 1;
	while(k)
	{
		if(k&1) res=combine(res,a,tr);
		a=combine(a,a,tr); k>>=1;
	}
	
	int ans = 0;
	for(int i=0; i<(int)tr.size(); ++i)
		ans = (ans + (ll)res[i] * s[i]) %mod;
	return ans;
}

char s[MAXN][MAXL];
int len[MAXN];

const int lim = 2e2;
const int LIM = lim + 5;

int f[LIM][MAXN][MAXL];
vector< pair<int,pii> > to[MAXN][MAXL];

inline bool chk_suf(int x,int l,int y)
{
	for(int i=len[x]-l+1, j=1; i<=len[x] && j<=len[y]; ++i, ++j)
		if(s[x][i] != s[y][j]) return 0;
	return 1;
}

inline pair<int,pii> get_nxt(int x,int xl,int y,int yl)
{
	if(xl == yl)
		return make_pair(xl, make_pair(0, 0));
	else if(xl < yl)
		return make_pair(xl, make_pair(y, yl - xl));
	else
		return make_pair(yl, make_pair(x, xl - yl));
}

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i)
		scanf("%s",s[i]+1), len[i] = strlen(s[i] + 1);
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<len[i]; ++j)
			for(int k=1; k<=n; ++k) if(chk_suf(i,j,k))
				to[i][j].push_back(get_nxt(i, j, k, len[k]));
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j) if(chk_suf(i,len[i],j))
			to[0][0].push_back(get_nxt(i, len[i], j, len[j]));
	
	f[0][0][0] = 1;
	for(int i=0; i<lim; ++i)
		for(int j=0; j<=n; ++j)
		{
			int kl = j? 1: 0, kr = j? len[j]-1: 0;
			for(int k=kl; k<=kr; ++k) if(f[i][j][k])
			{
				vector< pair<int,pii> > &vec = to[j][k];
				for(int it=0; it<(int)vec.size(); ++it)
				{
					int ii = i + vec[it].first, jj = vec[it].second.first, kk = vec[it].second.second;
					if(ii < lim)
						add_mod(f[ii][jj][kk], f[i][j][k]);
				}
			}
		}
	vector<int> g(lim);
	for(int i=0; i<lim; ++i) g[i] = f[i][0][0];
	
	printf("%d",linear_rec(g, Berlekamp_Massey(g), m));
	return 0;
}