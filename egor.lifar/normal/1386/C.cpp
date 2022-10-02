#include <iostream>
#include <complex>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdio>
#include <numeric>
#include <cstring>
#include <ctime>
#include <cstdlib>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <list>
#include <cmath>
#include <bitset>
#include <cassert>
#include <queue>
#include <stack>
#include <deque>
#include <random>


using namespace std;
template<typename T1, typename T2> inline void chkmin(T1 &a, T2 b) {if (a > b) a = b;}
template<typename T1, typename T2> inline void chkmax(T1 &a, T2 b) {if (a < b) a = b;}
#define files(FILENAME) read(FILENAME); write(FILENAME)
#define read(FILENAME) freopen((FILENAME + ".in").c_str(), "r", stdin)
#define write(FILENAME) freopen((FILENAME + ".out").c_str(), "w", stdout)
#define all(c) (c).begin(), (c).end()
#define sz(c) (int)(c).size()
#define left left228
#define right right228
#define y1 y1228
#define mp make_pair
#define pb push_back
#define y2 y2228
#define rank rank228
using ll = long long;
using ld = long double; 
const string FILENAME = "input";
const int MAXN = 500228;


int n, m, q;
int a[MAXN], b[MAXN];



struct dsu
{
	vector<pair<int, int> > parent;
	vector<int> rank;
	vector<pair<pair<int, int>, pair<int, int> > > parentChanges;
	vector<pair<int, pair<int, int> > > rankChanges;
	int it;
	int lastbad;
	void init(int n) {
		parent.resize(n);
		rank.resize(n);
		for (int i = 0; i < n; i++) {
			parent[i].first = i;
		}
		it = 0;
		lastbad = 1e9;
	}
	pair<int, int> find_set(int v) {
	    if (v != parent[v].first) {
	        int parity = parent[v].second;
	        parentChanges.pb(mp(parent[v], mp(v, it)));
	        parent[v] = find_set(parent[v].first);
	        parent[v].second ^= parity;
	    }
	    return parent[v];
	}
	void add_edge(int a, int b) {
		it++;
	    pair<int, int> pa = find_set(a);
	    a = pa.first;
	    int x = pa.second;
	    pair<int, int> pb = find_set(b);
	    b = pb.first;
	    int y = pb.second;
	    if (a == b) {
	        if (x == y) {
	            lastbad = it;
	        }
	    } else {
	        if (rank[a] < rank[b]) {
	            swap(a, b);
	        }
	        parentChanges.pb(mp(parent[b], mp(b, it)));
	        parent[b] = make_pair(a, x ^ y ^ 1);
	        if (rank[a] == rank[b]) {
	        	rankChanges.pb(mp(rank[a], mp(a, it)));
	            ++rank[a];
	        }
	    }
	}
	void reCharge(int timer) {
		it = timer;
		while (!parentChanges.empty() && parentChanges.back().second.second > timer) {
			auto x = parentChanges.back();
			parentChanges.pop_back();
			parent[x.second.first] = x.first;
		}
		while (!rankChanges.empty() && rankChanges.back().second.second > timer) {
			auto x = rankChanges.back();
			rankChanges.pop_back();
			rank[x.second.first] = x.first;
		}
		if (lastbad > it) {
			lastbad = 1e9;
		}
	}
	bool ok() {
		return lastbad <= it;
	}
} kek;




int last[MAXN];



void get(int l1, int l2, int r1, int r2) {
	if (l1 > l2) {
		return;
	} 
	chkmax(r1, l1 - 1);
	if (r1 == r2) {
		for (int i = l1; i <= l2; i++) {
			last[i] = r2;
		}
		return;
	}
	int lmid = (l1 + l2) / 2;
	int fl = kek.it;
	for (int i = l1; i < lmid; i++) {
		kek.add_edge(a[i], b[i]);
	}
	last[lmid] = lmid - 1;
	for (int i = r2; i >= max(r1, lmid); i--) {
		if (kek.ok()) {
			last[lmid] = i;
			break;
		}
		if (i >= 0) {
			kek.add_edge(a[i], b[i]);
		}
	}
//	cout << lmid << ' ' << last[lmid] << '\n';
	kek.reCharge(fl);
	if (l1 == l2) {
		return;
	}
	{
		fl = kek.it;
		for (int i = r2; i > last[lmid]; i--) {
			if (i < m) {
				kek.add_edge(a[i], b[i]);
			}
		}
		get(l1, lmid - 1, r1, last[lmid]);
		kek.reCharge(fl);
	}
	{
		fl = kek.it;
		for (int i = l1; i < lmid + 1; i++) {
			kek.add_edge(a[i], b[i]);
		}
		get(lmid + 1, l2, last[lmid], r2);
		kek.reCharge(fl);
	}
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	//read(FILENAME);
	cin >> n >> m >> q;
	for (int i = 0; i < m; i++) {
		cin >> a[i] >> b[i];
		a[i]--, b[i]--;
	}
	kek.init(n);
	if (max(n, m) <= 200 && q <= 200) {
		for (int it = 0; it < q; it++) {
			int l, r;
			cin >> l >> r;
			l--, r--;
			for (int i = 0; i < l; i++) {
				kek.add_edge(a[i], b[i]);
			}
			for (int i = r + 1; i < m; i++) {
				kek.add_edge(a[i], b[i]);
			}
			if (kek.ok()) {
				cout << "YES\n";
			} else {
				cout << "NO\n";
			}
			kek.reCharge(0);
		}	
		return 0;
	}
	get(0, m - 1, -1, m - 1);
	for (int it = 0; it < q; it++) {
		int l, r;
		cin >> l >> r;
		l--, r--;
		//cout << last[l] << endl; 
		if (last[l] >= r) {
			cout << "YES\n";
		} else {
			cout << "NO\n";
		}
	}
}