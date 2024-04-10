#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;

set<int> pos;
multiset<int> len;

inline void add_new(int p)
{
	if(pos.empty())
	{
		pos.insert(p);
		return;
	}
	
	set<int>::iterator it = pos.lower_bound(p);
	
	if(it == pos.end())
	{
		len.insert(p - *pos.rbegin());
		pos.insert(p);
		return;
	}
	if(it == pos.begin())
	{
		len.insert(*it - p);
		pos.insert(p);
		return;
	}
	
	int nxt = *it, lst = *--it;
	len.erase(len.lower_bound(nxt - lst));
	len.insert(nxt - p);
	len.insert(p - lst);
	pos.insert(p);
}

inline void remove(int p)
{
	pos.erase(p);
	if(pos.empty()) return;
	
	set<int>::iterator it = pos.lower_bound(p);
	
	if(it == pos.end())
	{
		len.erase(len.lower_bound(p - *pos.rbegin()));
		return;
	}
	if(it == pos.begin())
	{
		len.erase(len.lower_bound(*it - p));
		return;
	}
	
	int nxt = *it, lst = *--it;
	len.erase(len.lower_bound(nxt - p));
	len.erase(len.lower_bound(p - lst));
	len.insert(nxt - lst);
}

inline int query(void)
{
	if((int)pos.size() <= 2) return 0;
	return *pos.rbegin() - *pos.begin() - *len.rbegin();
}

int main(void)
{
	int n,Q;
	static int p[MAXN];
	scanf("%d%d",&n,&Q);
	for(int i=1; i<=n; ++i) scanf("%d",&p[i]);
	
	sort(p+1,p+n+1);
	for(int i=1; i<=n; ++i) pos.insert(p[i]);
	for(int i=2; i<=n; ++i) len.insert(p[i] - p[i-1]);
	
	printf("%d\n",query());
	while(Q--)
	{
		int oper,x;
		scanf("%d%d",&oper,&x);
		if(oper == 0) remove(x);
		else add_new(x);
		printf("%d\n",query());
	}
	return 0;
}