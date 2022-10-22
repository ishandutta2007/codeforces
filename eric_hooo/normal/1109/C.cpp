#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pi;
typedef pair <pi, pi> pii;

const long long INF = 0x3f3f3f3f3f3f3f3f;

vector <pii> q;
vector <int> all;

int get_id(int x){
	return lower_bound(all.begin(), all.end(), x) - all.begin();
}

struct Segment_tree{
	struct Node{
		long long sum, minj;
		long long lazy;
		Node(){sum = 0, minj = 0, lazy = 0;}
	}T[1600010];
	void pushup(int now){
		T[now].sum = T[now << 1].sum + T[now << 1 | 1].sum;
		T[now].minj = min(T[now << 1].minj, T[now << 1 | 1].minj + T[now << 1].sum);
	}
	Node merge(Node a, Node b){
		Node ans; ans.sum = a.sum + b.sum, ans.minj = min(a.minj, a.sum + b.minj);
		return ans;
	}
	void pushdown(int now, int l, int r){
		int mid = l + r >> 1;
		if (T[now].lazy == INF) return ;
		long long v = T[now].lazy;
		T[now].lazy = INF;
		T[now << 1].sum = v * (all[mid + 1] - all[l]), T[now << 1].lazy = v;
		T[now << 1 | 1].sum = v * (all[r + 1] - all[mid + 1]), T[now << 1 | 1].lazy = v;
		T[now << 1].minj = v >= 0 ? v * (all[l + 1] - all[l]) : T[now << 1].sum;
		T[now << 1 | 1].minj = v >= 0 ? v * (all[mid + 2] - all[mid + 1]) : T[now << 1 | 1].sum;
	}
	void Build(int now, int l, int r){
		T[now].lazy = INF;
		if (l == r){
			T[now].sum = 0, T[now].minj = 0;
			return ;
		}
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
		pushup(now);
	}
	void Update(int now, int l, int r, int L, int R, long long v){
		if (l == L && r == R){
			T[now].sum = (all[r + 1] - all[l]) * v;
			T[now].minj = v >= 0 ? (all[l + 1] - all[l]) * v : T[now].sum;
			T[now].lazy = v;
			return ;
		}
		pushdown(now, l, r);
		int mid = l + r >> 1;
		if (R <= mid) Update(now << 1, l, mid, L, R, v);
		else if (L > mid) Update(now << 1 | 1, mid + 1, r, L, R, v);
		else Update(now << 1, l, mid, L, mid, v), Update(now << 1 | 1, mid + 1, r, mid + 1, R, v);
		pushup(now);
	}
	Node Query(int now, int l, int r, int L, int R){
		if (L > R) return Node();
//		cout << "     Query:" << now << " " << l << " " << r << " " << L << " " << R << endl;
		if (l == L && r == R) return T[now];
		pushdown(now, l, r);
		int mid = l + r >> 1;
		if (R <= mid) return Query(now << 1, l, mid, L, R);
		if (L > mid) return Query(now << 1 | 1, mid + 1, r, L, R);
		return merge(Query(now << 1, l, mid, L, mid), Query(now << 1 | 1, mid + 1, r, mid + 1, R));
	}
}seg1;

