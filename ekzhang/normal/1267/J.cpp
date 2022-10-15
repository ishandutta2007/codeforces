#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

int eval(int n, int s){
	//fewest number of screens needed for s, s - 1
	if (n % (s - 1) > n / (s - 1)){
		return -1;
	}
	return (n + s - 1) / s;
}

int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t; cin >> t;
	for (int i = 0; i < t; i++){
		int n; cin >> n;
		map<int, int> counts;
		for (int j = 0; j < n; j++){
			int x; cin >> x;
			counts[x]++;
		}

		map<int, int> counts2;
		int mn = 3204214;
		for (pii v: counts){
			counts2[v.second]++;
			if (v.second < mn){
				mn = v.second;
			}
		}

		int res = -1;
		for (int cand = 2; cand <= mn + 1; ++cand){
			int tmp = 0;
			bool valid = true;
			for (pii v: counts2){
				int r = eval(v.first, cand);
				if (r == -1){
					valid = false;
					break;
				}
				tmp += v.second * eval(v.first, cand); 
			}
			if (valid == true){
				if ((tmp < res) || (res == -1)){
					res = tmp;
				}
			}
		}
		cout << res << endl;
	}	
}