#include <bits/stdc++.h>
#define Fast ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
typedef long long ll;
typedef pair<int, int> pii;
const int INF = 1e9;
const int N = 131072;

int tree[N*2];

void update(int node, int st, int ed, int pos, int val){
	if (st > pos || pos > ed) return;
	if (st == ed){
		tree[node] = val;
		return;
	}
	int mid = st + ed >> 1;
	update(node*2, st, mid, pos, val);
	update(node*2+1, mid+1, ed, pos, val);
	tree[node] = tree[node*2] + tree[node*2+1];
}

int query(int node, int ns, int ne, int st, int ed){
	if (st > ne || ns > ed) return 0;
	if (st <= ns && ne <= ed) return tree[node];
	int mid = ns + ne >> 1;
	return query(node*2, ns, mid, st, ed) + query(node*2+1, mid+1, ne, st, ed);
}

int main(){
	Fast;
	int t;
	cin >> t;
	while (t--){
		int n, m;
		ll sum=0;
		int a[N] = {0};
		cin >> n >> m;
		for (int i = 1; i <= n; i++) update(1, 1, n, i, 0);
		for (int i = 1; i <= n; i++){
			int x;
			cin >> x;
			a[x] = i;
		}
		for (int i = 1; i <= m; i++){
			int x;
			cin >> x;
			if (query(1, 1, n, a[x], n) == 0){
				sum += 2LL*(a[x] - query(1, 1, n, 1, a[x])) - 1;
				update(1, 1, n, a[x], 1);
				//cout << 'a';
			}
			else{
				update(1, 1, n, a[x], 1);
				sum += 1LL;
				//cout << 'b';
			}
		}
		cout << sum << '\n';
	}
}