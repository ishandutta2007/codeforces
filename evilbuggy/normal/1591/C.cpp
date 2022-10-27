#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t;
	cin >> t;
	while(t--){
		int n, k;
		cin >> n >> k;
		vector<int> neg, pos;
		for(int i = 0; i < n; i++){
			int x;
			cin >> x;
			if(x > 0){
				pos.emplace_back(x);
			}
			if(x < 0){
				neg.emplace_back(-x);
			}
		}
		sort(pos.begin(), pos.end());
		sort(neg.begin(), neg.end());
		
		int sp = (int)pos.size();
		int sn = (int)neg.size();
		long long sump = 0;
		long long sumn = 0;
		for(int i = sp - 1; i >= 0; i -= k){
			sump += pos[i];
		}
		for(int i = sn - 1; i >= 0; i -= k){
			sumn += neg[i];
		}
		long long remp = 0;
		long long remn = 0;
		if(sp)remp = pos.back();
		if(sn)remn = neg.back();
		cout << sump + sump + sumn + sumn - max(remp, remn) << '\n';
	}

	return 0;
}