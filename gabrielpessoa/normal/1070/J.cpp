#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 0x3f3f3f3f;
const int ms = 1e6+5;

int n, m, k;
int qnt[300];
int pd[300][30005];
string s;

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int T;
	cin >> T;
	while(T--) {
		memset(qnt, 0, sizeof qnt);
		cin >> n >> m >> k;
		cin >> s;
		for(char c : s) qnt[c]++;
		int ans = inf;
		for(int k = 'A'; k <= 'Z'; k++) {
			for(int j = 1; j <= n; j++) {
				int qnt2 = max(0, m - ((int) s.size() - qnt[k] - (n-j)));
				if(j + qnt2 <= qnt[k]) pd['A'-1][j] = j * qnt2;
				else pd['A'-1][j] = inf;
				//cout << (char) k << ' ' << " se sobrar " << j << " do lado do N entao fica " << pd['A'-1][j] << " pois faltam pro ouro " << qnt2 << endl;
			}
			for(int i = 'A'; i <= 'Z'; i++) {
				if(i == k) {
					for(int j = 1; j <= n; j++) {
						pd[i][j] = pd[i-1][j];
					}
					continue;
				}
				for(int j = 1; j <= n; j++) {
					pd[i][j] = pd[i-1][j];
					
					if(j > qnt[i]) {
						pd[i][j] = min(pd[i][j], pd[i-1][j-qnt[i]]);
					} else {
						int qnt2 = max(0, m - ((int) s.size() - qnt[k] - (n - (j - qnt[i]))));
						if(qnt2 <= qnt[k]) {
							pd[i][j] = 0;							
							//cout << (char) k << ' ' << (char) i << ' ' << j << ' ' << pd[i][j] << ' ' << qnt2 << endl;
						}
					}
				}
			}
			//if(pd['Z'][n] == 0) cout << (char) k << endl;
			ans = min(ans, pd['Z'][n]);
		}
		cout << ans << '\n';
	}
}