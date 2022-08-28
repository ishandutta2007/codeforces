#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>
 
#include <algorithm>
#include <tuple>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>
 
#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template <class T>
istream& operator>>(istream& is, vector<T>& v) {
  for (T& x : v)
    is >> x;
  return is;
}
 
template <class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
  if (!v.empty()) {
    os << v.front();
    for (int i = 1; i < v.size(); ++i)
      os << ' ' << v[i];
  }
  return os;
}

template <typename name>
class avlTree
{
	private:
	
	struct avlNode;
	typedef avlNode *avl;
	struct avlNode
	{
		int num, hei, size;
		name data;
		avl ls, rs;
		void update()
		{
			size = ls->size + rs->size + num;
			hei = max(ls->hei, rs->hei) + 1;
		}
	};
	protected:
	
	avl rot = NULL, NullNode = NULL;
	avl init(name x)
	{
		avl tmp = new avlNode;
		tmp->data = x;
		tmp->size = tmp->num = tmp->hei = 1;
		tmp ->ls = tmp->rs = NullNode;
		return tmp;
	}
	
	avl Single_left(avl T)
	{
		avl tmp = T->ls;
		T->ls = tmp->rs;
		tmp->rs = T;
		T->update();
		tmp->update();
		return tmp;
	}
	
	avl Single_right(avl T)
	{
		avl tmp = T->rs;
		T->rs = tmp->ls;
		tmp->ls = T;
		T->update();
		tmp->update();
		return tmp;
	}
	
	avl double_left(avl T)
	{
		T->ls = Single_right(T->ls);
		return Single_left(T);
	}
	
	avl double_right(avl T)
	{
		T->rs = Single_left(T->rs);
		return Single_right(T);
	}
	
	avl insert(avl T, name x)
	{
		if(T == NullNode) return init(x);
		if(x == T->data)
		{
			++(T->num);
			T->update();
			return T;
		}
		if(x < T->data)
		{
			T->ls = insert(T->ls, x);
			T->update();
			if(T->ls->hei - T->rs->hei == 2)
			{
				if(x < T->ls->data) T = Single_left(T);
				else T = double_left(T);
			}
		}
		else
		{
			T->rs = insert(T->rs, x);
			T->update();
			if(T->rs->hei - T->ls->hei == 2)
			{
				if(x < T->rs->data) T = double_right(T);
				else T = Single_right(T);
			}
		}
		return T;
	}
	
	avl erase(avl T, name x)
	{
		if(T == NullNode) return NullNode;
		if(T->data < x)
		{
			T->rs = erase(T->rs, x);
			T->update();
			if(T->ls->hei - T->rs->hei == 2)
			{
				if(T->ls->ls->hei >= T->ls->rs->hei) T = Single_left(T);
				else T = double_left(T);
			}
		}
		else if(x < T->data)
		{
			T->ls = erase(T->ls, x);
			T->update();
			if(T->rs->hei - T->ls->hei == 2)
			{
				if(T->rs->ls->hei > T->rs->rs->hei) T = double_right(T);
				else T = Single_right(T);
			}
		}
		else
		{
			if(T->num > 1)
			{
				--(T->num);
				T->update();
				return T;
			}
			else if(T->ls != NullNode && T->rs != NullNode)
			{
				avl p = T->rs;
				while(p->ls != NullNode) p = p->ls;
				T->num = p->num;
				T->data = p->data, p->num = 1;
				T->rs = erase(T->rs, T->data);
				T->update();
				if(T->ls->hei - T->rs->hei == 2)
				{
					if(T->ls->ls->hei >= T->ls->rs->hei) T = Single_left(T);
					else T = double_left(T);
				}
			}
			else
			{
				avl tmp = T;
				if(T->ls != NullNode) T = T->ls;
				else if(T->rs != NullNode) T = T->rs;
				else T = NullNode;
				delete tmp;
				tmp = NULL;
			}
		}
		return T;		
	}
	
	int get_rank(avl T, name x)
	{
		int ans = 0;
		while(T != NullNode)
		{
			if(T->data == x) return ans + T->ls->size + 1;
			else if(x < T->data) T = T->ls;
			else ans += T->ls->size + T->num, T = T->rs;
		}
    return ans;
	}
	
	name get_data(avl T, int x)
	{
		while(T != NullNode)
		{
			if(T->ls->size + T->num < x) x -= T->ls->size + T->num, T = T->rs;
			else if(x <= T->ls->size) T = T->ls;
			else return T->data;
		}
	}
	
	avl makeempty(avl x)
	{
		if(x == NullNode) return NullNode;
		x->ls = makeempty(x->ls);
		x->rs = makeempty(x->rs);
		delete x;
		return NullNode;
	}
	
