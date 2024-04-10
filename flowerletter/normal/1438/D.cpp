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

template <typename T> bool chkmx(T &x, T y){return x < y ? 	x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 1e5;
int n, a[maxn + 5];
int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d", &n);
	rep(i, 1, n) scanf("%d", &a[i]);
	if(n & 1) {
		puts("YES");
		cout << n - 2<< endl;
		rep(i, 1, n / 2) cout << 1 << ' ' << i * 2 << ' ' << i * 2 + 1 << endl;
		rep(i, 1, n / 2 - 1) cout << 1 << ' ' << i * 2 << ' ' << i * 2 + 1 << endl; 
	}
	else {
		int sum = 0;
		rep(i, 1, n) sum ^= a[i];
		if(sum) puts("NO");
		else {
			puts("YES");
			cout << n  - 3 << endl;
			rep(i, 1, n / 2 - 1) cout << 1 << ' ' << i * 2 << ' ' << i * 2 + 1 << endl;
			per(i, n / 2 - 2, 1) cout << n << ' ' << i * 2 << ' ' << i * 2 + 1 << endl;
		}
	} 
	return 0;
}