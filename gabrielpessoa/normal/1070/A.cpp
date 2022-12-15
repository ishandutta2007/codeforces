#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
const int ms = 1e6+5;

int dist[512][5123];
int ant[512][5123];
pair<int, int> posAnt[512][5123];
int ans[ms];
int z = 0;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	memset(dist, 63, sizeof dist);
	queue<pair<int, int>> q;
	q.push({0, 0});
	dist[0][0] = 0;
	int d, s;
	cin >> d >> s;
	while(!q.empty()) {
		int md = q.front().first;
		int soma = q.front().second;
		q.pop();
		int nmd = 10*md % d;
		for(int i = 0; i < 10; i++) {
			int novoMd = (nmd + i) % d;
			if(soma + i <= s && dist[novoMd][soma+i] > dist[md][soma] + 1) {
				dist[novoMd][soma+i] = dist[md][soma] + 1;
				ant[novoMd][soma+i] = i;
				posAnt[novoMd][soma+i] = {md, soma};
				q.push({novoMd, soma + i});
			}
		}
		//cout << md << ' ' << soma << ' ' <<dist[md][soma] << endl;
	}
	if(dist[0][s] == inf) {
		cout << -1 << endl;
	} else {
		int md = 0;
		while(md || s) {
			ans[z++] = ant[md][s];
			auto p = posAnt[md][s];
			md = p.first;
			s = p.second;
		}
		for(int i = z - 1; i >= 0; i--) cout << ans[i];
		cout << '\n';
	}
}