	public:
	avlTree()
	{
		NullNode = new avlNode;
		NullNode->size = NullNode->num = NullNode->hei = 0;
		NullNode->ls = NullNode->rs = NullNode;
		rot = NullNode;
	}
	name prv(name x) {
		name ans = name(-1 << 28);
		avl tmp = rot;
		while(tmp != NullNode) {
			if(tmp->data == x) {
				if(tmp->ls != NullNode) {
					tmp = tmp->ls;
					while(tmp->rs != NullNode) tmp = tmp->rs;
					ans = tmp -> data;
				}
				break;
			}
			if(tmp->data < x && ans < tmp->data) { ans = tmp->data; }
			tmp = tmp->data < x ? tmp->rs : tmp->ls;
		}
		return ans;
	}
		
	name next(name x) {
		name ans = name(1 << 28);
		avl tmp = rot;
		while(tmp != NullNode) {
			if(tmp->data == x) {
				if(tmp->rs != NullNode) {
					tmp = tmp->rs;
					while(tmp->ls != NullNode) tmp = tmp->ls;
					ans = tmp->data;
				}
				break;
			}
			if(x < tmp->data && tmp->data < ans) { ans = tmp->data; }
			tmp = tmp->data < x ? tmp->rs : tmp->ls;
		}
		return ans;
	}
	
  int sz() const {
    if (!rot) return 0;
    return rot->size;
  }

	inline void insert(name x) { rot = insert(rot, x); return ; }
	
	inline void erase(name x) { rot = erase(rot, x); }
	
	inline int get_rank(name x) { return get_rank(rot, x); }
	
	inline name get_data(int x) { return get_data(rot, x); }
	
	void clear() { rot = makeempty(rot); }
	
	void output() { output(rot); }
};

const int N = 400010;

int n;
int p[N], w[N];

int top, root;
int dv[N], ls[N], rs[N];
avlTree<int> lk[N], rk[N];
ll ans;
ll invs[N], tot[N];

int brute(int l, int r) {
  int o = ++top;
  if (l == r) {
    return o;
  }
  int pl = min_element(w + l, w + r) - w;
  dv[o] = pl;

  for (int i = l; i <= pl; ++i) lk[o].insert(p[i]);
  for (int i = pl + 1; i <= r; ++i) rk[o].insert(p[i]);
  for (int i = l; i <= pl; ++i) invs[o] += rk[o].get_rank(p[i]);

  tot[o] = (pl - l + 1LL) * (r - pl);
  ans += min(tot[o] - invs[o], invs[o]);

  ls[o] = brute(l, pl);
  rs[o] = brute(pl + 1, r);
  return o;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 1; i <= n; ++i)
    cin >> p[i];
  for (int i = 1; i < n; ++i)
    cin >> w[i];

  root = brute(1, n);
  int q;
  cin >> q;

  auto qry = [&](int o, int l, int r, int x, int y) {
    ll ret = 0;
    while (l < r) {
      int pl = dv[o];
      ret -= min(invs[o], tot[o] - invs[o]);
      if (x <= pl) {
        lk[o].erase(p[x]);
        lk[o].insert(p[y]);
        invs[o] -= rk[o].get_rank(p[x]);
        invs[o] += rk[o].get_rank(p[y]);
        ret += min(invs[o], tot[o] - invs[o]);

        o = ls[o];
        r = pl;
      } else {
        rk[o].erase(p[x]);
        rk[o].insert(p[y]);
        invs[o] -= lk[o].sz() - lk[o].get_rank(p[x]);
        invs[o] += lk[o].sz() - lk[o].get_rank(p[y]);
        ret += min(invs[o], tot[o] - invs[o]);

        o = rs[o];
        l = pl + 1;
      }
    }
    return ret;
  };

  auto query = [&](int x, int y) {
    if (x == y) return ans;
    int o = root, l = 1, r = n;
    if (x > y) swap(x, y);
    while (true) {
      int pl = dv[o];
      if (y <= pl) {
        r = pl;
        o = ls[o];
      } else if (x > pl) {
        l = pl + 1;
        o = rs[o];
      } else {
        ll ret = -min(invs[o], tot[o] - invs[o]) + qry(ls[o], l, pl, x, y) + qry(rs[o], pl + 1, r, y, x);

        if (p[x] < p[y]) invs[o] += 1;
        else invs[o] -= 1;

        lk[o].erase(p[x]);
        rk[o].erase(p[y]);

        invs[o] -= rk[o].get_rank(p[x]);
        invs[o] += rk[o].get_rank(p[y]);

        invs[o] -= lk[o].sz() - lk[o].get_rank(p[y]);
        invs[o] += lk[o].sz() - lk[o].get_rank(p[x]);

        lk[o].insert(p[y]);
        rk[o].insert(p[x]);

        ret += min(invs[o], tot[o] - invs[o]);
        return ans + ret;
      }
    }
  };

  while (q--) {
    int x, y;
    cin >> x >> y;
    cout << (ans = query(x, y)) << '\n';
    swap(p[x], p[y]);
  }

  return 0;
}