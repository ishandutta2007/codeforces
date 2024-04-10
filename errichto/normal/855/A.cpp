#include <bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin >> n;
	set<string> already;
	for(int i = 0; i < n; ++i) {
		string nowy;
		cin >> nowy;
		if(already.count(nowy)) puts("YES");
		else puts("NO");
		already.insert(nowy);
	}
}