int main(){
	int n; scanf("%d", &n);
	for (int i = 0; i < n; i++){
		int op; scanf("%d", &op);
		pii x; x.fi.fi = op;
		if (op == 1) scanf("%d%d", &x.se.fi, &x.se.se), all.push_back(x.se.fi);
		else if (op == 2) scanf("%d", &x.fi.se), all.push_back(x.fi.se);
		else scanf("%d%d%d", &x.se.fi, &x.se.se, &x.fi.se), all.push_back(x.se.fi), all.push_back(x.se.se);
		q.push_back(x);
	}
	sort(all.begin(), all.end()), all.resize(unique(all.begin(), all.end()) - all.begin());
	int m = all.size() - 2;
//	cout << all.size() << endl;
//	cout << "                              all:" << all[1] << endl;
//	cout << "                                  get_id:" << get_id(5) << endl;
	if (m >= 0) seg1.Build(1, 0, m);
	set <int> now;
	for (int i = 0; i < n; i++){
//		cout << "i:" << i << endl;
//		cout << "  first:" << q[i].se.fi << " " << q[i].se.se << endl;
		int op = q[i].fi.fi;
		if (op == 1) q[i].se.fi = get_id(q[i].se.fi);
		else if (op == 2) q[i].fi.se = get_id(q[i].fi.se);
		else q[i].se.fi = get_id(q[i].se.fi), q[i].se.se = get_id(q[i].se.se);
		if (op == 1){
			int t = q[i].se.fi, s = q[i].se.se;
			if (t == all.size() - 1) continue;
//			cout << "   t:" << t << endl;
			set <int> :: iterator it = now.upper_bound(t);
			int last = it == now.end() ? all.size() - 1 : *it;
//			cout << "   last:" << last - 1 << endl;
			seg1.Update(1, 0, m, t, last - 1, s);
			now.insert(t);
		} else if (op == 2){
//			cout << "     POS" << endl;
			int t = q[i].fi.se;
			if (t == all.size() - 1) continue;
//			cout << "    t:" << t << endl;
			set <int> :: iterator it = now.lower_bound(t);
//			cout << "    pd:" << (it == now.end()) << endl;
//			cout << "    it:" << *it << endl;
			if (it == now.end() || *it != t) continue;
			it++;
			int last = it == now.end() ? all.size() - 1 : *it;
			it--;
			int first = 0;
			long long v = 0;
			if (it != now.begin()){
				it--, first = *it;
				v = seg1.Query(1, 0, m, first, first).sum / (all[first + 1] - all[first]);
			}
//			cout << first << endl;
//			cout << seg1.Query(1, 0, m, first, first).sum << endl;
//			cout << "  v:" << v << endl;
//			cout << "  [" << first << ", " << last - 1 << "]" << endl;
//			cout << "  all:[" << all[first] << ", " << all[last - 1] << "]" << endl;
			seg1.Update(1, 0, m, first, last - 1, v);
			now.erase(t);
		} else {
			int l = q[i].se.fi, r = q[i].se.se, v = q[i].fi.se;
			set <int> :: iterator it = now.lower_bound(l);
			int from = -1, to = all.size() - 2;
			long long val = -1;
			int pos, le, ri;
			long long sum, k;
			if (it != now.end()) to = *it - 1;
			if (it != now.begin()){
				it--, from = *it;
				val = seg1.Query(1, 0, m, from, from).sum / (all[from + 1] - all[from]);
				seg1.Update(1, 0, m, from, to, 0);
			}
//			cout << "  " << l << " " << r << " " << v << endl;
			if (v == 0){
				printf("%d\n", all[l]);
				goto END;
			}
			if (l == r){
				printf("-1\n");
				goto END;
			}
//			cout << "  all:" << seg1.Query(1, 0, m, l, r - 1).minj << endl;
			if (seg1.Query(1, 0, m, l, r - 1).minj > -v){
				printf("-1\n");
				goto END;
			}
			le = l, ri = r - 1;
			while (le < ri){
//				cout << "  bound:" << le << " " << ri << endl;
				int mid = le + ri >> 1;
//				cout << "  mid:" << mid << endl; 
				long long x = seg1.Query(1, 0, m, l, mid).minj;
//				cout << "  POS" << endl;
				if (x > -v) le = mid + 1;
				else ri = mid;
			}
			pos = le;
			sum = seg1.Query(1, 0, m, l, pos - 1).sum;
			k = seg1.Query(1, 0, m, pos, pos).sum / (all[pos + 1] - all[pos]);
//			cout << "  pos:" << all[pos] << endl;
//			cout << "  sum:" << sum << endl;
			printf("%.9lf\n", 1.0 * (-v - sum) / k + all[pos]);
			END:;
			if (~from) seg1.Update(1, 0, m, from, to, val);
		}
	}
	return 0;
}