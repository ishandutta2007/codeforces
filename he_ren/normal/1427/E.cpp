#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cassert>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int lb = 63;
const int LB = lb + 5;
const ll mx_num = 5e18;

#define bbit(i) (1ll<<(i))
#define bdig(x,i) (((x)>>(i))&1)

inline int rnd(void){ return rand()<<15 | rand();}

set<ll> t;
vector<ll> num;
inline bool push(ll x)
{
	if(t.find(x) != t.end()) return 0;
	t.insert(x); num.push_back(x);
	return 1;
}

vector<pll> ans;
vector<bool> oper;
inline bool push_xor(ll x,ll y){ if(push(x^y)) ans.push_back(make_pair(x,y)), oper.push_back(0); return (x^y)==1;}
inline bool push_add(ll x,ll y){ if(push(x+y)) ans.push_back(make_pair(x,y)), oper.push_back(1); return (x+y)==1;}

inline ll rnd_num(void){ return num[rnd()%(int)num.size()];}

ll a[LB];

void insert(ll x)
{
	for(int k=lb; k>=0 && x; --k)
	{
		if(!bdig(x,k)) continue;
		if(a[k])
		{
			if(push_xor(a[k], x)) return;
			x ^= a[k];
			continue;
		}
		
		for(int i=0; i<k; ++i)
			if(a[i] && bdig(x, i))
			{
				if(push_xor(a[i], x)) return;
				x ^= a[i];
			}
		for(int i=k+1; i<=lb; ++i)
			if(bdig(a[i], k))
			{
				if(push_xor(a[i], x)) return;
				a[i] ^= x;
			}
		
		a[k] = x;
		push(x);
		return;
	}
}

int main(void)
{
	srand((unsigned long long)new char);
	
	int x;
	scanf("%d",&x);
	
	push(x);
	
	ll xx = x;
	while(xx <= mx_num/2)
	{
		if(push_add(xx,xx)) break;
		xx *= 2;
	}
	
	while(t.find(1) == t.end())
	{
		ll p = rnd_num(), q = rnd_num();
		
		if(rand()%4)
		{
			if(p > mx_num-q) continue;
			if(push_add(p, q)) break;
			insert(p+q);
		}
		else
		{
			if((p^q) > mx_num) continue;
			if(push_xor(p, q)) break;
			insert(p^q);
		}
	}
	
	assert((int)ans.size() <= 100000);
	assert(t.find(1) != t.end());
	
	t.clear(); t.insert(x);
	for(int i=0; i<(int)ans.size(); ++i)
	{
		ll a = ans[i].first, b = ans[i].second;
		
		if(oper[i]) t.insert(a+b);
		else t.insert(a^b);
		
		if(t.find(1) != t.end())
		{
			ans.resize(i+1);
			break;
		}
	}
	
	printf("%d\n",(int)ans.size());
	for(int i=0; i<(int)ans.size(); ++i)
	{
		ll a = ans[i].first, b = ans[i].second;
		printf("%lld %c %lld\n",a,oper[i]? '+': '^',b);
	}
	
	return 0;
}