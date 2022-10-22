#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i ++)
#define per(i, a, b) for(int i = (a); i >= int(b); i --)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].nxt].to)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
#define mk make_pair
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int,int> P;
mt19937_64 hua(time(0));
template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
template <int T> using A = array<int, T>;
inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int inf = 1e9;
const int maxn = 5000;
int n, k;
char t[maxn + 5];
bool use[maxn + 5];
void fmt() {
	rep(i, 0, k - 1) {
		rep(s, 0, (1 << k) - 1) if(s >> i & 1) use[s] |= use[s ^ 1 << i]; 
	}
}
int main() {
//	freopen("in.txt", "r", stdin);
	cin >> t + 1;
	n = strlen(t + 1), k = log2(n);
	vector<int> s;s.pb(0);
	rep(i, 1, n - (1 << k) + 1) {
		rep(i, 0, (1 << k) - 1) use[i] = 0;
		char mn = 'z'; 
		for(auto x : s) {
			use[x] = 1;
		}	
		fmt();s.clear();
		rep(j, 0, (1 << k) - 1) if(use[j]) chkmn(mn, t[i + j]);
		rep(j, 0, (1 << k) - 1) if(use[j]) if(mn == t[i + j]) s.pb(j);
		putchar(mn);
	}
	return 0;
}