#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int ms = 1e5+5;

int deg[ms];

int main(){
	cin.tie(0);
	cin.sync_with_stdio(false);
	int ateAgr = 0;
	int n;
	cin >> n;
	for(int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		deg[a]++;
		deg[b]++;
	}
	vector<int> deg1, deg2;
	for(int i = 1; i <= n; i++) {
		if(deg[i] == 1) deg1.push_back(i);
		else if(deg[i] >= 3) deg2.push_back(i);
	}
	if(deg2.size() == 0) {
		cout << "Yes\n1\n" << deg1[0] << ' ' << deg1[1] << endl;
	} else if(deg2.size() == 1) {
		cout << "Yes\n";
		cout << deg1.size() << '\n';
		for(int i = 0; i < deg1.size(); i++) {
			cout << deg2[0] << ' ' << deg1[i] << '\n';
		}
	} else {
		cout << "No" << endl;
	}
	return 0;
}