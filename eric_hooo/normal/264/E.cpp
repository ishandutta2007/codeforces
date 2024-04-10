#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

const int base = 200000;
const int maxj = 200011;

int dp[100010];

struct Segment_tree{
	int maxj[800010];
	void pushup(int now){
		maxj[now] = max(maxj[now << 1], maxj[now << 1 | 1]);
	}
	void Build(){memset(maxj, 0, sizeof(maxj));}
	void Update(int now, int l, int r, int pos, int val){
		if (l == r){
			maxj[now] = val;
			return ;
		}
		int mid = l + r >> 1;
		if (pos <= mid) Update(now << 1, l, mid, pos, val);
		else Update(now << 1 | 1, mid + 1, r, pos, val);
		pushup(now);
	}
	int Query(int now, int l, int r, int L, int R){
		if (l == L && r == R) return maxj[now];
		int mid = l + r >> 1;
		if (R <= mid) return Query(now << 1, l, mid, L, R);
		if (L > mid) return Query(now << 1 | 1, mid + 1, r, L, R);
		return max(Query(now << 1, l, mid, L, mid), Query(now << 1 | 1, mid + 1, r, mid + 1, R));
	}
}seg1, seg2;

set <pii> s1, s2;

int main(){
	int n, m; scanf("%d%d", &n, &m);
	seg1.Build(), seg2.Build();
	for (int i = 0; i < m; i++){
		int ans;
		int op, x, y; scanf("%d%d", &op, &x);
		if (op == 1){
			scanf("%d", &y), y = y - i + base;
//			cout << "y:" << y << endl;
			vector <pii> v;
			while (s1.size()){
				auto it = s1.begin();
				if (it->fi > y) break;
				seg1.Update(1, 0, maxj, it->se, 0);
				v.push_back(mp(it->fi, it->se));
				s1.erase(it);
			}
//			cout << "  v.size:" << v.size() << endl;
			v.push_back(mp(y, x));
			reverse(v.begin(), v.end());
			for (pii p : v){
				int x = p.fi, y = p.se;
				s1.insert(mp(x, y));
				dp[y] = seg1.Query(1, 0, maxj, y + 1, maxj) + 1;
				seg1.Update(1, 0, maxj, y, dp[y]), seg2.Update(1, 0, maxj, x, dp[y]);
			}
			s2.insert(mp(x, y));
			ans = seg1.Query(1, 0, maxj, 0, maxj); 
		} else {
			vector <pii> v;
			while (x--){
				auto it = s2.begin();
				seg2.Update(1, 0, maxj, it->se, 0);
				v.push_back(mp(it->fi, it->se));
				s2.erase(it);
			}
			s1.erase(mp(v.back().se, v.back().fi));
			seg1.Update(1, 0, maxj, v.back().fi, 0);
			v.pop_back();
//			cout << "  v.size:" << v.size() << endl;
			reverse(v.begin(), v.end());
			for (pii p : v){
				int x = p.fi, y = p.se;
				s2.insert(mp(x, y));
				dp[x] = seg2.Query(1, 0, maxj, y + 1, maxj) + 1;
				seg2.Update(1, 0, maxj, y, dp[x]), seg1.Update(1, 0, maxj, x, dp[x]);
			}
			ans = seg2.Query(1, 0, maxj, 0, maxj);
		}
		printf("%d\n", ans);
	}
	return 0;
}