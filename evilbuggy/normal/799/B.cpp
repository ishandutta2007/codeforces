#include <bits/stdc++.h>
using namespace std;

const int N = 200005;
int p[N], a[N], b[N], used[N];
vector<pair<int, int> > shirta[3];
vector<pair<int, int> > shirtb[3];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		cin >> p[i];
		used[i] = 0;
	}
	for(int i = 1; i <= n; i++){
		cin >> a[i]; a[i]--;
	}
	for(int i = 1; i <= n; i++){
		cin >> b[i]; b[i]--;
	}
	for(int i = 1; i <= n; i++){
		shirta[a[i]].emplace_back(p[i], i);
		shirtb[b[i]].emplace_back(p[i], i);
	}
	for(int i = 0; i < 3; i++){
		sort(shirta[i].rbegin(), shirta[i].rend());
		sort(shirtb[i].rbegin(), shirtb[i].rend());
	}
	int m;
	cin >> m;
	for(int i = 0; i < m; i++){
		int c;
		cin >> c;
		c = c - 1;
		int ind = -1;
		while(!shirta[c].empty() && used[shirta[c].back().second]){
			shirta[c].pop_back();
		}
		while(!shirtb[c].empty() && used[shirtb[c].back().second]){
			shirtb[c].pop_back();
		}
		if(!shirta[c].empty()){
			ind = shirta[c].back().second;
		}
		if(!shirtb[c].empty()){
			if(ind == -1){
				ind = shirtb[c].back().second;
			}else if(p[ind] > shirtb[c].back().first){
				ind = shirtb[c].back().second;
			}
		}
		if(ind == -1){
			cout << -1 << ' ';
		}else{
			cout << p[ind] << ' ';
			used[ind] = 1;
		}
	}
	cout << '\n';

	return 0;
}