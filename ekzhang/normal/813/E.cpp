#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

#define MAXN 100013
#define MAXLG 20
int N, K, Q;
int A[MAXN];
struct Node {
	int i, l, r, size;
} buf[MAXN * MAXLG * 2];
int mem = 0;
int tree[MAXN];
list<int> pos[MAXN];

int build_tree(int lo, int hi) {
	if (lo > hi) {
		return 0;
	}
	int mid = (lo + hi) / 2;
	int idx = ++mem;
	buf[idx] = (Node) { mid, build_tree(lo, mid - 1), build_tree(mid + 1, hi) };
	return idx;
}

int update(int node, int i, int x) {
	if (!node) return 0;
	int idx = ++mem;
	int l = buf[node].l;
	int r = buf[node].r;
	if (i < buf[node].i) l = update(l, i, x);
	if (i > buf[node].i) r = update(r, i, x);
	buf[idx] = (Node) { buf[node].i, l, r, buf[node].size + x };
	return idx;
}

int query(int node, int i) {
	if (i < buf[node].i)
		return query(buf[node].l, i) + buf[node].size - buf[buf[node].l].size;
	if (i > buf[node].i)
		return query(buf[node].r, i);
	return buf[node].size - buf[buf[node].l].size;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	tree[0] = build_tree(0, N - 1);
	for (int i = 0; i < N; i++) {
		if (pos[A[i]].size() < K) {
			tree[i + 1] = update(tree[i], i, 1);
		}
		else {
			tree[i + 1] = update(update(tree[i], pos[A[i]].front(), -1), i, 1);
			pos[A[i]].pop_front();
		}
		pos[A[i]].push_back(i);
	}

	cin >> Q;
	int last = 0;
	for (int q = 0; q < Q; q++) {
		int x, y;
		cin >> x >> y;
		int l = (x + last) % N;
		int r = (y + last) % N;
		if (l > r) swap(l, r);
		last = query(tree[r + 1], l);
		cout << last << '\n';
	}

	cout.flush();
	return 0;
}