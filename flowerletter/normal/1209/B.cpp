/*mjytxdy!*/
#include <bits/stdc++.h>
#define rep(i, a, b) for(int i = (a); i <= int(b); i++)
#define per(i, a, b) for(int i = (a); i >= int(b); i--)
#define fi first
#define se second
#define all(s) s.begin(),s.end()
#define trv(i, u) for(int i = head[u]; i; i = e[i].next)
#define sz(s) (int)(s.size())
#define lb(s) ((s) & (-s))
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

template <typename T> bool chkmx(T &x, T y){return x < y ? x = y, true : false;}
template <typename T> bool chkmn(T &x, T y){return x > y ? x = y, true : false;}
const int maxn = 100;
int n, a[maxn + 5], b[maxn+ 5];
char s[maxn + 5], t[maxn + 5];
int get() {
	int res = 0;
	rep(i, 1, n) res += t[i] == '1';
	return res; 
}
int main() {
	//freopen("in.txt", "r", stdin);
	scanf("%d%s", &n, s + 1);
	rep(i, 1, n) scanf("%d%d", &a[i], &b[i]);
	int mx = 0;
	rep(i, 0, 10000) {
		rep(j, 1, n) if(i < b[j]) t[j] = s[j]; else if((i - b[j]) / a[j] & 1) t[j] = s[j]; else t[j] = 1 ^ s[j];  
		chkmx(mx, get());
	}
	cout << mx << endl;
	return 0;
}