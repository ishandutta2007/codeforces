#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;

const int ms = 2e5+5;
typedef long long ll;

ll room[ms];

int main(){
	int n, m;
	cin >> n >> m;
	for(int i = 1; i <= n; i++) cin >> room[i];
	int dorm = 1;
	ll quarto = 0;
	for(int i = 0; i < m; i++) {
		ll x;
		cin >> x;
		while(x > quarto + room[dorm]) quarto += room[dorm++];
		cout << dorm << ' ' << x - quarto << '\n';
	}
	return 0;
}