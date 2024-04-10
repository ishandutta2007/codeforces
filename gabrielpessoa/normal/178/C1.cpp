#include<bits/stdc++.h>
#include<assert.h>
using namespace std;

typedef long long ll;

const int ms = 4e5+5, inf = 0x3f3f3f3f;

map<int, int> tipo;
map<int, int> pos;

int inicioIdx[ms], sz[ms];
int seg[2*ms], lazy[2*ms];
int ciclo[ms], posicaoNoCiclo[ms];
int n;
int h; // 
int* t, *d;

void calc(int p, int k) {
	if (d[p] == -1) t[p] = max(t[p<<1],t[p<<1|1]);
	else t[p] = d[p];
}

void apply(int p, int value, int k) {
	t[p] = value;
	if(p < n) d[p] = value;
}

void build(int l, int r) {
	int k = 2;
	for (l += n, r += n-1; l > 1; k <<= 1) {
		l >>= 1, r >>= 1;
		for (int i = r; i >= l; --i) calc(i, k);
	}
}

void push(int l, int r) {
	int s = h, k = 1 << (h-1);
	for (l += n, r += n-1; s > 0; --s, k >>= 1)
		for (int i = l >> s; i <= r >> s; ++i) if (d[i] != -1) {
		apply(i<<1, d[i], k);
		apply(i<<1|1, d[i], k);
		d[i] = -1;
		}
}

void modify(int l, int r, int value) {
	if (value == -1) return;
	//cout << "modificando " << l << " pra " << r << " = " << value << endl;
	r++;
	push(l, l + 1);
	push(r - 1, r);
	int l0 = l, r0 = r, k = 1;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1, k <<= 1) {
		if (l&1) apply(l++, value, k);
		if (r&1) apply(--r, value, k);
	}
	build(l0, l0 + 1);
	build(r0 - 1, r0);
}

int query(int l) {
	int r = l + 1;
	push(l, l + 1);
	push(r - 1, r);
	int res = 0;
	for (l += n, r += n; l < r; l >>= 1, r >>= 1) {
		if (l&1) res = max(res, t[l++]);
		if (r&1) res = max(res, t[--r]);
	}
	return res;
}

void updateGlobal(int i) {	
	d = lazy + inicioIdx[i];
	t = seg + inicioIdx[i];
	n = sz[i];
	h = sizeof(int) * 8 - __builtin_clz(n);
}

int buscaBinaria(int t, int p) {
	int n = sz[t];
	updateGlobal(t);
	int l = p + 1, r = p + n;
	while(r - l > 1) {
		int m = (l + r) / 2;
		int check = query(m % n);
		if(check == p) r = m;
		else l = m;
	}
	//cout << "busca binaria de " << t << " " << p << " = ";
	int check = query(l % n);
	if(check == p) {
		//cout << l % n << endl; 
		return l % n;
	}
	else {
		//cout << r % n << endl;
		return r % n;
	}
}

int main(){
	cin.tie(0);
	cin.sync_with_stdio(false);
	int h, m, n, ans = 0;
	cin >> h >> m >> n;
	memset(lazy, -1, sizeof lazy);
	int zzz = 0;
	int ciclosAteAgora = 0;
	int cnt = 0;
	for(int i = 0; i < h; i++) {
		int pos = i;
		if(!ciclo[pos]) ++ciclosAteAgora;
		for(int j = 0; ciclo[pos] == 0; j++) {
			//cout << "Comecando no " << pos << endl;
			ciclo[pos] = ciclosAteAgora;
			posicaoNoCiclo[pos] = j;
			sz[ciclosAteAgora]++;
			cnt++;
			//cout << "Ciclo de " << pos << " = " << ciclosAteAgora << endl;
			pos = (pos + m) % h;
		}
	}
	//cout << "to vivo e o ciclo 1 tem " << sz[1] << " e temos " << ciclosAteAgora << endl;
	for(int i = 1; i <= ciclosAteAgora; i++) {
		int qnt = sz[i];
		//cout << qnt << '\n';
		inicioIdx[i] = zzz;
		updateGlobal(i);
		for(int j = 0; j < qnt; j++) modify(j, j, j);
		//for(int j = 0; j < qnt*2; j++) cout << "No " << j << " = " << t[j] << " e " << d[j] << '\n';
		zzz += 2 * qnt;
	}
	//cout << "sobrevivi aqui tbm " << endl;
	for(int i = 0; i < n ; i++) {
		string s;
		cin >> s;
		if(s == "+") {
			int hash, id;
			cin >> id >> hash;
			int t = ciclo[hash], p = posicaoNoCiclo[hash];
			updateGlobal(t);
			//cout << sz[0] << '\n';
			int posicaoInserir = query(p);
			pos[id] = posicaoInserir;
			tipo[id] = t;
			ans += (posicaoInserir + sz[t] - p) % sz[t];
			//cout << "ans agora eh " << ans << " porque " << posicaoInserir << " e " << p << endl;
			int apos = query((posicaoInserir + 1) % sz[t]);
			//cout << posicaoInserir << " " << (posicaoInserir + 1) % sz[t] << " " << apos << '\n';
			//cout << posicaoInserir << '\n';
			if(apos == posicaoInserir) {
				//cout << "na posicao " << p << " eh igual a " << apos << endl;
				modify(0, sz[t] - 1, inf);
				//cout << "Me diz que eh inf plz : " << query(0, inicioIdx[t], 0, sz[t] - 1) << endl;
				continue;
			}
			int inicioUpdate = buscaBinaria(t, posicaoInserir);
			if(inicioUpdate > posicaoInserir) {
				modify(inicioUpdate, sz[t] - 1, apos);
				modify(0, posicaoInserir, apos);
			} else {
				modify(inicioUpdate, posicaoInserir, apos);
			}
			//cout << sz[t] << '\n';
			//cout << "Inserindo na table " << t << " de " << inicioUpdate << " ate " << posicaoInserir << " agora eh " << apos << endl;
		} else {
			int id;
			cin >> id;
			int t = tipo[id], p = pos[id];
			updateGlobal(t);
			int posicaoApos = query(p);
			//cout << "Tentando remover a prox posicao livre eh " << posicaoApos << endl;
			if(posicaoApos == inf) {
				modify(0, sz[t] - 1, p);
				continue;
			}
			int inicioUpdate = buscaBinaria(t, posicaoApos);
			//assert(p != posicaoApos || (p > posicaoApos && inicioUpdate >= p && inicioUpdate < posicaoApos) || (p < posicaoApos && !(inicioUpdate < p && inicioUpdate >= posicaoApos)));
			if(inicioUpdate > p) {
				modify(inicioUpdate, sz[t] - 1, p);
				modify(0, p, p);
			} else {
				modify(inicioUpdate, p, p);
			}
			//cout << "Removendo na table " << t << " de " << inicioUpdate << " ate " << p << " agora eh " << p << endl;
		}
	}
	cout << ans << '\n';
	return 0;
}