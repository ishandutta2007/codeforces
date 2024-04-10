#include<bits/stdc++.h>
using namespace std;

int main() {
	multiset<int> s;
	for(int i = 0; i < 6; i++) {
		int v; cin >> v; s.insert(v);
	}
	for(int i : s) {
		if(s.count(i) >= 4) {

			int cnt = s.count(i) - 4;
			s.erase(i);
			for(int j = 0; j < cnt; j++) s.insert(i);

			if(s.count(*s.begin()) == 2) {
				cout << "Elephant\n";
			} else {
				cout << "Bear\n";
			}
			return 0;
		}
	}
	cout << "Alien\n";

	return 0;
}