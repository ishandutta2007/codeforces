#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> a(n);
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	vector<int> ind;
	vector<int> b(n);
	if(a[0] == 0){
		ind.emplace_back(0);
	}else if(a[0] == 1){
		b[0] = 0;
	}else{
		cout << -1 << '\n';
		return 0;
	}
	for(int i = 1; i < n; i++){
		if(a[i] == a[i - 1]){
			ind.emplace_back(i);
		}else{
			int diff = a[i] - a[i - 1] - 1;
			if(diff > (int)ind.size()){
				cout << -1 << '\n';
				return 0;
			}
			for(int j = a[i - 1] + 1; j < a[i]; j++){
				int k = ind.back(); ind.pop_back();
				b[k] = j;
			}
			b[i] = a[i - 1];
		}
	}
	while(!ind.empty()){
		b[ind.back()] = n + n; ind.pop_back();
	}
	for(int i = 0; i < n; i++){
		cout << b[i] << ' ';
	}
	cout << '\n';

	return 0;
}