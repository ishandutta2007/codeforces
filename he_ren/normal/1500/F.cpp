#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e6 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

inline ll read(void)
{
	ll res = 0;
	char c = getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9') res=res*10+c-'0', c = getchar();
	return res;
}

int n;
ll a[MAXN], mxa, res[MAXN];

deque<ll> q;

struct Tag
{
	ll l,r,add,val;
	bool rev;
	int type;
	inline bool empty(void) const { return l > r && !q.size();}
	inline void set_seg(ll _l,ll _r)
	{
		l = _l; r = _r;
		rev = 0; add = 0; type = 0;
		q.clear();
	}
	inline ll get_mx(void) const
	{
		ll mx = -linf;
		if(l <= r) mx = r;
		if(q.size()) mx = max(mx, rev? -q.front() + add: q.back() + add);
		return mx;
	}
	inline void upd_tag(ll k)
	{
		l = k - l; r = k - r; swap(l, r);
		rev ^= 1; add = k - add;
	}
	inline void print(void) const
	{
		vector<ll> vec;
		for(int i=0; i<(int)q.size(); ++i)
			vec.push_back(rev? -q[i] + add: q[i] + add);
		if(vec.size() && vec.front() > vec.back())
			reverse(vec.begin(), vec.end());
		
		int ii = 0;
		while(ii < (int)vec.size() && vec[ii] < l)
			printf("%lld ",vec[ii++]);
		if(l <= r) for(ll k=l; k<=r; ++k) printf("%lld ",k);
		while(ii < (int)vec.size())
			printf("%lld ",vec[ii++]);
	}
	inline void trans(ll k)
	{
		r = min(r, k);
		if(rev)
			while(q.size() && -q.front() + add > k) q.pop_front();
		else
			while(q.size() && q.back() + add > k) q.pop_back();
		if(empty()) printf("NO"), exit(0);
		
		val = get_mx();
		if(val == k){ set_seg(0, k); type = 3; return;}
		
		upd_tag(k);
		if(get_mx() != k)
		{
			if(rev) q.push_front(-(k - add)), type = 1;
			else q.push_back(k - add), type = 2;
		}
		else type = 4;
	}
}tag[MAXN];

int main(void)
{
	n = read(); mxa = read();
	for(int i=3; i<=n; ++i) a[i] = read();
	
	tag[2].set_seg(0, 1e18);
	for(int i=3; i<=n; ++i)
	{
		tag[i] = tag[i-1];
		tag[i].trans(a[i]);
		if(tag[i].empty())
			return printf("NO"), 0;
	}
	
	res[n] = tag[n].get_mx();
	for(int i=n-1; i>=2; --i)
	{
		ll pre = res[i+1];
		int type = tag[i+1].type;
		
		if(type == 3)
			res[i] = -a[i+1];
		else if(abs(pre) == a[i+1] && type != 4)
			res[i] = -tag[i+1].val;
		else
			res[i] = a[i+1] - abs(pre);
		
		if(pre < 0) res[i] = -res[i];
	}
	
	for(int i=2; i<=n; ++i) res[i] += res[i-1];
	printf("YES\n");
	ll mn = *min_element(res+1,res+n+1);
	for(int i=1; i<=n; ++i) printf("%lld ",res[i] - mn);
	return 0;
}