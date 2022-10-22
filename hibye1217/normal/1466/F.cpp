#include <bits/stdc++.h>
#define endl '\n'
#define fr first
#define sc second
#define all(v) v.begin(),v.end()
#define bout(x) cout << bitset<sizeof(x)*8>(x) << endl;
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
const int dx[4] = {0, 1, 0, -1}, dy[4] = {-1, 0, 1, 0};
const int ddx[8] = {0, 1, 1, 1, 0, -1, -1, -1}, ddy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int nx[8] = {1, 2, 2, 1, -1, -2, -2, -1}, ny[8] = {-2, -1, 1, 2, 2, 1, -1, -2};

const ll mod = 1e9 + 7;
int par[500020];
bool chk[500020];
vector<int> v;

int fnd(int now){
	if (par[now] == now) return now;
	return par[now] = fnd( par[now] );
}

void uni(int x, int y){
	chk[x] |= chk[y];
	par[y] = x;
}

void Main(){
	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= m; i++){
		par[i] = i;
	}
	ll two = 1;
	for (int i = 1; i <= n; i++){
		int k, x, y;
		cin >> k;
		if (k == 1){
			cin >> x;
			int xx = fnd(x);
			if (chk[xx]) continue;
			chk[xx] = true;
		}
		if (k == 2){
			cin >> x >> y;
			int xx = fnd(x), yy = fnd(y);
			if (chk[xx] && chk[yy] ||
				xx == yy) continue;
			uni(xx, yy);
		}
		v.push_back(i);
		two <<= 1;
		two %= mod;
	}
	cout << two << ' ' << v.size() << endl;
	for (int idx : v){
		cout << idx << ' ';
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}