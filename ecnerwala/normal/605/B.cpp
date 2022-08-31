#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
#define A first
#define B second

const int MAXN = 2e5;
const int MAXM = 2e5;

int N;
int M;

pair<pii, int> edges[MAXM];

pii res[MAXM];

int main() {
ios_base::sync_with_stdio(0);
	cin >> N >> M;
	for(int i = 0; i < M; i++) {
		cin >> edges[i].A.A >> edges[i].A.B;
		edges[i].A.B ^= 1;
		edges[i].B = i;
	}
	sort(edges, edges + M);

	int V = 1;
	pii cur = pii(1, 3);
	for(int i = 0; i < M; i++) {
		int e = edges[i].B;
		if(edges[i].A.B == 0) {
			res[e] = pii(V, V + 1);
			V++;
		} else {
			if(cur.B > V) {
				cout << -1 << '\n';
				return 0;
			} else {
				res[e] = cur;
				cur.A ++;
				if(cur.B - cur.A <= 1) {
					cur.B++;
					cur.A = 1;
				}
			}
		}
	}
	for(int i = 0; i < M; i++) {
		cout << res[i].A << ' ' << res[i].B << '\n';
	}
	return 0;
}