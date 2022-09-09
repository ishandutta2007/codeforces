#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXD = 5 + 5;
const int MAXN = (1<<5) + 5;
const int mod = 998244353;

inline void add_mod(int &a,int b){ a+=b; if(a>=mod) a-=mod;}
inline int mod_add(int a,int b){ return a+b>=mod? a+b-mod: a+b;}

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

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)

ll pwA[MAXN], invA;

inline vector<int> decode(int mask,int n)
{
	vector<int> res(n, 1), id(n);
	for(int i=0; i<n; ++i) id[i] = i;
	while((int)id.size() > 1)
	{
		vector<int> lst; swap(id, lst);
		for(int i=0; i<(int)lst.size(); i+=2)
		{
			int u = lst[i], v = lst[i+1];
			if(mask & 1) swap(u, v);
			mask >>= 1;
			res[v] = (int)lst.size();
			id.push_back(u);
		}
	}
	return res;
}

void get_f(int n,int beg,unordered_map<int,int> f[])
{
	int all = (1<<(n - 1)) - 1;
	for(int mask=0; mask<=all; ++mask)
	{
		vector<int> rnk = decode(mask, n);
		int hd = find(rnk.begin(), rnk.end(), 1) - rnk.begin();
		int sum = 0;
		for(int i=0; i<n; ++i)
			sum = (sum + (i + beg + 1) * pwA[rnk[i]]) %mod;
		f[0][sum] = f[hd + 1][sum] = mask;
	}
}

int A, H;

inline void chk_res(int n,int begf,int begg,unordered_map<int,int> f[], unordered_map<int,int> g[])
{
	for(int i=1; i<=n; ++i)
		for(auto x: f[i])
		{
			int val = ((ll)x.first - (ll)A * (i + begf) %mod + (i + begf) + mod) %mod;
			int need = mod_add(H, mod - val);
			if(g[0].find(need) == g[0].end()) continue;
			
			int maskf = x.second;
			int maskg = g[0][need];
			vector<int> rnkf = decode(maskf, n);
			vector<int> rnkg = decode(maskg, n);
			
			vector<int> rnk(n * 2);
			for(int j=0; j<n; ++j) rnk[j + begf] = rnkf[j];
			for(int j=0; j<n; ++j) rnk[j + begg] = rnkg[j];
			rnk[i + begf - 1] = 0;
			
			for(auto t: rnk) printf("%d ",t+1);
			exit(0);
		}
}

int main(void)
{
	int d;
	scanf("%d%d%d",&d,&A,&H);
	int n = 1 << d;
	
	pwA[0] = 1;
	for(int i=1; i<MAXN; ++i) pwA[i] = pwA[i-1] * A %mod;
	
	invA = pw(A, mod - 2);
	H = H * invA %mod;
	
	int half = n / 2;
	
	static unordered_map<int,int> f[MAXN], g[MAXN];
	get_f(half, 0, f);
	get_f(half, half, g);
	
	chk_res(half, 0, half, f, g);
	chk_res(half, half, 0, g, f);
	
	printf("-1");
	return 0;
}