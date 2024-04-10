#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e2 + 5;
const int all = (1<<15) - 1;
const int ALL = all + 5;

#define bbit(i) (1ll<<(i))
#define bdig(x,i) (((x)>>(i))&1)
#define lowbit(x) ((x)&-(x))

inline ll rnd(void){ return ((ll)rand()<<15) | rand();}
inline ll rnd(ll l,ll r){ return rnd() % (r-l+1) + l;}

int tot1[ALL];
inline int count1(int x){ return tot1[x>>15] + tot1[x&all];}

int a[MAXN];
ll val[MAXN];

int main(void)
{
	srand((unsigned long long)new char);
	
	for(int i=1; i<ALL; ++i) tot1[i] = tot1[i^lowbit(i)] + 1;
	
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<i; ++j)
			if(count1(a[i]^a[j]) & 1){ printf("-1"); return 0;}
	
	for(int i=1; i<n; ++i)
	{
		ll tmp = rnd();
		val[i] += tmp;
		val[i+1] -= tmp;
	}
	
	for(int i=1; i<=500000; ++i)
	{
		int x = rnd(1,n), y = rnd(1,n);
		ll tmp = rnd();
		val[x] += tmp; val[y] -= tmp;
	}
	
	map<ll,vector<int> > t;
	for(int x=0; x<=all; ++x)
	{
		ll res = 0;
		for(int i=1; i<=n; ++i)
			res += (ll)tot1[(a[i]>>15) ^ x] * val[i];
		t[res].push_back(x);
	}
	
	for(int x=0; x<=all; ++x)
	{
		ll res = 0;
		for(int i=1; i<=n; ++i)
			res += (ll)tot1[(a[i]&all) ^ x] * val[i];
		
		if(t.find(-res) != t.end())
		{
			const vector<int> &vec = t[-res];
			for(int k=0; k<(int)vec.size(); ++k)
			{
				int ans = (vec[k]<<15) | x;
				
				int should = count1(a[1] ^ ans);
				bool flag = 1;
				for(int i=2; i<=n; ++i)
					if(count1(a[i] ^ ans) != should)
					{
						flag = 0;
						break;
					}
				if(flag)
				{
					printf("%d",ans);
					return 0;
				}
			}
		}
	}
	printf("-1");
	return 0;
}