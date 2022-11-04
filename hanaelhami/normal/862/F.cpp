#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define pb push_back

const int maxn = 1e5 + 20;
const int sq = 55;

struct node
{
	int pre , suf , ans , sz;
	node()
	{
		pre = suf = ans = sz = 0;
	}
};

node seg[sq][maxn * 4] , void_node;

int a[maxn] , n , mx[maxn * 4] , ans[maxn];

string s[maxn];

vector<int> Bigs;
int pre[maxn] , nxt[maxn];

inline void Change_Max(int p , int val , int s = 0 , int e = n , int v = 1)
{
	if(e - s < 2)
	{
		mx[v] = val;
		return;
	}
	int m = (s + e) / 2;

	if(p < m)
		Change_Max(p , val , s , m , 2 * v);
	else
		Change_Max(p , val , m , e , 2 * v + 1);

	mx[v] = max(mx[2 * v] , mx[2 * v + 1]);
}

inline int Get_Max(int l , int r , int s = 0 , int e = n , int v = 1)
{
	if(l <= s && e <= r)
		return mx[v];
	if(r <= s || e <= l)
		return 0;

	int m = (s + e) / 2;

	return max(Get_Max(l , r , s , m , 2 * v) , Get_Max(l , r , m , e , 2 * v + 1));
}

inline int LCP(int p)
{
	if(p < 0)
		return 0;
	int k = p + 1 , pt = 0;
	while(pt < (int)s[p].size() && pt < (int)s[k].size() && s[k][pt] == s[p][pt])
		pt++;

	return pt;
}

inline void build(int b , int s = 0 , int e = n , int v = 1)
{
	seg[b][v].pre = seg[b][v].suf = seg[b][v].ans = (e - s) * (int)(b == 0);
	seg[b][v].sz = e - s;

	if(e - s < 2)
		return;

	int m = (s + e) / 2;

	build(b , s , m , 2 * v);
	build(b , m , e , 2 * v + 1);
}

inline node merge(node a , node b)
{
	node c;
	
	c.sz = a.sz + b.sz;
	c.pre = a.pre + (a.pre == a.sz? b.pre : 0);
	c.suf = b.suf + (b.suf == b.sz? a.suf : 0);
	c.ans = max(max(a.ans , b.ans) , a.suf + b.pre);

	return c;
}

inline void Turn(int p , int b , int s = 0 , int e = n , int v = 1)
{
	if(e - s < 2)
	{
		seg[b][v].pre = seg[b][v].suf = seg[b][v].ans = 1 - seg[b][v].ans;
		return;
	}

	int m = (s + e) / 2;

	if(p < m)
		Turn(p , b , s , m , 2 * v);
	else
		Turn(p , b , m , e , 2 * v + 1);

	seg[b][v] = merge(seg[b][2 * v] , seg[b][2 * v + 1]);
}

inline node Get(int l , int r , int b , int s = 0 , int e = n , int v = 1)
{
	if(r <= l)
		return void_node;

	if(l <= s && e <= r)
		return seg[b][v];
	if(r <= s || e <= l)
		return void_node;

	int m = (s + e) / 2;

	return merge(Get(l , r , b , s , m , 2 * v) , Get(l , r , b , m , e , 2 * v + 1));
}

inline void change(int p , int val)
{
	if(p < 0)
		return;

	for(int i = min(a[p] , val); i < sq; i++)
	{
		bool tmp = (a[p] >= i) ^ (val >= i);
		if(tmp)
			Turn(p , i);
	}

	if(a[p] < sq && val >= sq)
		Bigs.pb(p);

	a[p] = val;
}

inline int solve(int s , int e)
{
	vector<int> t , tmp;
	for(auto p : Bigs)
	{
		if(a[p] < sq)
			continue;
		t.pb(p);
		if(s <= p && p < e)
			tmp.pb(p);
	}
	Bigs.swap(t);
	sort(tmp.begin() , tmp.end());
	tmp.resize(unique(tmp.begin() , tmp.end()) - tmp.begin());

	t.clear();
	int last;
	for(int i = 0; i < (int)tmp.size(); i++)
	{
		if(!i || tmp[i] != tmp[i - 1] + 1)
			t.clear() , last = tmp[i] - 1;

		while(!t.empty() && a[t.back()] >= a[tmp[i]])
			t.pop_back();

		if(t.empty())
			pre[tmp[i]] = last;
		else
			pre[tmp[i]] = t.back();
		t.pb(tmp[i]);
	}

	t.clear();
	for(int i = (int)tmp.size() - 1; i >= 0; i--)
	{
		if(i + 1 >= (int)tmp.size() || tmp[i + 1] != tmp[i] + 1)
			t.clear() , last = tmp[i] + 1;

		while(!t.empty() && a[t.back()] >= a[tmp[i]])
			t.pop_back();

		if(t.empty())
			nxt[tmp[i]] = last;
		else
			nxt[tmp[i]] = t.back();
		t.pb(tmp[i]);
	}

	int ans = 0;
	for(auto p : tmp)
		ans = max(ans , (nxt[p] - pre[p]) * a[p]);

	return ans;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int q;
	cin >> n >> q;

	for(int i = 0; i < n; i++)
		cin >> s[i] , Change_Max(i , s[i].size());

	for(int i = 0; i < sq; i++)
		build(i);

	for(int i = 0; i < n - 1; i++)
		change(i , LCP(i));

	for(int i = 0; i < q; i++)
	{
		int type;
		cin >> type;

		if(type == 1)
		{
			int lq , rq;
			cin >> lq >> rq;
			lq-- , rq--;

			ans[i] = max(Get_Max(lq , rq + 1) , solve(lq , rq));

			for(int j = 1; j < sq; j++)
			{
				int tmp = Get(lq , rq , j).ans;
				if(tmp)
					tmp++;

				ans[i] = max(ans[i] , tmp * j);
			}
		}
		else
		{
			int p;
			string tmp;
			cin >> p >> tmp;

			p--;
			s[p] = tmp;

			change(p - 1 , LCP(p - 1));
			change(p , LCP(p));
			Change_Max(p , s[p].size());
		}
	}

	for(int i = 0; i < q; i++)
		if(ans[i])
			cout << ans[i] << endl;

}