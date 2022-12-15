#include<bits/stdc++.h>
#include<assert.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;

const int ms = 4e5+5, inf = 0x3f3f3f3f;

map<int, ii> mapa;

int inicioIdx[ms], sz[ms];
int seg[2*ms];
int ciclo[ms], posicaoNoCiclo[ms];
int n;
int h; // 
int* t, *d;

int combine(int l, int r) {
	//cout << "Combinando " << l << " e " << r << endl;
	return l == -1 ? r : l;
}

void update(int p, int value) {
	//cout << "UPDATING " << p << ' ' << value << endl;
	for(t[p += n] = value; p >>= 1; ) t[p] = combine(t[p<<1], t[p<<1|1]);
}

int query(int l, int r) {
	//cout << "Query " << l << ' ' << r << endl;
	int resl = -1, resr = -1;
	for(l += n, r += n; l < r; l >>=1, r >>= 1) {
		if(l & 1) resl = combine(resl, t[l++]);
		if(r&1) resr = combine(t[--r], resr);
	}
	return combine(resl, resr);
}

int trueQuery(int x) {
	//cout << "Query True " << x << endl;
	return x == 0 ? query(x, n) : combine(query(x, n), query(0, x));
}

void updateGlobal(int i) {	
	t = seg + inicioIdx[i];
	n = sz[i];
}

int main(){
	cin.tie(0);
	cin.sync_with_stdio(false);
	long long h, m, n, ans = 0;
	cin >> h >> m >> n;
	int zzz = 0;
	int ciclosAteAgora = 0;
	int cnt = 0;
	for(int i = 0; i < h; i++) {
		int pos = i;
		if(!ciclo[pos]) ++ciclosAteAgora;
		for(int j = 0; ciclo[pos] == 0; j++) {
			ciclo[pos] = ciclosAteAgora;
			posicaoNoCiclo[pos] = j;
			sz[ciclosAteAgora]++;
			cnt++;
			pos = (pos + m) % h;
		}
	}
	for(int i = 1; i <= ciclosAteAgora; i++) {
		int qnt = sz[i];
		//cout << qnt << '\n';
		inicioIdx[i] = zzz;
		updateGlobal(i);
		for(int j = 0; j < qnt; j++) update(j, j);
		zzz += 2 * qnt;
	}
	for(int i = 0; i < n ; i++) {
		string s;
		cin >> s;
		if(s == "+") {
			int hash, id;
			cin >> id >> hash;
			int t = ciclo[hash], p = posicaoNoCiclo[hash];
			updateGlobal(t);
			int posicaoInserir = trueQuery(p);
			mapa[id] = ii(t, posicaoInserir);
			ans += (posicaoInserir + sz[t] - p) % sz[t];
			update(posicaoInserir, -1);
		} else {
			int id;
			cin >> id;
			ii smt = mapa[id];
			int t = smt.first, p = smt.second;
			//cout << "Posicao de " << id << " removendo = " << p << endl;
			updateGlobal(t);
			update(p, p);
		}
	}
	cout << ans << '\n';
	return 0;
}