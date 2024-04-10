#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n; cin >> n;
	int m; cin >> m;
	int k; cin >> k;
	int flgg = 0;
	int flgr = 0;
	vector<int> sum(30);
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		int ind1 = -1;
		int ind2 = -1;
		for(int j = 0; j < m; j++){
			if(s[j] != '-'){
				if(ind1 == -1){
					ind1 = j;
				}else{
					ind2 = j;
				}
			}
		}
		if(ind1 == -1)continue;
		if(ind2 == -1){
			if(m > 1){
				if(s[ind1] == 'R')flgr = 1;
				if(s[ind1] == 'G')flgg = 1;
			}
		}else{
			if(s[ind1] == s[ind2]){
				if(m > 2){
					if(s[ind1] == 'R')flgr = 1;
					if(s[ind1] == 'G')flgg = 1;
				}
			}else{
				int len = abs(ind1 - ind2) - 1;
				for(int i = 0; i < 30; i++){
					sum[i] += (len >> i) & 1;
				}
			}
		}
	}
	bool flg = false;
	for(int i = 0; i < 30; i++){
		if(sum[i]%(k + 1))flg = true;
	}
	if(flgg && flgr){
		cout << "Draw" << '\n';
	}else if(flgg){
		cout << "First" << '\n';
	}else if(flgr){
		cout << "Second" << '\n';
	}else if(flg){
		cout << "First" << '\n';
	}else{
		cout << "Second" << '\n';
	}

	return 0;
}