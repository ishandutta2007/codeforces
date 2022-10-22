#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <string>
#include <cmath>
#include <random>

using namespace std;

void pass(){
	return;
}

#define int long long
#define rand() (rand()<<15+rand())
typedef long long ll;
typedef unsigned long long ull;
const double EPS = 1e-6;

mt19937 rnd(rand());
const int MOD = 1e9 + 7;
const ll BIG_MOD = 1e18 + 7;
const int MAXN = 3e5 + 7;

struct Node{
	int x, y, cnt, num;
	Node *l, *r;
};

inline Node *init(int x, int num){
	Node *res = new Node();
	res->x = x;
	res->y = rand();
	res->cnt = 1;
	res->l = NULL;
	res->r = NULL;
	res->num = num;

	return res;
}

inline int cnt(Node *t){
	if (!t) return 0;
	return t->cnt;
}

inline Node *relax(Node *t){
	t->cnt = 1 + cnt(t->l) + cnt(t->r);
	return t;
}

inline Node *merge(Node *l, Node *r){
	if (!l) return r;
	if (!r) return l;

	if (l->y > r->y){
		l->r = merge(l->r, r);
		l = relax(l);
		return l;
	}
	else{
		r->l = merge(l, r->l);
		r = relax(r);
		return r;
	}
}

inline pair <Node*, Node*> split(Node *t, int x){
	if (!t) return{ NULL, NULL };

	if (x < t->x){
		auto tmp = split(t->l, x);
		t->l = tmp.second;
		t = relax(t);
		return{ tmp.first, t };
	}
	else{
		auto tmp = split(t->r, x);
		t->r = tmp.first;
		t = relax(t);
		return{ t, tmp.second };
	}
}

inline int k_stat(Node *t, int k){
	if (!k) return MOD;
	if (cnt(t) < k) return -MOD;

	if (k == cnt(t->r) + 1) return t->x;

	if (cnt(t->r) >= k){
		return k_stat(t->r, k);
	}
	else{
		return k_stat(t->l, k - cnt(t->r) - 1);
	}
}

inline Node *insert(Node *t, Node *elem){
	auto tmp = split(t, elem->x);
	return merge(merge(tmp.first, elem), tmp.second);
}

inline Node *erase(Node *t, int x){
	auto tmp1 = split(t, x - 1);
	auto tmp2 = split(tmp1.second, x);
	if (tmp2.first) tmp2.first = merge(tmp2.first->l, tmp2.first->r);
	return merge(merge(tmp1.first, tmp2.first), tmp2.second);
}

struct Event{
	bool type;
	int time, num;
};

inline bool comp(Event a, Event b){
	return (a.time < b.time) || (a.time == b.time && a.type && !b.type);
}

inline Event init1(bool type, int time, int num){
	Event res = *new Event;
	res.type = type;
	res.time = time;
	res.num = num;

	return res;
}

inline void print_last_k(Node *t, int k){
	if (!t || !k){
		return;
	}

	print_last_k(t->r, k);
	if (k > cnt(t->r)) cout << t->num + 1 << ' ';
	print_last_k(t->l, k - cnt(t->r) - 1);
}

signed main(){
	cout.tie(NULL);
	cout.precision(20);
	//freopen("input.txt", "r", stdin);
	ios_base::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector <pair <int, int> > a(n);
	vector <Event> c;
	for (int i = 0; i < n; ++i){
		cin >> a[i].first >> a[i].second;

		c.push_back(init1(true, a[i].first, i));
		c.push_back(init1(false, a[i].second, i));
	}

	sort(c.begin(), c.end(), comp);

	int ans = 0;
	Node *root = NULL;
	for (Event elem : c){
		int i = elem.num;

		if (elem.type){
			int left = elem.time;
			int right = min(a[i].second, k_stat(root, k - 1));
			ans = max(ans, right - left + 1);

			root = insert(root, init(a[i].second, i));
		}
		else{
			root = erase(root, a[i].second);
		}
	}

	cout << ans << '\n';

	if (!ans){
		for (int i = 0; i < k; ++i){
			cout << i + 1 << ' ';
		}

		return 0;
	}

	root = NULL;
	for (Event elem : c){
		int i = elem.num;

		if (elem.type){
			int left = elem.time;
			int right = min(a[i].second, k_stat(root, k - 1));
			int new_ans = right - left + 1;

			if (new_ans == ans){
				cout << i + 1 << ' ';
				print_last_k(root, k - 1);
				return 0;
			}

			root = insert(root, init(a[i].second, i));
		}
		else{
			root = erase(root, a[i].second);
		}
	}

	return 0;
}