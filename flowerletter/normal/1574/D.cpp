/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].next].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
#define mk(s, t) make_pair(s, t)
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 10;
const int maxm = 2e5;
int n, m, c[maxn + 5];
vector<int> a[maxn + 5];
struct Node {
	int a[maxn + 1];
	int sum, lst;
	Node() {memset(a, 0, sizeof a);}
	
	friend operator < (Node x, Node y) {
		rep(i, 1, n) if(x.a[i] != y.a[i]) return x.a[i] < y.a[i];
		return 0;
	}
}st;
struct cmp1 {
	bool operator () (Node &x, Node &y) {
		return x.sum < y.sum;
	}
};
map<Node, int> mp;
int main() {
//	freopen("in.txt", "r", stdin);
	cin >> n;st.lst = 1;
	rep(i, 1, n) {
		cin >> c[i];
		a[i].resize(c[i] + 1);
		rep(j, 1, c[i]) cin >> a[i][j];
		st.sum += a[i][c[i]];
		st.a[i] = c[i];
	}
	cin >> m;
	rep(i, 1, m) {
		Node nw;
		rep(i, 1, n) cin >> nw.a[i], nw.sum += a[i][nw.a[i]];
		mp[nw] = 1;
	}
	priority_queue<Node, vector<Node>, cmp1> q;
	q.push(st);
	while(1) {
		Node u = q.top(); q.pop();
		if(!mp[u]) {
			rep(i, 1, n) cout << u.a[i] << ' ';
			break;
		}
		rep(i, u.lst, n) if(u.a[i] > 1) {
			u.lst = i;
			u.sum -= a[i][u.a[i]];
			u.a[i] --;
			u.sum += a[i][u.a[i]];
			q.push(u);
			u.sum -= a[i][u.a[i]];
			u.a[i] ++;
			u.sum += a[i][u.a[i]];
		}
	}
	return 0;
}