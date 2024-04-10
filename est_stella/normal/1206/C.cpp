#include<bits/stdc++.h>
using namespace std;

int n;
int ans[200010];

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> n;

	if(n%2==0) {
		cout << "NO";
		return 0;
	}

	cout << "YES" << "\n";

	for(int i=0; i<n; i++) {
		if(i%2==0) ans[i] = i*2+1, ans[i+n] = i*2+2;
		else ans[i] = i*2+2, ans[i+n] = i*2+1;
	}

	for(int i=0; i<2*n; i++) {
		cout << ans[i] << " ";
	}
}