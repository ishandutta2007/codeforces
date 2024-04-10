#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int LB = 17 + 2;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;
const __int128 LLinf = (__int128)linf << 64 | linf;

int lb[MAXN];

struct Data
{
	__int128 sum;
	ll cnt;
	Data(void){ clear();}
	Data(__int128 _sum,ll _cnt): sum(_sum), cnt(_cnt) {}
	void clear(void){ sum = -LLinf; cnt = -1;}
	void upd(const Data &oth){ if(*this < oth) *this = oth;}
	bool operator < (const Data &oth) const
	{
		if(sum == oth.sum) return cnt < oth.cnt;
		else return sum < oth.sum;
	}
	Data operator + (const Data &oth) const
	{
		return Data(sum + oth.sum, cnt + oth.cnt);
	}
	Data operator - (const Data &oth) const
	{
		return Data(sum - oth.sum, cnt - oth.cnt);
	}
};

template<typename T>
struct BIT
{
	int n;
	T tree[MAXN], unit;
	function<T(T,T)> merge;
	#define lowbit(x) ((x)&-(x))
	void build(int _n,T _unit,function<T(T,T)> _merge)
	{
		n = _n; unit = _unit; merge = _merge;
		fill(tree+1, tree+n+1, unit);
	}
	void update(int x,T k)
	{
		while(x<=n)
			tree[x] = merge(tree[x], k),
			x += lowbit(x);
	}
	T query(int x)
	{
		T res = unit;
		while(x)
			res = merge(res, tree[x]),
			x ^= lowbit(x);
		return res;
	}
};

int n;
int a[MAXN];
ll sum[MAXN];

ll dsc[MAXN], dcnt = 0;
int val[MAXN];
ll premn[MAXN];

BIT<ll> vsum;
BIT<int> vcnt, vmn;
Data mx1[MAXN][LB], mx2[MAXN][LB];

Data calc(ll k)
{
	vsum.build(dcnt, 0, plus<ll>());
	vcnt.build(dcnt, 0, plus<int>());
	vmn.build(dcnt, inf, [](int x,int y){ return x<y? x: y;});
	
	Data tag = Data(0,0);
	auto insert = [&] (int i,Data fi)
	{
		fi = fi - tag;
		vsum.update(val[i], sum[i]);
		vcnt.update(val[i], 1);
		vmn.update(val[i], i);
		mx1[i][0] = fi;
		mx2[i][0] = fi + Data(-premn[i], 1);
		for(int j=1; j<=lb[i+1]; ++j)
		{
			mx1[i][j] = max(mx1[i][j-1], mx1[i-(1<<(j-1))][j-1]);
			mx2[i][j] = max(mx2[i][j-1], mx2[i-(1<<(j-1))][j-1]);
		}
	};
	auto getmx = [&] (auto mx,int l,int r)
	{
		int j = lb[r-l+1];
		return max(mx[r][j], mx[l+(1<<j)-1][j]) + tag;
	};
	
	insert(0, Data(0,0));
	for(int i=1; i<=n; ++i)
	{
		ll lim = sum[i] - k;
		int curval = upper_bound(dsc+1,dsc+dcnt+1,lim) - dsc - 1;
		
		ll tsum = vsum.query(curval);
		int tcnt = vcnt.query(curval);
		int tmn = vmn.query(curval);
		
		Data more = Data(0,0);
		if(tmn < i)
			more = Data((__int128)lim * tcnt - tsum, tcnt);
		
		Data curf;
		if(tmn <= i-1)
			curf.upd(getmx(mx1, tmn, i-1));
		if(tmn-1 >= 0)
			curf.upd(getmx(mx2, 0, min(i-1, tmn-1)) + Data(lim, 0));
		
		insert(i, curf);
		tag = tag + more;
	}
	return getmx(mx1, n, n);
}

int main(void)
{
	lb[0] = -1;
	for(int i=1; i<MAXN; ++i) lb[i] = lb[i>>1] + 1;
	
	ll d;
	scanf("%d%lld",&n,&d);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i)
	{
		sum[i] = sum[i-1] + a[i];
		premn[i] = min(premn[i-1], sum[i]);
	}
	
	for(int i=0; i<=n; ++i)
		dsc[++dcnt] = sum[i];
	sort(dsc+1,dsc+dcnt+1);
	dcnt = unique(dsc+1,dsc+dcnt+1) - dsc - 1;
	for(int i=0; i<=n; ++i)
		val[i] = lower_bound(dsc+1,dsc+dcnt+1,sum[i]) - dsc;
	
	ll l = -5e9, r = 5e9;
	while(l<r)
	{
		ll mid = l+1==r? r: (l+r)/2;
		if(calc(mid).cnt >= d) l = mid;
		else r = mid - 1;
	}
	
	ll ans = calc(l).sum + l * d;
	printf("%lld",ans);
	return 0;
}