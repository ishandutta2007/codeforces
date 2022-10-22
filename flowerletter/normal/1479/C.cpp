/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i++)
#define per(i, a, b) for(int i = (a); i >= int(b); i--)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u) for(int i = head[u]; i; i = e[i].next)
#define sz(s) (int)(s.size())
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
int L, R, n = 1;
struct Edge {
	int u, v, w;
};
vector<Edge> ans;
void add(int u, int v, int w) {
	ans.push_back((Edge){u + 1, v + 1, w});
	chkmx(n, v + 1);
}
int main() {
//	freopen("in.txt", "r", stdin);
	puts("YES");
	scanf("%d%d", &L, &R), R -= L;
	rep(i, 1, 25) {
		int up = (1 << i) - 1;
		if(up > R) {
			int del = up - R - 1, nw = 1 << i - 1;
			rep(j, 1, i - 1) if(!(del & (1 << j - 1))) add(j, i, nw - (1 << j - 1)), nw += (1 << j - 1);
			break; 
		}
		else if(up == R) {
			rep(j, 0, i - 1) add(j, i, 1 << i - 1);
			break;
		}
		else rep(j, 0, i - 1) add(j, i, 1 << i - 1);
	}
	n++;
	rep(i, 1, n - 1) ans.push_back((Edge){i, n, L});
	cout << n << ' ' << sz(ans) << endl;
	for(auto x : ans) cout << x.u << ' ' << x.v << ' ' << x.w << endl;
	return 0;
}