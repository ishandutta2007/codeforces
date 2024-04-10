#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

using namespace std;

int n,k;
int a[1100];
int dist[3000];

int main() {
	scanf("%d %d", &k, &n);
	REP(i,n) {
		int b; scanf("%d", &b);
		a[b] = 1;
	}

	memset(dist,-1,sizeof(dist));

	queue<int> q;
	for (int i = 0; i <= 1000; i++) if (a[i]) {
		dist[i - k + 1500] = 1;
		q.push(i - k + 1500);
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();

		for (int i = 0; i <= 1000; i++) if (a[i]) {
			int nxt = cur + i - k;
			//printf("%d -> %d\n", cur,nxt);
			if (nxt < 0 || nxt >= 3000) continue;
			if (dist[nxt] != -1) continue;

			dist[nxt] = dist[cur] + 1;
			q.push(nxt);
		}
	}

	printf("%d\n", dist[1500]);
}