#include <bits/stdc++.h>
using namespace std;

#define REP(i, n) for(int i = 0; i < (n); i++)
typedef long long int ll;

set <int> svi;
set <int> :: iterator it;
multiset <int> raz;
int suma = 0;

void ubaci(int x) {
	if(!svi.size()) {
		svi.insert(x);
		return;
	}
	it = svi.lower_bound(x);
	if(it == svi.begin()) {
		raz.insert(-((*it) - x));
		suma += (*it) - x;
	}
	else if(it == svi.end()) {
		it--;
		raz.insert(-(x - (*it)));
		suma += x - *it;
	}
	else {
		int pom = *it;
		it--;
		raz.erase(raz.find((*it) - pom));
		suma -= pom - (*it);
		raz.insert(x - pom);
		raz.insert((*it) - x);
		suma += pom - x;
		suma += x - *it;
	}
	svi.insert(x);
	return;
}

void izbaci(int x) {
	it = svi.lower_bound(x);
	if(it == svi.begin()) {
		it++;
		if(it != svi.end()) {
			raz.erase(raz.find(x - (*it)));
			suma -= (*it) - x;
		}
	}
	else {
		it--;
		int pom = *it;
		it++;
		it++;
		if(it == svi.end()) {
			raz.erase(raz.find(pom - x));
			suma -= x - pom;
		}
		else {
			raz.erase(raz.find(x - (*it)));
			raz.erase(raz.find(pom - x));
			suma -= (*it) - x;
			suma -= x - pom;
			suma += (*it) - pom;
			raz.insert(pom - (*it));
		}
	}
	svi.erase(x);
	return;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, q;
	cin >> n >> q;
	int a, b;
	REP(i, n) {
		cin >> a;
		ubaci(a);
	}
	if(raz.size()) {
		cout << suma + *(raz.begin()) << "\n";
	}
	else {
		cout << suma << "\n";
	}
	REP(qq, q) {
		cin >> a >> b;
		if(a == 1) ubaci(b);
		else izbaci(b);
		if(raz.size()) {
			cout << suma + *(raz.begin()) << "\n";
		}
		else {
			cout << suma << "\n";
		}
	}
	return 0;
}