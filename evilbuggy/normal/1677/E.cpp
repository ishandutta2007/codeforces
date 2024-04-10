#include <bits/stdc++.h>
using namespace std;

struct Data{
	int mxm;
	long long m, c, lazym, lazyc;
	Data(){
		m = c = lazym = lazyc = 0;
	}
};

const int maxn = 200005;
const int maxm = 1000005;

long long ans[maxm];
Data tree[maxn << 2];
vector<int> divisors[maxn];
vector<pair<int, int> > queries[maxn];
int p[maxn], q[maxn], lo[maxn], hi[maxn], last[maxn];

void build(int v, int l, int r){
	if(l == r){
		tree[v].mxm = p[l];
		return;
	}
	int m = (l + r)/2;
	build(v + v, l, m);
	build(v + v + 1, m + 1, r);
	tree[v].mxm = max(tree[v + v].mxm, tree[v + v + 1].mxm);
}

int queryMax(int v, int s, int e, int l, int r){
	if(l <= s && e <= r)return tree[v].mxm;
	int m = (s + e)/2;
	if(r <= m)return queryMax(v + v, s, m, l, r);
	if(m + 1 <= l)return queryMax(v + v + 1, m + 1, e, l, r);
	return max(queryMax(v + v, s, m, l, r), queryMax(v + v + 1, m + 1, e, l, r));
}

inline void push(int v, int s, int e){
	if(tree[v].lazym != 0 || tree[v].lazyc != 0){
		tree[v].m += tree[v].lazym*(e - s + 1);
		tree[v].c += tree[v].lazyc*(e - s + 1);
		if(s != e){
			tree[v + v].lazym += tree[v].lazym;
			tree[v + v].lazyc += tree[v].lazyc;
			tree[v + v + 1].lazym += tree[v].lazym;
			tree[v + v + 1].lazyc += tree[v].lazyc;
		}
		tree[v].lazym = 0;
		tree[v].lazyc = 0;
	}
}

inline long long eval(pair<long long, long long> p, long long x){
	return x*p.first + p.second;
}

void update(int v, int s, int e, int l, int r, long long m, long long c){
	if(l <= s && e <= r){
		tree[v].lazym += m;
		tree[v].lazyc += c;
		push(v, s, e);
		return;
	}
	push(v, s, e);
	if(e < l || r < s || r < l)return;
	
	int mi = (s + e)/2;
	update(v + v, s, mi, l, r, m, c);
	update(v + v + 1, mi + 1, e, l, r, m, c);
	tree[v].m = tree[v + v].m + tree[v + v + 1].m;
	tree[v].c = tree[v + v].c + tree[v + v + 1].c;
}

pair<long long, long long> query(int v, int s, int e, int l, int r){
	push(v, s, e);
	if(l <= s && e <= r)return {tree[v].m, tree[v].c};
	int m = (s + e)/2;
	if(r <= m)return query(v + v, s, m, l, r);
	if(m + 1 <= l)return query(v + v + 1, m + 1, e, l, r);
	pair<long long, long long> p1 = query(v + v, s, m, l, r);
	pair<long long, long long> p2 = query(v + v + 1, m + 1, e, l, r);
	return {p1.first + p2.first, p1.second + p2.second};
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int t; cin >> t;
	stack<int> maxst;
	for(int i = 1; i <= n; i++){
		cin >> p[i]; q[p[i]] = i; lo[i] = hi[i] = -1;
		while(!maxst.empty() && p[maxst.top()] < p[i])maxst.pop();
		if(maxst.empty()){
			last[i] = 0;
		}else{
			last[i] = maxst.top();
		}
		maxst.push(i);
		for(int j = i; j <= n; j += i){
			divisors[j].emplace_back(i);
		}
	}
	for(int i = 1; i <= t; i++){
		int l; cin >> l;
		int r; cin >> r;
		queries[r].emplace_back(l, i);
	}
	build(1, 1, n);
	set<int> curInds;
	for(int i = 1; i <= n; i++){
		while(!curInds.empty()){
			int x = *curInds.begin();
			if(x >= p[i])break;
			curInds.erase(x);
			update(1, 1, n, lo[x], hi[x], -1, i - 1);
			lo[x] = -1; hi[x] = -1;
		}
		{
			int m = p[i];
			int hig = 0;
			int low = last[i] + 1;
			for(int d : divisors[m]){
				int e = m/d;
				if(q[d] >= q[e] || q[d] <= last[i] || q[d] > i || q[e] > i)continue;
				hig = max(hig, q[d]);
			}
			if(low <= hig){
				assert(lo[m] == -1);
				lo[m] = low;
				hi[m] = hig;
				update(1, 1, n, lo[m], hi[m], +1, 1 - i);
				curInds.insert(m);
			}
		}
		for(int m = p[i] + p[i]; m <= n; m += p[i]){
			int k = m/p[i];
			if(q[k] >= i || q[m] >= i)continue;
			int low = last[q[m]] + 1;
			int hig = min(q[m], q[k]);
			if(hig < low || queryMax(1, 1, n, hig, i) != m)continue;
			if(lo[m] == -1){
				lo[m] = low;
				hi[m] = hig;
				update(1, 1, n, lo[m], hi[m], +1, 1 - i);
				curInds.insert(m);
			}else{
				update(1, 1, n, lo[m], hi[m], -1, i - 1);
				lo[m] = min(lo[m], low);
				hi[m] = max(hi[m], hig);
				update(1, 1, n, lo[m], hi[m], +1, 1 - i);
			}
		}
		for(auto x : queries[i]){
			ans[x.second] = eval(query(1, 1, n, x.first, i), i);
		}
	}
	for(int i = 1; i <= t; i++){
		cout << ans[i] << '\n';
	}

	return 0;
}