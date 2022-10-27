#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> zer;
	vector<pair<int, int> > pos;
	vector<pair<int, int> > neg;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		if(x == 0){
			zer.emplace_back(i);
		}else if(x > 0){
			pos.emplace_back(x, i);
		}else{
			neg.emplace_back(x, i);
		}
	}
	sort(neg.begin(), neg.end());

	if(pos.empty() && neg.size() <= 1){
		for(int i = 2; i <= n; i++){
			cout << 1 << " " << i - 1 << " " << i << '\n';
		}
	}else{
		vector<int> rem;
		vector<int> chk(n, 1);
		for(auto x : zer){
			chk[x] = 0;
			rem.emplace_back(x);
		}
		if(neg.size()&1){
			chk[neg.back().second] = 0;
			rem.emplace_back(neg.back().second);
		}
		for(int i = 1; i < (int)rem.size(); i++){
			cout << 1 << " " << rem[i] + 1 << " " << rem[0] + 1 << '\n';
		}
		if(!rem.empty()){
			cout << 2 << " " << rem[0] + 1 << '\n';
		}
		int prev = -1;
		for(int i = 0; i < n; i++){
			if(chk[i]){
				if(prev != -1){
					cout << 1 << " " << prev + 1 << " " << i + 1 << '\n';
				}
				prev = i;
			}
		}
	}

	return 0;
}