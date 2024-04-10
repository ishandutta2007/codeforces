#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

ll A[26];
ll B[26];
ll C[26];


ll val(ll numb) {
	ll numc = 10000000000;
	for(ll i = 0; i < 26; i++) {
		if(numb * B[i] > A[i]) return -1;
		if(C[i]) numc = min(numc, (A[i] - numb * B[i]) / C[i]);
	}
	return numb + numc;
}

int main() {
	ios_base::sync_with_stdio(0);
	string a, b, c;
	cin >> a >> b >> c;
	for(char x : a) A[x - 'a'] ++;
	for(char x : b) B[x - 'a'] ++;
	for(char x : c) C[x - 'a'] ++;

	ll best = 0;
	ll bestb = 0;
	for(ll numb = 0; true; numb++) {
		ll cnd = val(numb);
		if(cnd == -1) break;
		if(cnd > best) {
			best = cnd;
			bestb = numb;
		}
	}
	
	best -= bestb;

	for(ll i = 0; i < bestb; i++) {
		cout << b;
	}

	for(ll i = 0; i < best; i++) {
		cout << c;
	}

	for(ll i = 0; i < 26; i++) {
		ll cnt = A[i] - bestb * B[i] - best * C[i];
		while(cnt --) {
			cout << char(i + 'a');
		}
	}

	cout << '\n';

	return 0;
}