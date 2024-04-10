#include <bits/stdc++.h>
using namespace std;
#define maxn 400010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
#define fi first
#define pi pair<int, int>
#define se second
#define mp make_pair
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
// head
char inp[maxn];
int tp[maxn], pl[maxn];
stack<int> r1, r2;
vi eg[maxn];
ll ans[maxn];
ll a[maxn];
void cal(int x) {
	for (auto v : eg[x])
		cal(v);
	if (tp[x] == -1) {
		a[x] = 1;
		return ;
	} 
	else if (tp[x] == 0) {
		a[x] = 1e18;
		for (auto v : eg[x])
			a[x] = min(a[x], a[v]);
	}
	else {
		a[x] = 0;
		for (auto v : eg[x])
			a[x] += a[v];
	}
} 
void work(int x, ll t) {
	if (tp[x] == -1)
		ans[x] = t;
	else {
		if (tp[x] == 1)
			for (auto v : eg[x])
				work(v, t);
		else {
			int fl = 0;
			for (auto v : eg[x]) {
				if (fl) work(v, 0);
				else if (a[v] == a[x]) 
					work(v, t), fl = 1;
				else work(v, 0); 
			}
		}
	}
}
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int r;
		scanf("%d", &r);
		int cnt = 1;
		char ch = getchar();
		int num = 0;
		while (!r1.empty()) r1.pop();
		while (!r2.empty()) r2.pop();
		while (ch != '\n') {
			num++;
			if (ch == ' ') {
				ch = getchar();
				continue;
			}
			else if (ch == 'P')
				tp[r1.top()] = 1;
			else if (ch == 'S') tp[r1.top()] = 0;
			else if (ch == '*') {
				eg[cnt].clear();
				pl[cnt] = num, 
				tp[cnt] = -1;
				r2.push(cnt), 
				cnt++;
			} 
			else if (ch == '(') {
				eg[cnt].clear();
				pl[cnt] = num, 
				r1.push(cnt);
				cnt++;
			}
			else if (ch == ')') {
				int nid = r1.top(); 
				while (!r2.empty() && pl[r2.top()] > pl[nid])
					eg[nid].pb(r2.top()), 
					r2.pop();
				r1.pop();
				r2.push(nid);
			}
			ch = getchar();
		}
	//	cout << cnt << endl;
		cal(1);
		work(1, 1ll * r * a[1]);
		cout << "REVOLTING ";
		for (int i = 1; i < cnt; i++)
			if (tp[i] == -1)
				printf("%lld ", ans[i]);
		printf("\n");
	}
	return 0;
}