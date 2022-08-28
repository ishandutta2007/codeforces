#include <cmath>
#include <cstdio>

#include <iostream>
#include <vector>
#include <map>

using namespace std;

typedef long long ll;

int n, m;

map<string, string> mp;

int main() {
	cin >> n >> m;

	while (n--) {
		string name, ips;
		cin >> name >> ips;
		mp.insert(make_pair(ips, name));
	}

	while (m--) {
		string command, ips;
		cin >> command >> ips;
		ips.erase(ips.size() - 1);
		cout << command << " " << ips << "; #" << mp[ips] << endl;
	}

	return 0;
}