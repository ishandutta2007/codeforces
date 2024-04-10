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
vector<int> a;
vector<int> ask(int x,int y)
{
	cout<<"? "<<x+1<<' '<<y+1<<endl;
//vector<int> b(a.begin()+x,a.begin()+y+1);
//sort(all(b));
//return b;
	vector<int> r(y-x+1);
	cin>>r;
	for (int &x:r) --x;
	return r;
}
void answer(int x)
{
//assert(a[x]==x);
	cout<<"! "<<x+1<<endl;
}
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int T;
	cin>>T;
	while (T--)
	{
		int n;
		cin>>n;
		//a.resize(n);
		//cin>>a;
		int l=0,r=n-1,m,i;
		while (l<r)
		{
			m=l+r>>1;
			auto v=ask(l,m);
			set<int> s(all(v));
			int res=0;
			for (i=l;i<=m;i++) res+=s.count(i);
			if (res&1) r=m; else l=m+1;
		}
		answer(l);
	}
}