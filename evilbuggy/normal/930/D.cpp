#include <bits/stdc++.h>
using namespace std;

const int N = 400005;
vector<int> ycoords[N];
vector<pair<int, int> > black[2];

int prefmin[N], prefmax[N], suffmin[N], suffmax[N];

inline int count(int lo, int hi, int p){
	if((lo&1) != p){
		return (hi - lo + 1)/2;
	}else{
		return (hi - lo + 2)/2;
	}
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int n;
	cin >> n;
	for(int i = 1; i <= n; i++){
		int x, y;
		cin >> x >> y;
		x += 100000; y += 100000;
		black[(x + y)&1].emplace_back(y + x, y - x);
	}
	long long answer = 0;
	for(int p : {0, 1}){
		for(auto x : black[p]){
			ycoords[x.first].emplace_back(x.second);
		}
		prefmax[0] = suffmax[N - 1] = -1e9;
		prefmin[0] = suffmin[N - 1] = +1e9;
		for(int i = 0; i + 1 < N; i++){
			prefmax[i + 1] = prefmax[i];
			prefmin[i + 1] = prefmin[i];
			for(auto y : ycoords[i]){
				prefmax[i + 1] = max(prefmax[i + 1], y);
				prefmin[i + 1] = min(prefmin[i + 1], y);
			}
		}
		for(int i = N - 1; i > 0; i--){
			suffmax[i - 1] = suffmax[i];
			suffmin[i - 1] = suffmin[i];
			for(auto y : ycoords[i]){
				suffmax[i - 1] = max(suffmax[i - 1], y);
				suffmin[i - 1] = min(suffmin[i - 1], y);
			}
		}
		for(int X = p^1; X < N; X += 2){
			if(prefmin[X] >= prefmax[X])continue;
			if(suffmin[X] >= suffmax[X])continue;
			int lo = max(prefmin[X], suffmin[X]);
			int hi = min(prefmax[X], suffmax[X]);
			if(lo > hi)continue;
			answer += count(lo, hi, p^1);
		}
		for(int i = 0; i < N; i++){
			ycoords[i].clear();
		}
	}
	cout << answer << '\n';

	return 0;
}