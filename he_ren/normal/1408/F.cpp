#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1.5e4 + 5;

#define bbit(i) (1ll<<(i))
#define bdig(x,i) (((x)>>(i))&1)

int n;
vector<pii> ans;
inline void push_ans(int x,int y){ ans.push_back(make_pair(x,y));}

void merge(int len)
{
	for(int i=1; i+len*2-1 <= n; i+=len*2)
		for(int j=1; j<=len; ++j)
			push_ans(i+j-1, i+len+j-1);
}

int nxt[MAXN];

struct Seg
{
	int beg,len;
};
inline bool operator < (const Seg &p,const Seg &q){ return p.len == q.len? p.beg < q.beg: p.len < q.len;}

void merge(Seg &p,Seg &q)
{
	int len = p.len;
	
	int x = p.beg, y = q.beg;
	for(int i=1; i<=len; ++i)
	{
		push_ans(x, y);
		if(i < len)
			x = nxt[x], y = nxt[y];
	}
	
	nxt[x] = q.beg;
	p.len *= 2;
	
	q.beg = nxt[y];
	q.len -= p.len;
	nxt[y] = y;
}

int main(void)
{
	scanf("%d",&n);
	
	for(int i=0; (1<<i)*2 <= n; ++i)
		merge(1<<i);
	
	vector<Seg> t;
	
	for(int i=1; i<=n; ++i) nxt[i] = i;
	
	int r = n;
	for(int i=0; i<=20; ++i)
		if(bdig(n,i))
		{
			int l = r - (1<<i) + 1;
			for(int j=l; j<r; ++j) nxt[j] = j+1;
			
			t.push_back((Seg){l, (1<<i)});
			r -= (1<<i);
		}
	
	Seg big = t.back();
	t.pop_back();
	
	for(int i=0; i<(int)t.size()-1; ++i)
	{
		if(t[i].len == t[i+1].len)
		{
			merge(t[i], t[i+1]);
			t[i+1] = t[i];
			continue;
		}
		
		merge(t[i], big);
		--i;
	}
	
	printf("%d\n",(int)ans.size());
	for(int i=0; i<(int)ans.size(); ++i)
		printf("%d %d\n",ans[i].first,ans[i].second);
	return 0;
}