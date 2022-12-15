#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ii, int> iii;
typedef pair<ll, ll> llll;
typedef vector<llll> vllll;

const int SIZE  = 1E5+5;
const int MOD = 1E9 + 7;
const double EPS = 1e-7;
const int INF = 0x3f3f3f3f;

ll max_health[SIZE];
ll start_health[SIZE];
ll regen[SIZE];
vllll changes[SIZE];
llll events[SIZE*5];

int main() {
	ll n, m, bounty, damage, increase, qntEventos = 0, iniciais = 0;
	scanf("%lld %lld %lld %lld %lld", &n, &m, &bounty, &increase, &damage);
	for(int i = 1; i <= n; i++) {
		scanf("%lld %lld %lld", &max_health[i], &start_health[i], &regen[i]);
	}
	for(int i = 0; i < m; i++) {
		ll enemyTemp, timeTemp, healthTemp;
		scanf("%lld %lld %lld", &timeTemp, &enemyTemp, &healthTemp);
		changes[enemyTemp].push_back(make_pair(timeTemp,healthTemp));
	}
	for(int i = 1; i <= n; i++) {
		//printf("O inimigo %lld no momento %lld tera uma mudanca de %lld\n", i, timeChange[i], healthChange[i]);
		if(max_health[i] <= damage) {
			if(increase) {
				printf("-1\n");
				return 0;
			} else {
				iniciais++;
			}
		} else {
			if(start_health[i] <= damage) iniciais++;
			ll vidaAtual = start_health[i];
			ll tempoAtual = 0;
			sort(changes[i].begin(), changes[i].end());
			if(regen[i] == 0) {
				for(int j = 0; j < changes[i].size(); j++) {
					if(changes[i][j].second > damage && vidaAtual <= damage) {
						events[qntEventos++] = make_pair(changes[i][j].first, -1);
						events[qntEventos++] = make_pair(changes[i][j].first-1, 0);
					} else if(changes[i][j].second <= damage && vidaAtual > damage) {						
						events[qntEventos++] = make_pair(changes[i][j].first, 1);
					}
					vidaAtual = changes[i][j].second;
				}
				if(vidaAtual <= damage && increase) {
					printf("-1\n");
					return 0;
				}
			} else {
				for(int j = 0; j < changes[i].size(); j++) {
					if(vidaAtual <= damage) {
						if((damage - vidaAtual)/regen[i] + 1 + tempoAtual < changes[i][j].first) {
							events[qntEventos++] = make_pair((damage - vidaAtual)/regen[i] + 1 + tempoAtual, -1);
							events[qntEventos++] = make_pair((damage - vidaAtual)/regen[i] + tempoAtual, 0);
							if(changes[i][j].second <= damage) {
								events[qntEventos++] = make_pair(changes[i][j].first, 1);
							}
						} else if(changes[i][j].second > damage) {
							events[qntEventos++] = make_pair(changes[i][j].first, -1);
							events[qntEventos++] = make_pair(changes[i][j].first-1, 0);
						}
					} else {
						if(changes[i][j].second <= damage) {
							events[qntEventos++] = make_pair(changes[i][j].first, 1);
						}
					}
					vidaAtual = changes[i][j].second;
					tempoAtual = changes[i][j].first;
				}
				if(vidaAtual <= damage) {
					events[qntEventos++] = make_pair((damage - vidaAtual)/regen[i] + tempoAtual + 1, -1);
					events[qntEventos++] = make_pair((damage - vidaAtual)/regen[i] + tempoAtual, 0);
				}
			}
		}
	}
	sort(events, events + qntEventos);
	ll best = iniciais * bounty;
	//printf("Tem %lld eventos e %lld iniciais\n", qntEventos, iniciais);
	for(int i = 0; i < qntEventos; i++) {
		iniciais += events[i].second;
		//printf("No momento %lld temos %lld vivos numa recompensa de %lld\n", events[i].first, iniciais, iniciais * (bounty + events[i].first * increase));
		if(i == qntEventos - 1 || events[i+1].first != events[i].first) best = max(best, iniciais * (bounty + events[i].first * increase));
	}
	cout << best << endl;
	return 0;
}