#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const int ms = 2e5 + 5, me = 1e6+5, z = 0;

ll hp[ms];
ll dmg[ms];
bool used[ms];
ii aux[ms];

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll n, a, b;
	cin >> n >> a >> b;
	ll soma = 0;
	for(int i = 0; i < n; i++) {
		cin >> hp[i] >> dmg[i];
		aux[i] = ii(hp[i] - dmg[i], i);
		soma += dmg[i];
	}
	if(!b) {
		cout << soma << '\n';
		return 0;
	}
	//cout << soma << '\n';
	sort(aux, aux + n);
	ll ganhoExtra = 0;
	for(int i = n - 1; i >= 0; i--) {
		if(aux[i].first <= 0) break;
		if(b > 1) {
			soma += aux[i].first;
			used[aux[i].second] = true;
			b--;
		} else {
			ganhoExtra = aux[i].first;
			break;
		}
	}
	if(!a) {
		cout << soma + ganhoExtra << '\n';
		return 0;
	}
	//cout << soma << ' ' << ganhoExtra << '\n';
	ll melhorDobrando = ganhoExtra;
	for(int i = 0; i < n; i++) {
		ll ganhoDobro = (1 << a) * hp[i] - dmg[i];
		if(used[i]) {
			ganhoDobro -= hp[i] - dmg[i];
			ganhoDobro += ganhoExtra;
			melhorDobrando = max(melhorDobrando, ganhoDobro);
		} else {
			melhorDobrando = max(melhorDobrando, ganhoDobro);
		}
	}
	cout << melhorDobrando + soma << '\n';
}