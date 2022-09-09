#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXL = 2e5 + 5;
const int LB = 19 + 2;
const int inf = 0x3f3f3f3f;

int lb[MAXL];

struct BIT
{
	int tree[MAXL],n;
	#define lowbit(x) ((x)&-(x))
	inline void clear(int _n){ n = _n; memset(tree,0,(n+1)<<2);}
	inline void update(int x,int k)
	{
		while(x<=n)
			tree[x] += k,
			x += lowbit(x);
	}
	inline int query(int x)
	{
		int res=0;
		while(x)
			res += tree[x],
			x ^= lowbit(x);
		return res;
	}
	inline int query(int l,int r){ return query(r) - query(l-1);}
};

struct Counter
{
	int n;
	vector<int> p[MAXL];
	vector< pair<pii,int> > q[MAXL];
	BIT tree;
	inline void clear(int _n)
	{
		n = _n;
		for(int i=0; i<=n; ++i) p[i].clear(), q[i].clear();
	}
	inline void insert(int x,int y)
	{
		p[x].push_back(y);
	}
	inline void query(int xl,int xr,int yl,int yr)
	{
		q[xr].push_back(make_pair(make_pair(yl, yr), 1));
		q[xl-1].push_back(make_pair(make_pair(yl, yr), -1));
	}
	inline ll build(void)
	{
		ll res = 0;
		tree.clear(n);
		for(int i=1; i<=n; ++i)
		{
			for(int j=0; j<(int)p[i].size(); ++j)
				tree.update(p[i][j], 1);
			for(int j=0; j<(int)q[i].size(); ++j)
				res += tree.query(q[i][j].first.first, q[i][j].first.second) * q[i][j].second;
		}
		return res;
	}
};

struct SA
{
	int _rnk1[MAXL], _rnk2[MAXL];
	int n, sa[MAXL], *rnk, *lst_rnk, sa_k;
	int lcp[MAXL], st[MAXL][LB];
	SA(void): rnk(_rnk1), lst_rnk(_rnk2) {}
	inline bool sa_same(int x,int y){ return lst_rnk[x] == lst_rnk[y] && lst_rnk[x + sa_k] == lst_rnk[y + sa_k];}
	void build(char s[],int _n)
	{
		int m = 3e2; n = _n;
		static int t[MAXL];
		memset(t,0,(m+1)<<2); rnk[0] = lst_rnk[0] = rnk[n+1] = lst_rnk[n+1] = 0;
		for(int i=1; i<=n; ++i) ++t[rnk[i] = s[i]];
		for(int i=1; i<=m; ++i) t[i] += t[i-1];
		for(int i=n; i>=1; --i) sa[t[rnk[i]]--] = i;
		if(n == 1){ rnk[1] = sa[1] = 1; return;}
		if(m == n) ++m;
		for(int &k=sa_k=1; m!=n; k<<=1)
		{
			static int id[MAXL];
			int *w = lst_rnk, cur = 0;
			for(int i=n-k+1; i<=n; ++i) id[++cur] = i;
			for(int i=1; i<=n; ++i) if(sa[i] > k) id[++cur] = sa[i] - k;
			
			memset(t,0,(m+1)<<2);
			for(int i=1; i<=n; ++i) ++t[w[i] = rnk[id[i]]];
			for(int i=1; i<=m; ++i) t[i] += t[i-1];
			for(int i=n; i>=1; --i) sa[t[w[i]]--] = id[i];
			
			m = 0;
			swap(rnk, lst_rnk);
			for(int i=1; i<=n; ++i)
				rnk[sa[i]] = sa_same(sa[i], sa[i-1])? m: ++m;
		}
		
		for(int i=1,k=0; i<=n; ++i)
		{
			if(rnk[i] == n){ lcp[n] = k = 0; continue;}
			if(k) --k;
			int j = sa[rnk[i]+1];
			while(s[i+k] == s[j+k]) ++k;
			lcp[rnk[i]] = k;
		}
		
		for(int i=n; i>=1; --i)
		{
			st[i][0] = lcp[i];
			for(int j=1; i+(1<<j)-1 <= n; ++j)
				st[i][j] = min(st[i][j-1], st[i+(1<<(j-1))][j-1]);
		}
	}
	inline int get_mn(int l,int r){ int k = lb[r-l+1]; return min(st[l][k], st[r-(1<<k)+1][k]);}
	inline int get_lcp(int x,int y)
	{
		if(x == y) return inf;
		x = rnk[x]; y = rnk[y];
		return x < y? get_mn(x,y): get_mn(y,x);
	}
	inline pii get_rng(int x,int k)
	{
		x = rnk[x];
		int l = x, r = x;
		for(int i=lb[l-1]; i>=0; --i)
			if(i <= lb[l-1] && st[l-(1<<i)][i] >= k)
				l -= 1<<i;
		for(int i=lb[n-r]; i>=0; --i)
			if(i <= lb[n-r] && st[r][i] >= k)
				r += 1<<i;
		return make_pair(l,r);
	}
}pref, suff;

