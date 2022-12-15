#include <bits/stdc++.h>
using namespace std;

const int inf = 0x3f3f3f3f;
const int ms = 1e6+5;

pair<int, string> a[ms];

int main(){
	ios::sync_with_stdio(0); cin.tie(0);
	int n;
	int soma = 0;
	int alice = 0, bob = 0;
	cin >> n;
	for(int i = 0; i < n; i++) {
		cin >> a[i].second >> a[i].first;
		soma += a[i].first;
		if(a[i].second[0] == '1') alice++;
		if(a[i].second[1] == '1') bob++;
	}
	sort(a, a + n);
	int m = min(min(alice, bob) * 2, n);
	int qnt = m / 2;
	int i = -1;
	while(m < n) {
		i++;
		//cout << m << ' ' << n << ' ' << i << endl;
		if(a[i].second[0] == '1' && alice == qnt) {
			continue;
		}
		if(a[i].second[1] == '1') {
			if(bob == qnt) continue;
			bob--;
		}
		if(a[i].second[0] == '1') {
			alice--;
		}
		soma -= a[i].first;
		n--;
	}
	cout << soma << endl;
}