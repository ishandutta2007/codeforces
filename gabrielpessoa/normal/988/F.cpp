#include<bits/stdc++.h>
using namespace std;

typedef pair<int, int> ii;
typedef long long ll;

const int ms = 2005, mv = 2e5+5, nove = 1e9, inf = 0x3f3f3f3f;
const ll mod = 1e9+7;


int pd[ms][ms];
int umb[ms];
int rain[ms];
int w[ms];

int main(){
	cin.tie(0);
	cin.sync_with_stdio(false);
	int a, n, m;
	cin >> a >> n >> m;
	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		for(int k = x ; k < y; k++) {
			rain[k] = 1;
		}
	}
	for(int i = 1; i <= m; i++) {
		int x;
		cin >> x >> w[i];
		if(umb[x] == 0 || w[umb[x]] > w[i])	umb[x] = i;
	}
	for(int i = a-1; i >= 0; i--) {
		pd[i][0] = (rain[i]) ? inf : pd[i+1][0];
		if(umb[i]) pd[i][0] = min(pd[i][0], pd[i+1][umb[i]] + w[umb[i]]);
		for(int j = 1; j <= m; j++) {
			pd[i][j] = min(pd[i][0], pd[i+1][j] + w[j]);
		}
	}
	if(pd[0][0] == inf) pd[0][0] = -1;
	cout << pd[0][0] << endl;
	return 0;
}