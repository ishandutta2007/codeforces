#include <cstdio>
#include <cassert>
#include <map>
#include <set>
#include <vector>

using ll = long long;
const int MN = 5e5+10;
int N, P, Q, R;

bool QT;
struct qry
{
public:
	int q;
	mutable int r;
	bool operator < (qry o) const {return QT?r > o.r:q < o.q;}
};
std::vector<qry> a[MN];
std::multiset<int> mq, mr;
int mQ, mR;
std::set<qry> rule;
ll f, ans;

int fq(int v){return v>mQ?v:mQ;}
int fr(int v){return v>mR?v:mR;}
void tog(qry x)
{
	//erase q, r
	{//q
		int q=x.q;
		mq.erase(mq.find(q));
		mQ = *mq.rbegin();
		if(q>mQ)
		{
			int v=mQ;
			for(auto it=rule.upper_bound({v, 0});v<q;++it)
			{
				f += (ll)(std::min(q, it->q)-v)*(R-fr(it->r));
				v=it->q;
			}
		}
	}
	{//r
		int r=x.r;
		mr.erase(mr.find(r));
		mR = *mr.rbegin();
		if(r>mR)
		{
			QT=1;
			int v=mR;
			for(auto it=rule.lower_bound({0, v});v<r;)
			{
				--it;
				f += (ll)(Q-fq(it->q))*(std::min(r, it->r)-v);
				v=it->r;
			}
			QT=0;
		}
	}

	auto it=rule.lower_bound(x), n=rule.end(), pr=rule.end();
	if(it->r < x.r) assert(it != rule.begin());
	if(it->r >= x.r) return;// otherwise assert it != start
	else if(it->q == x.q)
		pr=std::prev(it), f -= (ll)(fq(it->q)-fq(pr->q))*(fr(x.r)-fr(it->r)), it->r = x.r;
	else
		pr=std::prev(it), f -= (ll)(fq(x.q)-fq(pr->q))*(fr(x.r)-fr(it->r)), it = rule.insert(x).first;

	for(;it != rule.begin() && (pr=std::prev(it))->r <= it->r;rule.erase(n))
	{
		n=pr;
		if(it->r!=n->r)
			--pr, f -= (ll)(fq(n->q)-fq(pr->q))*(fr(it->r)-fr(n->r));
		else
		{
			rule.erase(n);
			break;
		}
	}
}
int main()
{
	scanf("%d%d%d%d", &N, &P, &Q, &R);
	for(int i=0,a,b,c;i<N;++i)
		scanf("%d%d%d", &a,&b,&c), ::a[a].push_back({b,c}), mq.insert(b), mr.insert(c);
	rule.insert({0, R});//this can be replaced/removed by something, but second point must be R
	rule.insert({Q, 0});//this can be replaced later on, but first point must be Q
	mq.insert(0); mr.insert(0);
	mQ=*mq.rbegin(), mR=*mr.rbegin();
	f = (ll)(Q-mQ)*(R-mR);
	//printf("initial f: %lld\n", f);
	for(int p=1;p<=P;++p)
	{
		//printf("MIN: %d %d\n", mQ, mR);
		//printf("%d: %lld\n", p, f);
		ans+=f;
		for(auto x:a[p])
			tog(x);
	}
	printf("%lld\n", ans);
	return 0;
}