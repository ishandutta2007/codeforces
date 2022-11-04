//Awwawa! Dis cold yis ratten buy tEMMIE!
#include <bits/stdc++.h>
#define ll long long
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
#define maxn 500005

template <typename T> bool chkmax(T &x,T y){return x<y?x=y,true:false;}
template <typename T> bool chkmin(T &x,T y){return x>y?x=y,true:false;}

using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
priority_queue<pi> x;
int fl[maxn];
int main() {
	int q;
	cin >> q;
	int cnt = 0;
	int pl = 1;
	while (q--) {
		int t;
		scanf("%d", &t);
		if (t == 2) {
			while (fl[pl]) pl++;
			printf("%d\n", pl);
			fl[pl] = 1; 
		}
		else if (t == 3) {
			while (1) {
				pi cur = x.top();
				x.pop();
				int id = -cur.se;
				if (!fl[id]) {
					printf("%d\n", id);
					fl[id] = 1;
					break;
				}
			}
		}
		else {
			cnt++;
			int s;
			scanf("%d", &s);
			x.push(mp(s, -cnt));
		}
	}
	return 0;
}