static char a[MAXL], b[MAXL];
int bega[MAXN], begb[MAXN];

ll get_res(string s[],int n)
{
//	printf("solve:(%d)\n",n);
//	for(int i=1; i<=n; ++i)
//		cout << s[i] << endl;
	
	int tot = 0;
	for(int i=1; i<=n; ++i)
	{
		bega[i] = tot + 1;
		for(int j=0; j<(int)s[i].size(); ++j)
			a[++tot] = s[i][j];
	}
	a[tot+1] = 0;
	
	tot = 0;
	for(int i=1; i<=n; ++i)
	{
		begb[i] = tot + 1;
		for(int j=(int)s[i].size()-1; j>=0; --j)
			b[++tot] = s[i][j];
	}
	b[tot+1] = 0;
	
	pref.build(a, tot);
	suff.build(b, tot);
	
	static Counter cnter;
	cnter.clear(tot);
	
	for(int i=1; i<=n; ++i)
		cnter.insert(pref.rnk[bega[i]], suff.rnk[begb[i]]);
//		printf("%d: (%d, %d)\n",i,pref.rnk[bega[i]], suff.rnk[begb[i]]);
	
//	printf("sa:\n");
//	for(int i=1; i<=tot; ++i)
//	{
//		printf("%d: %2d %2d %2d  ",i, pref.sa[i], pref.rnk[pref.sa[i]], pref.lcp[i]);
//		for(int j=pref.sa[i]; j<=tot; ++j) putchar(a[j]);
//		printf("\n");
//	}
	
	ll res = 0;
	for(int i=1; i<=n; ++i)
	{
		for(int l=0,r=0; l<(int)s[i].size(); l=r)
		{
			r = l+1;
			while(r < (int)s[i].size() && s[i][r] >= s[i][r-1]) ++r;
			--res;
			
//			printf("i = %d, l = %d, r = %d\n",i,l,r);
			
			pii rnga = pref.get_rng(bega[i], l);
			pii rngb = suff.get_rng(begb[i], (int)s[i].size() - r);
			
//			printf("query: %d %d %d %d\n",rnga.first, rnga.second, rngb.first, rngb.second);
			
			cnter.query(rnga.first, rnga.second, rngb.first, rngb.second);
		}
	}
	
	res += cnter.build();
	
//	printf("res = %lld\n",res);
	
	return res + (ll)(n * (n-1) / 2 - res) * 2;
}

inline pii get_hash(const string &s)
{
	static const int mod1 = 1e9 + 7;
	static const int mod2 = 998244353;
	static const int base1 = 20210605;
	static const int base2 = 19491001;
	
	static int t[30];
	memset(t,0,sizeof(t));
	for(int i=0; i<(int)s.size(); ++i) ++t[s[i] - 'a'];
	
	int res1 = 0, res2 = 0;
	for(int i=0; i<26; ++i)
		res1 = ((ll)res1 * base1 + t[i]) %mod1,
		res2 = ((ll)res2 * base2 + t[i]) %mod2;
	return make_pair(res1, res2);
}

string s[MAXN];

int main(void)
{
	lb[0] = -1;
	for(int i=1; i<MAXL; ++i) lb[i] = lb[i>>1] + 1;
	
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) cin >> s[i];
	
	static pair<pii,int> p[MAXN];
	for(int i=1; i<=n; ++i) p[i] = make_pair(get_hash(s[i]), i);
	sort(p+1,p+n+1);
	
	static string t[MAXN];
	for(int i=1; i<=n; ++i) t[i] = s[p[i].second];
	
	ll ans = 0;
	int cur = 0;
	for(int i=1,j=1; i<=n; i=j)
	{
		while(j<=n && p[i].first == p[j].first) ++j;
		ans += (ll)(j - i) * cur * 1337;
		cur += j - i;
		ans += get_res(t+i-1, j-i);
	}
	
	printf("%lld",ans);
	return 0;
}