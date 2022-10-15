#include <iostream>
#include <algorithm>

using namespace std;

vector <int> dp;
vector <int> v;
int n, m, s, d;                         

int op(int a, int b)
{
	return (a < 0) ? b : a;
}

const int minT = -1;
const int segtreePow = 20;
const int segtreeMax = 1 << segtreePow;
const int segtreeLen = segtreeMax * 2;

class segtree
{
	public:
	vector<int> tree;
	void clear()
	{
		for (int i = 0; i < segtreeLen; i++) tree[i] = minT;
        }
	segtree() : tree(segtreeLen)
	{
		clear();
        }
	void update(int i, int tl, int tr, int v, int val)
	{
		if (tl == tr) tree[i] = val;
			else
			{
				int tm = (tl + tr) / 2;
				if (v <= tm) update(i * 2, tl, tm, v, val);
					else update(i * 2 + 1, tm + 1, tr, v, val);
				tree[i] = op(tree[i * 2], tree[i * 2 + 1]);
			}
	}
	void update(int v, int val)
	{
		update(1, 0, segtreeMax - 1, v, val);
	}
	int query(int i, int tl, int tr, int l, int r)
	{
		if (l > r) return minT;
		if (l == tl && r == tr) return tree[i];
		int tm = (tl + tr) / 2;
		return op(query(i * 2, tl, tm, l, min(tm, r)),
		          query(i * 2 + 1, tm + 1, tr, max(l, tm + 1), r));
	}
	int query(int l, int r)
	{
		return query(1, 0, segtreeMax - 1, l, r);
	}
	void updIt(int i)
	{
		update(i, (dp[i] < 0) ? -1 : i);
	}
};

void repair(int step)
{
	if (step == 0) cout << "RUN " <<  v[0] - 1 << "\n"; 
		else
		{
			repair(dp[step]);
			cout << "JUMP " << v[step - 1] - v[dp[step]] + 2 << "\n"; 
			if (step == n) 
			{
				if (m - v[n - 1] - 1 != 0) cout << "RUN " << m - v[n - 1] - 1 << "\n";
			}
			else cout << "RUN " << v[step] - v[step - 1] - 2 << "\n"; 
		}		
}

int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m >> s >> d;
	v.resize(n);
	for (int i = 0; i < n; i++) cin >> v[i];
	sort(v.begin(), v.end());
	dp.resize(n + 1);
	segtree t;
	if (v[0] - 1 < s) dp[0] = -1; 
		else dp[0] = 0;
	t.updIt(0);
	for (int i = 1; i <= n; i++)
	{
		if (i != n)
			if (v[i] - v[i - 1] - 2 < s)	
			{
				dp[i] = -1;
				t.updIt(i);
				continue;
			}
		int u = int(upper_bound(v.begin(), v.end(), v[i - 1] - d + 1) - v.begin());    
		dp[i] = t.query(u, i - 1);
		t.updIt(i);  
	}
	if (dp[n] == -1) cout << "IMPOSSIBLE" << "\n";
		else repair(n);
}