#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define mod 998244353 
#define db double
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
int fa[maxn], col[maxn];
int gfa(int a) {
	if(fa[a ] == a) return a;
	int ns = gfa(fa[a]);
	if (col[fa[a]]) col[a] ^= 1;
	fa[a] = ns;
	return ns;
} 
int n, m;
vi eg[maxn];
int r[maxn];
int main() {
	int a, b, c;
	cin >> a >> b >> c;
	if (b < c) swap(b, c);
	int fl = 1;
	if (b < a) fl = 0;
	else if (c < a && (b % a) != 0) fl = 0;
	if (fl) cout << (b / a) + (c / a) << endl;
	else cout << -1 << endl;
	return 0;
}
/*
1 2
..
*/