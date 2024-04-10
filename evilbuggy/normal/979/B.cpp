#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	vector<int> scores(3);
	for(int i = 0; i < 3; i++){
		string s;
		cin >> s;
		int mx = 0;
		map<char, int> f;
		int m = (int)s.size();
		for(auto ch : s){
			f[ch]++;
			mx = max(mx, f[ch]);
		}
		if(n == 0){
			scores[i] = mx;
		}else if(f.size() == 1){
			if(n > 1)scores[i] = m;
			else scores[i] = max(m - 1, 1);
		}else{
			scores[i] = min(m, mx + n);
		}
	}
	int mx = *max_element(scores.begin(), scores.end());
	int ind = -1;
	for(int i = 0; i < 3; i++){
		if(scores[i] == mx){
			if(ind != -1){
				cout << "Draw" << '\n';
				exit(0);
			}
			ind = i;
		}
	}
	if(ind == 0){
		cout << "Kuro" << '\n';
	}else if(ind == 1){
		cout << "Shiro" << '\n';
	}else{
		cout << "Katie" << '\n';
	}

	return 0;
}