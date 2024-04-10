#include<bits/stdc++.h>
#define rep(i, l, r) for(int i = (l); i <= (r); i ++)
#define per(i, r, l) for(int i = (r); i >= (l); i --)
#define trv(i, u, v) for(int i = head[u], v = e[i].to; i; v = e[i = e[i].nxt].to)
#define fi first
#define se second
#define all(s) s.begin(), s.end()
#define sz(s) (int)(s.size())
#define lb(s) ((s) & -(s))
#define pb push_back
using namespace std;

typedef long long ll;
typedef pair<int, int> P;
mt19937_64 hua(time(0));
template<typename T> inline bool chkmx(T &x, T y) {return x < y ? x = y, 1 : 0;}
template<typename T> inline bool chkmn(T &x, T y) {return y < x ? x = y, 1 : 0;}
template<int T> using A = array<int, T>;

inline int read() {
	int x = 0, f = 1; char c = getchar();
	for(; !isdigit(c); c = getchar()) if(c == '-')  f = 0;
	for(; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	return f ? x : -x;
}
const int lg = 29;
int rev;
int s, t;
int sgn(int a, int b) {return a > b ? 1 : (a == b ? 0 : -1);}
int ask(int a, int b) {
	if(rev) cout << "? " << b << ' ' << a << endl;
	else cout << "? " << a << ' ' << b << endl;
	int x; cin >> x;
	return rev ? -x : x;
}
int main() {
// 	freopen("in.txt", "r", stdin);
// 	s = read(), t = read();  
	int c = 0, d = 0, tmp = ask(0, 0);
	int cnt = 0;
	rev = tmp == 1; 
	if(!tmp) {
		per(i, lg, 0) {
			int x = ask(1 << i, 0);
			if(x == -1) c |= 1 << i;
		}
		cout << "! " << c << ' ' << c << endl;
		return 0;
	} tmp = 0;
	per(i, lg, 0){
		int x = ask(tmp | 1 << i, 1 << i);
		if(x == 1) {
			d |= 1 << i;
			tmp |= 1 << i;
			if(ask(tmp, 0) == 1) rev ^= 1, swap(c, d); 
		}
		else {
			if(ask(tmp | 1 << i, 0) == -1) c |= 1 << i, d |= 1 << i;
		}
	}
	if(rev) cout << "! " << d << ' ' << c << endl; 
	else cout << "! " << c << ' ' << d << endl; 
	return 0;
}