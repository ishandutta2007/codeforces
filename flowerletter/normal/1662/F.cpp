#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
mt19937_64 hua(time(0));
template<typename T> inline bool chkmx(T &x, T y) {return x < y ? x = y, 1 : 0;}
template<typename T> inline bool chkmn(T &x, T y) {return y < x ? x = y, 1 : 0;}
queue<int> q;
vector<int> dep; 
struct Segment {
	#define ls u << 1
	#define rs u << 1 | 1
	int n;
	vector<int> mn, mx, p;
	void up(int u) {mx[u] = max(mx[ls], mx[rs]), mn[u] = min(mn[ls], mn[rs]);}
	void build(int u, int l, int r) {
		if(l == r) {
			mx[u] = min(n - 1, l + p[l]);
			mn[u] = max(0, l - p[l]);
			return ;
		}
		int mid = l + r >> 1;
		build(ls, l, mid), build(rs, mid + 1, r);
		up(u); 
	}
	void init(int _n, vector<int> _p) {
		n = _n, p = _p;
		mn.assign(n + 5 << 2, 1e9);
		mx.assign(n + 5 << 2, -1);
		build(1, 0, n - 1);
	}
	void covermx(int u, int l, int r, int ql, int qr, int k, int d) {
		if(mx[u] < k) return ;
		if(l == r) {
			q.push(l), dep[l] = d;
			mx[u] = -1, mn[u] = 1e9;
			return ;
		}
		int mid = l + r >> 1;
		if(qr <= mid) covermx(ls, l, mid, ql, qr, k, d); 
		else if(ql > mid) covermx(rs, mid + 1, r, ql, qr, k, d);
		else covermx(ls, l, mid, ql, qr, k, d), covermx(rs, mid + 1, r, ql, qr, k, d);
		up(u);
	}
	void covermn(int u, int l, int r, int ql, int qr, int k, int d) {
//		cout << u << ' '<< l << ' ' << r <<' ' << ql << ' ' << qr << ' '<< k << ' ' << d << ' ' << mn[u] << '\n';;
		if(mn[u] > k) return ;
		if(l == r) {
			q.push(l), dep[l] = d;
			mx[u] = -1, mn[u] = 1e9;
			return ;
		}
		int mid = l + r >> 1;
		if(qr <= mid) covermn(ls, l, mid, ql, qr, k, d); 
		else if(ql > mid) covermn(rs, mid + 1, r, ql, qr, k, d);
		else covermn(ls, l, mid, ql, qr, k, d), covermn(rs, mid + 1, r, ql, qr, k, d);
		up(u);
	}
}sgt;
void solvecase() {
	int n, s, t;
	cin >> n >> s >> t;
	s --, t --;
	vector<int> p(n);
	dep = vector<int> (n, -1); 
	for(int i = 0; i < n; i ++) {
		cin >> p[i];
	}
	sgt.init(n, p);
	dep[s] = 0, sgt.covermx(1, 0, n - 1, s, s, 0, 0);
//	return ;
	while(!q.empty()) {
		int u = q.front(); q.pop();
//		cout << u <<  ' '<< dep[u] << '\n';
		sgt.covermn(1, 0, n - 1, u, min(n - 1, u + p[u]), u, dep[u] + 1);
		sgt.covermx(1, 0, n - 1, max(0, u - p[u]), u, u, dep[u] + 1);
	}
	cout << dep[t] << '\n';
}
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false);
	cin.tie(0), cout.tie(0);
	int T;
	for(cin >> T; T; T --) {
		solvecase();
	}
	return 0;
}