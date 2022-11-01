#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

const int maxm = 500100;
const int mod = 1e9 + 7;

int add(int a, int b) {
	a += b;
	if(a >= mod) a -= mod;
	if(a < 0) a += mod;
	return a;
}

int mult(int a, int b) {
	return (ll) a * b % mod;
}

int tko[maxm];
int rod[maxm];
int vel[maxm];

int daj_rod(int a) {
	if(rod[a] == a) return a;
	return rod[a] = daj_rod(rod[a]);
}

void spoji(int a, int b) {
	a = daj_rod(a);
	b = daj_rod(b);
	rod[b] = a;
	vel[a] += vel[b];
	return;
}

vector <pair <int, int> > svi;
vector <vector <int> > ind;
vector <bool> slob;
vector <int> nez;

void oslobodi(int x) {
	slob[x] = 1;
	vector <int> tr = ind[x];
	ind[x].clear();
	for(int tr_ind : tr) {
		int a = svi[tr_ind].first, b = svi[tr_ind].second;
		if(!slob[a]) oslobodi(a);
		if(!slob[b]) oslobodi(b);
	}
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m, a, b, c;
	cin >> n >> m;
	svi.resize(n);
	ind.resize(m, vector <int>());
	slob.resize(m, 0);
	REP(i, maxm) {
		rod[i] = i;
		tko[i] = -1;
		vel[i] = 1;
	}
	REP(i, n) {
		cin >> a;
		if(a == 2) {
			cin >> b >> c;
			b--; c--;
			svi[i] = make_pair(b, c);
			if(slob[b] && slob[c]) continue;
			else if(slob[b]) {
				oslobodi(c);
				nez.push_back(i);
			}
			else if(slob[c]) {
				oslobodi(b);
				nez.push_back(i);
			}
			else {
				if(tko[b] == -1 || tko[c] == -1) {
					if(tko[b] == -1 && tko[c] == -1) {
						tko[b] = tko[c] = i;
					}
					else {
						int r;
						if(tko[b] == -1) {
							r = daj_rod(tko[c]);
						}
						else r = daj_rod(tko[b]);
						spoji(r, i);
						tko[b] = tko[c] = i;
					}
					nez.push_back(i);
					ind[b].push_back(i);
					ind[c].push_back(i);
				}
				else {
					int rb = daj_rod(tko[b]), rc = daj_rod(tko[c]);
					if(rb == rc) continue;
					spoji(rb, i);
					spoji(rc, i);
					tko[b] = tko[c] = i;
					nez.push_back(i);
					ind[b].push_back(i);
					ind[c].push_back(i);
				}
			}
		}
		else {
			cin >> b;
			b--;
			if(slob[b]) continue;
			nez.push_back(i);
			oslobodi(b);
		}
	}
	vector <bool> imam(n, 0);
	int br_slob = 0, zbroj_vel = 0;
	REP(i, m) {
		if(slob[i]) br_slob++;
		else if(tko[i] != -1) {
			if(imam[daj_rod(tko[i])]) continue;
			zbroj_vel += vel[daj_rod(tko[i])];
			imam[daj_rod(tko[i])] = 1;
		}
	}
	//cout << br_slob << " " << zbroj_vel << endl;
	int rj = 1;
	REP(i, br_slob + zbroj_vel) rj = mult(rj, 2);
	cout << rj << " " << (int)nez.size() << endl;
	for(int i : nez) {
		cout << i + 1 << " ";
	}
	cout << endl;
	return 0;
}