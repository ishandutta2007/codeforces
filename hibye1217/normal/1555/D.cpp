#include <bits/stdc++.h>
#define endl '\n'
#define fr first
#define sc second
#define all(v) v.begin(),v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() )
#define bout(x) cout << bitset<sizeof(x)*8>(x) << endl
#define mkp(a,b) make_pair(a,b)
#define gcd(a,b) __gcd(a,b)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using cpl = complex<ld>;
const ld pi = 3.14159265358979323846264338327950288;
const ld tau = 2 * pi;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

// #define DEBUG

typedef pair<pi2, int> pi3;
int sq;
int cnt[4][4];
pi3 qry[200020];
int ans[200020];

int f(int i1, int i2, int i3){
	return cnt[0][i1] + cnt[1][i2] + cnt[2][i3];
}

void Main(){
	int n, m; cin >> n >> m; sq = sqrt(n);
	string s; cin >> s;
	for (int i = 1; i <= m; i++){
		cin >> qry[i].fr.fr >> qry[i].fr.sc;
		qry[i].sc = i;
	}
	sort(qry+1, qry+m+1, [](pi3 a, pi3 b){
		if (a.fr.fr/sq != b.fr.fr/sq){ return a.fr.fr < b.fr.fr; }
		return a.fr.sc < b.fr.sc;
	});
	int st = 0, ed = 0; cnt[0][ s[0]-'a' ] += 1;
	for (int i = 1; i <= m; i++){
		int pst = qry[i].fr.fr, ped = qry[i].fr.sc; pst -= 1; ped -= 1;
		int idx = qry[i].sc;
		for (int p = pst; p < st; p++){ cnt[p%3][ s[p]-'a' ] += 1; }
		for (int p = st; p < pst; p++){ cnt[p%3][ s[p]-'a' ] -= 1; }
		for (int p = ed+1; p <= ped; p++){ cnt[p%3][ s[p]-'a' ] += 1; }
		for (int p = ped+1; p <= ed; p++){ cnt[p%3][ s[p]-'a' ] -= 1; }
		st = pst; ed = ped;
		ans[idx] = ed-st+1 - max({ f(0,1,2), f(0,2,1), f(1,0,2), f(1,2,0), f(2,0,1), f(2,1,0) });
	}
	for (int i = 1; i <= m; i++){
		cout << ans[i] << endl;
	}
}

int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}