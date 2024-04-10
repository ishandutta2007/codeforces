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
// mt19937 rnd(23);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
int n;
string ta;
struct Q
{
	int v,w;
};
int cnt;
int ask(string &s)
{
	cout<<s<<endl;
	int x=0;
// for (int i=0;i<n;i++) x+=s[i]==ta[i];
// ++cnt;
	cin>>x;
	if (x==n||x==-1)
	{
		cerr<<cnt<<endl;
		exit(0);
	}
	return x;
}
const int C='T'^'F';
int main()
{
	ios::sync_with_stdio(0);cin.tie(0);
	cout<<setiosflags(ios::fixed)<<setprecision(15);
	int i,j;
	cin>>n;
	// cin>>n>>ta;
	// n=1000;
	// for (i=0;i<n;i++) ta+=rnd()&1?'T':'F';
	vector<int> a(n),rd(n);
	vector<vector<Q>> e(n);
	iota(all(a),0);
	string s(n,'T'),ans(n,'T');
	for (i=0;i<n;i++) if (rnd()&1) s[i]^=C;
	int cur=ask(s);
	while (a.size()>1)
	{
		int m=a.size();
		int x=rnd()%m,y=rnd()%m;
		while (x==y) x=rnd()%m;
		if (e[a[x]].size()<e[a[y]].size()) swap(x,y);
		s[a[x]]^=C;
		s[a[y]]^=C;
		if (e[a[x]].size()>1)
		{
			s[a[x]]^=C;
			s[e[a[x]][0].v]^=C;
			s[e[a[x]][1].v]^=C;
			int now=ask(s);
			if (now==cur+3)
			{
				ans[a[x]]=s[e[a[x]][0].v]^e[a[x]][0].w;
				ans[a[y]]=s[a[y]];
			}
			else if (now==cur+1)
			{
				ans[a[x]]=s[e[a[x]][0].v]^e[a[x]][0].w;
				ans[a[y]]=s[a[y]]^C;
			}
			else if (now==cur-1)
			{
				ans[a[x]]=s[e[a[x]][0].v]^e[a[x]][0].w^C;
				ans[a[y]]=s[a[y]];
			}
			else if (now==cur-3)
			{
				ans[a[x]]=s[e[a[x]][0].v]^e[a[x]][0].w^C;
				ans[a[y]]=s[a[y]]^C;
			} else throw;
			cur=now;
			vector<int> b(m-2);
			int j=0;
			for (i=0;i<m;i++) if (i!=x&&i!=y) b[j++]=a[i];
			a=b;
			continue;
		}
		int now=ask(s);
		if (cur==now)
		{
			e[a[x]].push_back({a[y],(s[a[x]]==s[a[y]])*C});
			rd[a[y]]=1;
			if (s[a[x]]=='F') s[a[x]]='T',s[a[y]]^=C;
			a.erase(a.begin()+y);
		}
		else
		{
			ans[a[x]]=s[a[x]],ans[a[y]]=s[a[y]];
			if (now==cur-2) ans[a[x]]^=C,ans[a[y]]^=C;
			cur=now;
			vector<int> b(m-2);
			int j=0;
			for (i=0;i<m;i++) if (i!=x&&i!=y) b[j++]=a[i];
			a=b;
		}
	// cerr<<"?\n";
	}
	// cerr<<"!!\n";
	if (a.size()==1)
	{
		s[a[0]]^=C;
		ans[a[0]]=s[a[0]];
		int now=ask(s);
		if (now<cur) ans[a[0]]^=C;
	}
	queue<int> q;
	for (i=0;i<n;i++) if (!rd[i]) q.push(i);
	while (q.size())
	{
		int u=q.front();q.pop();
		for (auto [v,w]:e[u]) q.push(v),ans[v]=w^ans[u];
	}
	ask(ans);
	// cerr<<ta<<endl;
	assert(0);
}