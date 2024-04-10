#include <bits/stdc++.h>
#define endl '\n'
#define PRECISION 0
using namespace std;
using ll = long long;
using ld = long double;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

const int B = 30;

int par[30][100001], odd[30][100001];
bool chk[30][100001];
int fnd1(int a, int i){
	if (par[i][a] == a){ return a; }
	return par[i][a] = fnd1(par[i][a], i);
}
void uni1(int a, int b, int c, int i){
	int pa = fnd1(a, i), pb = fnd1(b, i);
	par[i][pa] = pb;
}
int fnd2(int a, int i){
	if (odd[i][a] == a){ return a; }
	return odd[i][a] = fnd2(odd[i][a], i);
}
void uni2(int a, int b, int c, int i){
	int pa = fnd2(a, i), pb = fnd2(b, i);
	odd[i][pa] = pb; chk[i][pb] |= chk[i][pa];
}

void Main(){
	int n, m; cin >> n >> m;
	for (int j = 0; j < B; j++){
		for (int i = 1; i <= n; i++){ par[j][i] = odd[j][i] = i; }
	}
	while (m--){
		int a, b, c; cin >> a >> b >> c;
		for (int i = 0; i < B; i++){
			if (c & (1<<i)){
				uni1(a, b, c, i);
				if (c & 1){ uni2(a, b, c, i); }
			}
			if (~c & 1){
				int pa = fnd2(a, i), pb = fnd2(b, i);
				chk[i][pa] = chk[i][pb] = 1;
			}
		}
	}
	int q; cin >> q;
	while (q--){
		int v, w; cin >> v >> w;
		for (int i = 0; i < B; i++){
			int vp = fnd1(v, i), wp = fnd1(w, i);
			if (vp == wp){ cout << 0; goto next; }
		}
		for (int i = 1; i < B; i++){
			int vp = fnd2(v, i), wp = fnd2(w, i);
			if (chk[i][vp] || vp == wp){ cout << 1; goto next; }
		}
		cout << 2;
		next: cout << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout.setf(ios::fixed);
	cout.precision(PRECISION);
	Main();
}