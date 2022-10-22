#include<bits/stdc++.h>
using namespace std;

int n, m;
int a[110];
int b[110];
bool chk[1010];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	for(int i=0; i<n; i++) {
		cin >> a[i];
		chk[a[i]]= true;
	}

	cin >> m;

	for(int i=0; i<m; i++) {
		cin >> b[i];
		chk[b[i]] = true;
	}

	for(int i=0; i<n; i++) {
		for(int j=0; j<m; j++) {
			if(chk[a[i] + b[j]]) continue;

			cout << a[i] << " " << b[j];
			return 0;
		}
	}
}