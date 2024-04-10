#include <bits/stdc++.h>
using namespace std;

const int maxN = 100005;

int n, m;
vector<pair<int, int> > pts[3];

inline bool byX(pair<int, int> &a, pair<int, int> &b){
	return a.first < b.first;
}

inline bool byY(pair<int, int> &a, pair<int, int> &b){
	return a.second < b.second;
}

inline int config1(int i0, int i1, int i2){
	if(pts[i1][m - 1].first < pts[i0][0].first)return 0;
	if(pts[i2][m - 1].first < pts[i1][0].first)return 0;
	
	int ind, border;
	int lo = 1, hi = m;
	while(lo < hi){
		int mi = (lo + hi + 1) >> 1;
		border = pts[i0][mi - 1].first;
		ind = lower_bound(pts[i1].begin(), pts[i1].end(), make_pair(border + 1, INT_MIN)) - pts[i1].begin();
		if(ind + mi > m){
			hi = mi - 1;
			continue;
		}
		border = pts[i1][ind + mi - 1].first;
		ind = lower_bound(pts[i2].begin(), pts[i2].end(), make_pair(border + 1, INT_MIN)) - pts[i2].begin();
		if(ind + mi > m){
			hi = mi - 1;
		}else{
			lo = mi;
		}
	}
	return lo;
}

inline int config2(int i0, int i1, int i2){
	sort(pts[i0].begin(), pts[i0].end(), byX);
	sort(pts[i1].begin(), pts[i1].end(), byY);
	sort(pts[i2].begin(), pts[i2].end(), byY);
	bool flg1 = false, flg2 = false;
	for(int i = 0; i < m; i++){
		if(pts[i0][0].first < pts[i1][i].first)flg1 = true;
		if(pts[i0][0].first < pts[i2][i].first)flg2 = true;
	}
	if(!flg1 || !flg2)return 0;

	int lo = 1, hi = m;
	while(lo < hi){
		int mi = (lo + hi + 1) >> 1;
		int border = pts[i0][mi - 1].first;
		int mni1, mxi1, mni2, mxi2;
		bool fni1 = true;
		bool fxi1 = true;
		bool fni2 = true;
		bool fxi2 = true;
		{
			int cnt = mi;
			for(int i = 0; i < m; i++){
				if(pts[i1][i].first <= border)continue;

				cnt--;
				if(cnt == 0){
					mni1 = pts[i1][i].second;
					break;
				}
			}
			if(cnt)fni1 = false;
		}
		{
			int cnt = mi;
			for(int i = 0; i < m; i++){
				if(pts[i2][i].first <= border)continue;

				cnt--;
				if(cnt == 0){
					mni2 = pts[i2][i].second;
					break;
				}
			}
			if(cnt)fni2 = false;
		}
		{
			int cnt = mi;
			for(int i = m - 1; i >= 0; i--){
				if(pts[i1][i].first <= border)continue;

				cnt--;
				if(cnt == 0){
					mxi1 = pts[i1][i].second;
					break;
				}
			}
			if(cnt)fxi1 = false;
		}
		{
			int cnt = mi;
			for(int i = m - 1; i >= 0; i--){
				if(pts[i2][i].first <= border)continue;

				cnt--;
				if(cnt == 0){
					mxi2 = pts[i2][i].second;
					break;
				}
			}
			if(cnt)fxi2 = false;
		}
		if(fni1 && fxi2 && mni1 < mxi2){
			lo = mi;
		}else if(fni2 && fxi1 && mni2 < mxi1){
			lo = mi;
		}else{
			hi = mi - 1;
		}
	}
	return lo;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n; m = n/3;
	for(int i = 0; i < n; i++){
		int x, y, c;
		cin >> x >> y >> c;
		pts[c - 1].emplace_back(x, y);
	}
	int ans = 0;

	for(int i = 0; i < 3; i++){
		for(auto &x : pts[i]){
			swap(x.first, x.second);
		}
		sort(pts[i].begin(), pts[i].end(), byX);
	}
	ans = max(ans, config1(0, 1, 2));
	ans = max(ans, config1(0, 2, 1));
	ans = max(ans, config1(1, 0, 2));
	ans = max(ans, config1(1, 2, 0));
	ans = max(ans, config1(2, 0, 1));
	ans = max(ans, config1(2, 1, 0));
	
	for(int i = 0; i < 3; i++){
		for(auto &x : pts[i]){
			swap(x.first, x.second);
		}
		sort(pts[i].begin(), pts[i].end(), byX);
	}
	ans = max(ans, config1(0, 1, 2));
	ans = max(ans, config1(0, 2, 1));
	ans = max(ans, config1(1, 0, 2));
	ans = max(ans, config1(1, 2, 0));
	ans = max(ans, config1(2, 0, 1));
	ans = max(ans, config1(2, 1, 0));
	
	ans = max(ans, config2(0, 1, 2));
	ans = max(ans, config2(1, 0, 2));
	ans = max(ans, config2(2, 0, 1));

	for(int i = 0; i < 3; i++){
		for(auto &x : pts[i]){
			x.first = -x.first;
		}
	}

	ans = max(ans, config2(0, 1, 2));
	ans = max(ans, config2(1, 0, 2));
	ans = max(ans, config2(2, 0, 1));

	for(int i = 0; i < 3; i++){
		for(auto &x : pts[i]){
			x.first = -x.first;
			swap(x.first, x.second);
		}
	}

	ans = max(ans, config2(0, 1, 2));
	ans = max(ans, config2(1, 0, 2));
	ans = max(ans, config2(2, 0, 1));

	for(int i = 0; i < 3; i++){
		for(auto &x : pts[i]){
			x.first = -x.first;
		}
	}

	ans = max(ans, config2(0, 1, 2));
	ans = max(ans, config2(1, 0, 2));
	ans = max(ans, config2(2, 0, 1));

	cout << ans*3 << '\n';

	return 0;
}