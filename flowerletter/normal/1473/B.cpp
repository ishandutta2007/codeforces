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

int T, n, m;
string s, t;
int main() {
	//freopen("in.txt", "r", stdin);
	for(cin >> T; T; T--) {
		cin >> s >> t;
		n = s.size(), m = t.size();
		string a = "", b = "";
		rep(i, 1, m / __gcd(n, m)) a = a + s;
		rep(i, 1, n / __gcd(n, m)) b = b + t;
		if(a == b) cout << a << endl; 
		else cout << -1 << endl;
	}
	return 0;
}