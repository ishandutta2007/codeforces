#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int SIZE = 5005;
const ll INF = 0x3f3f3f3f3f3f3f3f;

ll arr[SIZE];
ll dif[SIZE];
ll valor[SIZE];
ll leftt[SIZE];
ll rightt[SIZE];
ll tipo[SIZE];

int main() {
	int n, m;
	cin >> n >> m;
	for(int i = 1; i<= n; i++) {
		arr[i] = INF;
	}
	for(int k = 0; k < m; k++) {
		int t, l, r;
		ll m;
		cin >> t >> l >> r >> m;
		if(t == 1) {
			for(int i = l; i <= r; i++) {
				dif[i] += m;
			}
			leftt[k] = l;
			rightt[k] = (r);
			valor[k] = (m);
			tipo[k] = (1);
		} else {
			for(int i = l; i <= r; i++) {
				arr[i] = min(arr[i], m - dif[i]);
			}
			leftt[k] = l;
			rightt[k] = (r);
			valor[k] = (m);
			tipo[k] = (2);
		}
	}
	for(int i = 1; i <= n; i++) {
		if(arr[i] == INF) arr[i] = -1E9;
		dif[i] = 0;	
	}
	for(int i = 0; i < m; i++) {
		if(tipo[i] == 2) {
			ll maior = -2E10;
			for(int j = leftt[i]; j <= rightt[i]; j++) {
				maior = max(maior, arr[j] + dif[j]);
			}
			if(maior != valor[i]) {
				cout << "NO\n";
				return 0;
			}
		} else {
			for(int j = leftt[i]; j <= rightt[i]; j++) {
				dif[j] += valor[i];
			}
		}
		
	}
	for(int i = 1; i <= n; i++) {
		if(abs(arr[i]) > 1E9) {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
	for(int i = 1; i <= n; i++) cout << arr[i] << ' ';
	cout << '\n';
	return 0;
}