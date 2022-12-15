#include <bits/stdc++.h>
using namespace std;

const int INF = 0x3f3f3f3f;
const int SIZE = 200005;

typedef long long ll;
typedef pair<ll, ll> ii;
typedef pair<ll, ii> iii;

int main() {
	ios::sync_with_stdio(false);
	ll n, k, m, tempoChegou = 0;	
	set<ll> taxis;  //casas onde tem taxi na ordem correta
	set<ll, greater<ll> > taxisInvertido; // casas onde tem taxis na ordem invertida 
	priority_queue<ii, vector<ii>, greater<ii> > houses[SIZE]; // pra cada posicao contem : Tempo desde que o taxi esta la / numero
	priority_queue<iii, vector<iii>, greater<iii> > taxisOcupados; // cada posicao tem: tempo de inicio / numero / casa destino
	cin >> n >> k >> m;
	for(int i = 1; i <= k; i++) {
		ll x;
		cin >> x;
		if(houses[x].empty()) {
			taxis.insert(x);
			taxisInvertido.insert(x);
		}
		houses[x].push(make_pair(0, i));
	}
	for(int i = 0; i < m; i++) {
		ll t, a, b, tempoEspera = 0;
		cin >> t >> a >> b;
		while(!taxisOcupados.empty() && taxisOcupados.top().first <= t) {
			iii novoTaxiLivre = taxisOcupados.top();
			taxisOcupados.pop();
			if(houses[novoTaxiLivre.second.second].empty()) {
				taxis.insert(novoTaxiLivre.second.second);
				taxisInvertido.insert(novoTaxiLivre.second.second);
			}
			houses[novoTaxiLivre.second.second].push(make_pair(novoTaxiLivre.first, novoTaxiLivre.second.first));
		}
		if(taxis.empty()) {
			ll tf = taxisOcupados.top().first;
			tempoChegou = tf;
			while(!taxisOcupados.empty() && taxisOcupados.top().first <= tf) {
				iii novoTaxiLivre = taxisOcupados.top();
				taxisOcupados.pop();
				if(houses[novoTaxiLivre.second.second].empty()) {
					taxis.insert(novoTaxiLivre.second.second);
					taxisInvertido.insert(novoTaxiLivre.second.second);
				}
				houses[novoTaxiLivre.second.second].push(make_pair(novoTaxiLivre.first, novoTaxiLivre.second.first));
			}
		}
		auto it1 = taxis.lower_bound(a);
		auto it2 = taxisInvertido.lower_bound(a);
		ll posEscolhida;
		//return 0;
		if(it1 == taxis.end()) {
			posEscolhida = *it2;
		} else if(it2 == taxisInvertido.end()) {
			posEscolhida = *it1;
		} else if(abs(*it1 - a) < abs(*it2 - a)) {
			posEscolhida = *it1;
		} else if(abs(*it1 - a) > abs(*it2 - a)) {
			posEscolhida = *it2;
		} else {
			ll pos1 = *it1;
			ll pos2 = *it2;
			if(houses[pos1].top() < houses[pos2].top()) {
				posEscolhida = pos1;
			} else {
				posEscolhida = pos2;
			}
		}
		ii taxiEscolhido = houses[posEscolhida].top();
		houses[posEscolhida].pop();
		if(houses[posEscolhida].empty()) {
			taxis.erase(posEscolhida);
			taxisInvertido.erase(posEscolhida);
		}
		tempoEspera = max(t, tempoChegou)- t + abs(posEscolhida - a);
		taxisOcupados.push(make_pair(t+tempoEspera+abs(b-a), make_pair(taxiEscolhido.second, b)));
		cout << taxiEscolhido.second << " " << tempoEspera << endl;
	}
	return 0;
}