#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int ms = 1e3+5, inf = 0x3f3f3f3f;
typedef long long ll;
typedef pair<int, int> ii;

int s[ms], d[ms], c[ms];
int dias[ms];

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 0; i < m; i++) {
		cin >> s[i] >> d[i] >> c[i];
	}
	for(int i = 1; i <= n; i++) {
		for(int j = 0; j < n; j++) {
			if(d[j] == i) {
				dias[i] = m + 1;
				for(int k = s[j]; k < i; k++) {
					if(c[j] && !dias[k]) {
						dias[k] = j + 1;
						c[j]--;
					}
				}
				if(c[j]) {
					cout << -1 << '\n';
					return 0;
				}
			}
		}
	}
	for(int i = 1; i <= n; i++) {
		cout << dias[i] << ' ';
	}
	cout << '\n';

	return 0;
}