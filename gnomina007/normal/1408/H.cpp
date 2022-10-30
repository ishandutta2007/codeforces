#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<cassert>
#include<algorithm>
#include<random>
#include<map>
#include<set>
#include <bitset>
#include<queue>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<char> vc;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<ll>> vvl;
typedef vector<pair<ll, ll>> vpll;
typedef vector<pair<ld, ld>> vpld;
typedef vector<pair<int, int>> vpi;
typedef pair<ld, ld> pld;
#define mp make_pair
#define pb push_back

int mod = 998244353;
//int mod = 1e9 + 7;

int sum(int a, int b)
{
	int c = a + b;
	if (c >= mod)
	{
		c -= mod;
	}
	return c;
}

int dif(int a, int b)
{
	int c = a - b;
	if (c < 0)
	{
		c += mod;
	}
	return c;
}

int mlt(int a, int b)
{
	ll c = a * 1LL * b;
	return c % mod;
}

int ibit(int n, int i)
{
	return ((n >> i) & 1);
}

void outp1(vl &ou, string s = " ")
{
	cerr << s << endl;
	for (int i = 0; i < ou.size(); i++)
	{
		cerr << ou[i] << ' ';
	}
	cerr << endl;
}

void outp1(vi &ou, string s = " ")
{
	cerr << s << endl;
	for (int i = 0; i < ou.size(); i++)
	{
		cerr << ou[i] << ' ';
	}
	cerr << endl;
}

void outp2(vector<vector<ll>> &ou, string s = " ")
{
	cerr << s << endl;
	for (int i = 0; i < ou.size(); i++)
	{
		for (int j = 0; j < ou[i].size(); j++)
		{
			cerr << ou[i][j] << ' ';
		}
		cerr << '\n';
	}
}

int bp(int x, int y)
{
	if (y == 0)
	{
		return 1;
	}
	int a = 0;
	if (!(y % 2))
	{
		a = bp(x, y / 2);
	}
	return (y % 2) ? mlt(bp(x, y - 1), x) : mlt(a, a);
}

int obr(int x)
{
	return bp(x, mod - 2);
}

const int maxn = 301;
int fact[maxn], ofact[maxn];

void prec()
{
	fact[0] = 1;
	ofact[0] = 1;
	for (int i = 1; i < maxn; i++)
	{
		fact[i] = mlt(fact[i - 1], i);
	}
	//cerr << "sdsds" << endl;
	ofact[maxn - 1] = obr(fact[maxn - 1]);
	for (int i = maxn - 2; i > 0; i--)
	{
		ofact[i] = mlt(ofact[i + 1], i + 1);
	}
}

int c(int a, int b)
{
	return ((a <= b) && (a >= 0)) ? mlt(fact[b], mlt(ofact[a], ofact[b - a])) : 0;
}

ll inf = 1e18;

struct segtree // , +  .       
{
	int depth=0;
	vector<int> lb, rb, son, pushed, mn;
};

int sml = 1e8; //   -  -

void rec_init(segtree &s, int l, int r, int num)
{
//	cerr<<l<<' '<<r<<endl;
	s.lb[num] = l;
	s.rb[num] = r;
	if (num < (1 << s.depth))
	{
		int mid = (l + r) / 2;
		rec_init(s, l, mid, 2 * num);
		rec_init(s, mid, r, 2 * num + 1);
	}
	else
		s.son[num] = -1;
}

void init(segtree &s, int n)
{
	int t = 0, cur = n;
	while (cur > 1)
	{
		cur = (cur + 1) / 2;
		t++;
	}
	s.depth = t;
	(s.lb).resize(1 << (t + 1));
	s.rb = s.lb;
	s.son = s.lb;
	s.pushed = s.lb;
	s.mn = s.lb;
	rec_init(s, 0, (1 << t), 1);
}

void getmax(segtree &s, int num)//   
{
	s.mn[num] = min(s.mn[2 * num] + s.pushed[2 * num], s.mn[2 * num + 1] + s.pushed[2 * num + 1]);
}

void segadd(segtree &s, int l, int r, int num, int val)
{
	//cerr<<"ADD "<<l<<' '<<r<<' '<<num<<' '<<s.lb[num]<<' '<<s.rb[num]<<' '<<val<<endl;
	if (l == s.lb[num] && r == s.rb[num])
	{
		s.pushed[num] += val;
	}
	else
	{
		int mid = (s.lb[num] + s.rb[num]) / 2;
		int r1 = min(mid, r), l2 = max(l, mid);
		if (l < r1)
			segadd(s, l, r1, 2 * num, val);
		if (l2 < r)
			segadd(s, l2, r, 2 * num + 1, val);
		getmax(s, num);
	}
}

int segmin(segtree &s, int l, int r, int num)
{
//	cerr<<"MIN "<<l<<' '<<r<<' '<<num<<' '<<s.lb[num]<<' '<<s.rb[num]<<' '<<endl;
	if (l == s.lb[num] && r == s.rb[num])
	{
		return s.mn[num] + s.pushed[num];
	}
	else
	{
		int mid = (s.lb[num] + s.rb[num]) / 2;
		int r1 = min(mid, r), l2 = max(l, mid);
		int val1 = sml;
		if (l < r1)
			val1 = min(val1, segmin(s, l, r1, 2 * num));
		if (l2 < r)
			val1 = min(val1, segmin(s, l2, r, 2 * num + 1));
		return val1 + s.pushed[num];
	}
}

int total_smin(segtree &s)
{
	int val=segmin(s, 0, 1<<s.depth, 1);
	return val;
}

void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	int n;
	cin >> n;
	vector<int> vals(n), prev(n), used(n + 1, -1);
	for (int i = 0; i < n; i++)
		cin >> vals[i];
	int zer = 0;
	for (int i = 0; i < n; i++)
	{
		if (vals[i] == 0)
			zer++;
		prev[i] = used[vals[i]];
		used[vals[i]] = i;
	}
	int ans = zer, curzero = 0;// -    
	segtree s;
	init(s, n + 1);
//	outp1(prev, "prev ");
	for (int i = 0; i < n; i++)
	{
		if (vals[i] != 0)
			segadd(s, prev[i] + 1, i + 1, 1, 1);
		if (vals[i] == 0)
			curzero++;
		segadd(s, i + 1, i + 2, 1, curzero);
		ans = min(ans,segmin(s, 0, i+2, 0)+zer-curzero);
	}
	cout << min(zer/2, ans) << '\n';
}

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int tests = 1;
	cin >> tests;
	for (int i = 0; i < tests; i++)
		solve();
	int n;
	cin >> n;
}