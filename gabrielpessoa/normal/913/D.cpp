#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef pair<ii, int> iii;

const int SIZE  = 2E5+5;
const int MOD = 1E9 + 7;
const double EPS = 1e-7;
const int INF = 0x3f3f3f3f;

iii problemas[SIZE];
vi probs[SIZE];
//set<int> resposta;
//set<int> setAtual;
int n;

int main() {
	int t;
	scanf("%d %d", &n, &t);
	for(int i = 0; i < n; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		problemas[i] = iii(ii(y, x), i + 1);
	}
	sort(problemas, problemas+n);
	int melhor = 0;
	int atual = 0;
	int tempoAtual = 0;
	for(int i = 0; i < n; i++) {
		if(problemas[i].first.second <= melhor) continue;
		tempoAtual += problemas[i].first.first;
		probs[problemas[i].first.second].push_back(i);
		//setAtual.insert(problemas[i].second);
		for(int x : probs[atual]) {
			tempoAtual -= problemas[x].first.first;
			//setAtual.erase(problemas[x].second);
		}
		int tempAtual = atual;
		atual -= probs[atual].size();
		probs[tempAtual].clear();
		atual++;
		//printf("Atual = %d Tempo = %d\n", atual, tempoAtual);
		if(atual > melhor && tempoAtual <= t) {
			melhor = atual;
			//resposta = setAtual;
		}
	}
	printf("%d\n%d\n", melhor, melhor);
	int qntAteAgora = 0;
	for(int i = 0; i < n; i++) {
		if(qntAteAgora == melhor) break;
		if(problemas[i].first.second < melhor) continue;
		qntAteAgora++;
		printf("%d ", problemas[i].second);
	}
	printf("\n");
	return 0;
}