#include <bits/stdc++.h>
using namespace std;

const int K = 105;

int l[K], r[K];
vector<pair<int, int> > vec[2][K << 1];

inline void addBack(vector<pair<int, int> > &vec, int lo, int hi){
	if(vec.empty() || vec.back().second + 1 < lo){
		vec.emplace_back(lo, hi);
	}else if(vec.back().second < hi){
		vec.back().second = hi;
	}
}

inline void merge(vector<pair<int, int> > &a, vector<pair<int, int> > &b, int lo, int hi){
	int sza = (int)a.size();
	int szb = (int)b.size();
	int i = 0, j = 0;
	vector<pair<int, int> > vec;
	while(i < sza || j < szb){
		if(i == sza){
			addBack(vec, b[j].first + lo, b[j].second + hi); ++j;
		}else if(j == szb){
			addBack(vec, a[i].first, a[i].second); ++i;
		}else if(a[i].first <= b[j].first + lo){
			addBack(vec, a[i].first, a[i].second); ++i;
		}else{
			addBack(vec, b[j].first + lo, b[j].second + hi); ++j;
		}
	}
	a = vec;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n, k;
	cin >> n >> k;
	for(int i = 1; i <= k; i++){
		cin >> l[i] >> r[i];
	}
	if(l[k] == 2*n){
		k--;
	}else if(r[k] == 2*n){
		r[k]--;
	}
	if(k == 0){
		cout << "Hungry" << '\n';
		exit(0);
	}
	r[0] = -1;
	int flg = 0;
	vec[0][0].emplace_back(0, 0);
	for(int i = 1; i <= k; i++){
		for(int j = 0; j < 2*i - 1; j += 2){
			for(auto &x : vec[flg][j]){
				x.first += l[i] - r[i - 1] - 1;
				x.second += l[i] - r[i - 1] - 1;
			}
		}
		int nflg = flg^1;
		for(int j = 0; j < 2*i + 1; j++){
			vec[nflg][j].clear();
		}
		int len = r[i] - l[i] + 1;
		for(int j = 0; j < 2*i - 1; j++){
			if(j&1){
				merge(vec[nflg][j], vec[flg][j], 0, 0);
				merge(vec[nflg][j + 1], vec[flg][j], 1, len);
				if(len > 1)merge(vec[nflg][j + 2], vec[flg][j], 1, len - 1);
			}else{
				merge(vec[nflg][j], vec[flg][j], len, len);
				merge(vec[nflg][j + 1], vec[flg][j], 0, len - 1);
				if(len > 1)merge(vec[nflg][j + 2], vec[flg][j], 1, len - 1);
			}
		}
		flg = nflg;
	}
	int excess = 2*n - 1 - r[k];
	for(int j = 0; j < 2*k + 1; j += 2){
		for(auto &x : vec[flg][j]){
			x.first += excess;
			x.second += excess;
		}
	}
	for(int j = 0; j < 2*k + 1; j++){
		for(auto x : vec[flg][j]){
			if(x.first <= n && n <= x.second){
				cout << "Full" << '\n';
				cout << j << '\n';
				exit(0);
			}
		}
	}
	cout << "Hungry" << '\n';
	
	return 0;
}