#include <bits/stdc++.h>
using namespace std;

int a[105][105];
vector<int> min_set;
int sz = 3000;
typedef pair<int, int> pii;

int main(){
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++){
		for (int j = 0; j < n; j++){
			cin >> a[i][j];
		}
	}

	for (int j = 0; j < n - 1; j++){
		//compute the fewest needed to lose to candidate j
		vector<pii> diffs; 
		for (int i = 0; i < m; i++){
			diffs.push_back(make_pair(a[i][j] - a[i][n - 1], i));
		}	
		sort(diffs.begin(), diffs.end());
		reverse(diffs.begin(), diffs.end());
		int sm = 0;
		for (int i = 0; i < m; i++){
			sm += diffs[i].first;
			if (sm < 0){
				//can't include this eleemnt
				vector<int> tmp_set;
				for (int k = i; k < m; k++){
					tmp_set.push_back(diffs[k].second);
				}
				if (tmp_set.size() < sz){
					min_set = tmp_set;
					sz = tmp_set.size();
				}
				break;
			}
			if (i == m - 1){
				vector<int> tmp_set;
				min_set = tmp_set;
				sz = 0;
			}
		}
		
	}
	cout << sz << endl;
	for (int i = 0; i < min_set.size(); i++){
		cout << min_set[i] + 1;
		if (i != min_set.size() - 1){
			cout << ' ';
		}
	}
	cout << endl;
}