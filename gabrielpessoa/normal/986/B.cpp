#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;
const int ms = 1e6+5;

int a[ms];

int main(){
	cin.tie(0);
	cin.sync_with_stdio(false);
	int n;
	cin >> n;
	int ans = 0;
	for(int i = 1; i <= n; i++) cin >> a[i];
	for(int i = 1; i <= n; i++) {
		while(a[i] != i) {
			swap(a[i], a[a[i]]);
			ans++;
		}
	}
	if((ans & 1) == (n & 1)) {
		cout << "Petr\n";
	} else {
		cout << "Um_nik\n";
	}
	return 0;
}