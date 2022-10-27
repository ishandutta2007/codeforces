#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> pos;
	for(int i = 1; i <= n; i++){
		int x;
		cin >> x;
		if(x == 1)pos.emplace_back(i);
	}
	cout << pos.size() << '\n';
	pos.emplace_back(n + 1);
	for(int i = 1; i < (int)pos.size(); i++){
		cout << pos[i] - pos[i - 1] << " ";
	}
	cout << '\n';
	return 0;
}