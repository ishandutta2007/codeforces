#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
const int ms = 1e4+5;

int n, q;
iii query[ms];
int fimDeX[ms];
int fimDeX2[ms];

int main(){
	cin.tie(0);
	cin.sync_with_stdio(false);
	cin >> n >> q;
	for(int i = 0; i < q; i++) {
		cin >> query[i].first.first >> query[i].first.second >> query[i].second;
	}
	sort(query, query + q);
	for(int i = 0; i < q; i++)  {
		int pos = query[i].first.first;
		int fim = query[i].first.second;
		int x = query[i].second;
		for(int i = n - x; i >= 1; i--) {
			if(fimDeX[i] >= pos) fimDeX[i+x] = max(min(fim, fimDeX[i]), fimDeX[i+x]);
		}
		fimDeX[x] = max(fimDeX[x], fim);
	}
	int ans = 0;
	for(int i = 1; i <= n; i++) if(fimDeX[i]) ans++;
	cout << ans << endl;
	for(int i = 1; i <= n; i++) {
		if(fimDeX[i]) cout << i << ' ';
	}
	return 0;
}