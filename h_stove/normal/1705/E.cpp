//114514min
//ACM 
#include "bits/stdc++.h"
using namespace std;
template<typename typC,typename typD> istream & operator>>(istream &cin,pair<typC,typD> &a) {return cin>>a.first>>a.second;}
template<typename typC> istream & operator>>(istream &cin,vector<typC> &a){for (auto &x:a) cin>>x;return cin;}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const pair<typC,typD> &a) {return cout<<a.first<<' '<<a.second;}
template<typename typC,typename typD> ostream & operator<<(ostream &cout,const vector<pair<typC,typD>> &a){for (auto &x:a) cout<<x<<'\n';return cout;}
template<typename typC> ostream & operator<<(ostream &cout,const vector<typC> &a){int n=a.size();if (!n) return cout;cout<<a[0];for (int i=1;i<n;i++) cout<<' '<<a[i];return cout;}
#if !defined(ONLINE_JUDGE)&&defined(LOCAL)
#include "my_header\debug.h"
#else
#define dbg(...) ;
#define dbgn(...) ;
#endif
typedef unsigned int ui;
typedef long long ll;
#define all(x) (x).begin(),(x).end()
const int N=1e6+5;
int a[N],b[N];
#define all(x) (x).begin(),(x).end()
multiset<int> ss;
namespace chtholly_tree
{
	typedef int TT;
	struct Q
	{
		int l;
		mutable int r;
		mutable TT v;
		int len() const {return r-l+1;}
		bool operator<(const Q &x) const {return l<x.l;}
	};
	class odt: public set<Q>
	{
	public:
		typedef odt::iterator iter;
		iter split(int x)
		{
			iter it=lower_bound({x});
			if (it!=end()&&it->l==x) return it;
			Q t=*--it,a={t.l,x-1,t.v},b={x,t.r,t.v};
			erase(it);insert(a);
			return insert(b).first;
		}
		void modify(int l,int r,TT v)//[l,r]
		{
			iter lt,rt,it;
			rt=split(r+1);lt=split(l);//[lt,rt)
			while (lt!=begin()&&(it=prev(lt))->v==v) l=(lt=it)->l;
			while (rt!=end()&&rt->v==v) r=(rt++)->r;
			erase(lt,rt);insert({l,r,v});
		}
		void add(int x)
		{
			auto it=prev(upper_bound({x,x,0}));
			if (it->v==1)
			{
				int r=it->r;
				modify(x,r,0);
				modify(r+1,r+1,1);
			}
			else
			{
				modify(x,x,1);
			}
		}
		void del(int x)
		{
			auto it=prev(upper_bound({x,x,0}));
			if (it->v==0)
			{
				int r=it->r;
				modify(x,r,1);
				modify(r+1,r+1,0);
			}
			else
			{
				modify(x,x,0);
			}
		}
	};
}
using chtholly_tree::Q,chtholly_tree::odt;
typedef odt::iterator iter;
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int n,m,i;
	cin>>n>>m;
	odt s;
	s.insert({1,210000,0});
	for (i=0;i<n;i++)
	{
		cin>>b[i];
		s.add(b[i]);
	}
	while (m--)
	{
		int x,y;
		cin>>x>>y;--x;
		s.del(b[x]);
		s.add(b[x]=y);
		cout<<next(s.rbegin())->r<<'\n';
	}
}