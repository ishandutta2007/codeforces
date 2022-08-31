//#pragma comment(linker, "/STACK:1000000000")
#pragma GCC optimize("Ofast,no-stack-protector")
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
#include <memory.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <ctime>
#include <limits.h>
#include <random>
#include <bitset>
#include <cstring>
#include <memory.h>
#include <cassert>

#define all(a) (a).begin(), (a).end()
#define pb push_back
#define mp make_pair
#define ll long long
#define ull unsigned long long 
#define pii pair <int, int>
#define ld double
#define pll pair <ll, ll>

using namespace std;

const int maxn = (int)2e5 + 10;
const int inf = (int)1e9;

struct Tree {
	int n;
	
	vector<int> t;
	
	void build(int it, int l, int r, const vector<int>& v) {
		if (l == r) {
			t[it] = v[l];
		} else {
			int m = (l + r) >> 1;
			build(2 * it, l, m, v);
			build(2 * it + 1, m + 1, r, v);
			t[it] = min(t[2 * it], t[2 * it + 1]);
		}
	}
	
	Tree(vector <int> v) {
		n = (int)v.size();
		t.resize(4 * n);
		build(1, 0, n - 1, v);
	}
	
	vector<int> cur;
	
	void change(int it, int l, int r, int lm, int rm, int x) {
		if (t[it] > x) {
			return;
		}
		
		if (l == r) {
			cur.push_back(l);
			t[it] = inf;
		} else if (l == lm && r == rm) {
			int m = (l + r) >> 1;
			change(2 * it, l, m, lm, m, x);
			change(2 * it + 1, m + 1, r, m + 1, rm, x);
			t[it] = min(t[2 * it], t[2 * it + 1]);
		} else {
			int m = (l + r) >> 1;
			if (rm <= m) {
				change(2 * it, l, m, lm, rm, x);
			} else if (lm > m) {
				change(2 * it + 1, m + 1, r, lm, rm, x);
			} else {
				change(2 * it, l, m, lm, m, x);
				change(2 * it + 1, m + 1, r, m + 1, rm, x);
			}
			t[it] = min(t[2 * it], t[2 * it + 1]);
		}
	}
	
	vector<int> change(int l, int r, int x) {
		cur.clear();
		change(1, 0, n - 1, l, r, x);
		return cur;
	}
};

int p[maxn];

int main() {
	int t;
	cin >> t;
	while (t--) {
		int n, a, b;
		scanf("%d %d %d", &n, &a, &b);
		a--;
		b--;
		
		vector<int> f, s;
		
		for (int i = 0; i < n; i++) {
			int x;
			scanf("%d", &x);
			p[i] = x;
			s.push_back(i - x);
			f.push_back(-(i + x));
		}
		
		Tree l(f);
		Tree r(s);
		
		queue<int> q;
		q.push(a);
		vector<int> dst(n, -1);
		dst[a] = 0;
		
		while (!q.empty()) {
			int v = q.front();
			q.pop();
			
			vector<int> cur = r.change(v, min(n - 1, v + p[v]), v);
			for (int x : cur) {
				if (dst[x] == -1) {
					dst[x] = dst[v] + 1;
					q.push(x);
				}
			}
			
			cur = l.change(max(0, v - p[v]), v, -v);
			for (int x : cur) {
				if (dst[x] == -1) {
					dst[x] = dst[v] + 1;
					q.push(x);
				}
			}
		}
		
		printf("%d\n", dst[b]);
	}
}