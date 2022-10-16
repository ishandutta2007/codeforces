#include <bits/stdc++.h> 

using namespace std;

typedef long long ll; 
typedef pair<int, int> pii;

#define REP(i,n) for(int(i)=0;(i)<(int)(n);(i)++)

using namespace std;

int n,m,q;
int a[210000];
int nxt[210000][20];
int loc[210000];
int p[210000];
int rp[210000];
int ans[210000];

pair< pii, int > queries[210000];

int main() {
	scanf("%d %d %d", &n, &m, &q);
	for (int i = 0; i < n; i++) {
		scanf("%d", &p[i]); p[i]--;
		rp[p[i]] = i;
	}
	for (int i = 0; i < m; i++) {
		scanf("%d", &a[i]); a[i]--;
		a[i] = rp[a[i]];
	}
	for (int i = 0; i < q; i++) {
		int l, r;
		scanf("%d %d", &l, &r); r--; l--;
		queries[i] = { {r, l}, i };
	}

	memset(loc,-1,sizeof(loc));
	for (int i = 0; i < m; i++) {
		int prev = (a[i]+n-1)%n;
		nxt[i][0] = loc[prev];
		loc[a[i]] = i;
	}

	for (int lvl = 1; lvl < 20; lvl++) {
		for (int i = 0; i < m; i++) {
			if (nxt[i][lvl-1] == -1) nxt[i][lvl] = -1;
			else nxt[i][lvl] = nxt[nxt[i][lvl-1]][lvl-1];
		}
	}

	sort(queries, queries+q);
	int cur_query = 0;
	int best = -1;

	for (int i = 0; i < m; i++) {
		int cur = i;
		for (int lvl = 0; lvl < 20; lvl++) if ((1<<lvl)&(n-1)) cur = nxt[cur][lvl]; 
		//printf("%d -> %d (%d %d)\n", i, cur, nxt[i][1], nxt[i][0]);
		best = max(best, cur);

		for (; cur_query < q && queries[cur_query].first.first == i; cur_query++) {
			//printf("processing %d %d (b = %d)\n", queries[cur_query].first.second, queries[cur_query].first.first, best);
			ans[queries[cur_query].second] = (best >= queries[cur_query].first.second);
		}
	}

	for (int i = 0; i < q; i++) {
		printf("%d", ans[i]);
	}
}