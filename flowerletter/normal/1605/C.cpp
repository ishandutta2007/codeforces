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

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
template <int T> using A = array<int, T>;
inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int maxn = 1e6;
const int inf = 1e9;
int n;
char s[maxn + 5]; 
int main() {
//	freopen("in.txt", "r", stdin);
	for(int T = read(); T; T --) {
		cin >> n >> s + 1;
		int cntb = inf, cntc = inf, ans = inf, lst = -1;
		rep(i, 1, n) {
			if(s[i] == 'a') {
				if(cntb <= 1 && cntc <= 1) {
					chkmn(ans, cntb + cntc + 2);
				}
				else if(cntb == 2 && cntc == 0) {
					if(lst == 0) chkmn(ans, 7); 
					lst = 1;
				}
				else if(cntb == 0 && cntc == 2){
					if(lst == 1) chkmn(ans, 7);
					lst = 0;
				}
				else lst = -1;
				cntb = cntc = 0;
			}
			if(s[i] == 'b') cntb ++;
			if(s[i] == 'c') cntc ++;
		}
		cout << (ans == inf ? -1 : ans) << '\n';
	}
	return 0;
}