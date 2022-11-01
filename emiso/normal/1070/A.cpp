#include <bits/stdc++.h>

using namespace std;

int d, s;
int dist[5050][505], prv[5050][505], pm[5050][505];

#define pii pair < int, int >
#define INF 100000000

void bfs() {
	for (int i = 0; i < 5050; i++)
		for (int j = 0; j < 505; j++) {
			dist[i][j] = INF;
			prv[i][j] = -1;
		}
		
	queue < pii > fila;
	fila.push(pii(0, 0));
	dist[0][0] = 0;
	
	while (!fila.empty()) {
		pii u = fila.front();
		fila.pop();
		
		if (u == pii(s, 0)) {
			string ans = "";
			int a = s, b = 0;
			while (prv[a][b] != -1) {
				int x = prv[a][b];
				ans += x + '0';
				b = pm[a][b];
				a -= x;
			}
			
			reverse(ans.begin(), ans.end());
			cout << ans << endl;
			return;
		}
		
		if (u.first > s) continue;
		
		for (int i = (u.first == 0); i < 10; i++)
			if (dist[u.first+i][(u.second*10 + i)%d] > dist[u.first][u.second] + 1) {
				dist[u.first+i][(u.second*10 + i)%d] = dist[u.first][u.second] + 1;
				prv[u.first+i][(u.second*10 + i)%d] = i;
				pm[u.first+i][(u.second*10 + i)%d] = u.second;
				
				fila.push(pii(u.first+i, (u.second*10 + i)%d));
			}
	}
	
	printf("-1\n");
}

int main() {
	scanf("%d %d", &d, &s);
	bfs();
	return 0;
}