#include <bits/stdc++.h>
#define fi first
#define se second
using namespace std;

typedef pair <int, int> pii;

int a[100010];
int head[100010], to[200010], nxt[200010];
int tot;

struct Node{
	map <int, int> mp;
	vector <int> res;
	int size;
	Node(){size = 0;}
	void add(int x){
		int t = mp[x]++;
		if (t == res.size()) res.push_back(1);
		else res[t]++;
		size++;
	}
	Node *merge(Node *a){
		for (map <int, int> :: iterator it = a->mp.begin(); it != a->mp.end(); it++){
			for (int i = 0; i < it->se; i++){
				add(it->fi);
			}
		}
		return this;
	}
};

vector <pii> q[100010];
int ans[100010];

void add(int u, int v){
	to[tot] = v, nxt[tot] = head[u], head[u] = tot++;
}

Node *dfs(int x, int last){
//	cout << "dfs:" << x << " " << last << endl;
	Node *now = new Node(); now->add(a[x]);
	for (int i = head[x]; ~i; i = nxt[i]){
		int v = to[i];
//		cout << "  v:" << v << endl;
		if (v == last) continue;
		Node *t = dfs(v, x);
		now = now->size > t->size ? now->merge(t) : t->merge(now);
	}
//	cout << "dfs_end:" << x << endl;
//	for (auto it : now->mp){
//		cout << "  " << it.fi << " " << it.se << endl;
//	}
	for (int i = 0; i < q[x].size(); i++){
		int k = q[x][i].fi - 1, id = q[x][i].se;
		ans[id] = k < now->res.size() ? now->res[k] : 0;
	}
	return now;
}

int main(){
	memset(head, -1, sizeof(head));
	int n, m;
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}
	for (int i = 1; i < n; i++){
		int u, v; scanf("%d%d", &u, &v);
		add(u, v), add(v, u);
	}
	for (int i = 0; i < m; i++){
		int a, b; scanf("%d%d", &a, &b);
		q[a].push_back(make_pair(b, i));
	}
	dfs(1, 1);
	for (int i = 0; i < m; i++){
		printf("%d\n", ans[i]);
	}
	return 0;
}