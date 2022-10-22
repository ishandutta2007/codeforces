#include <bits/stdc++.h>
using namespace std;

struct cmp {
	bool operator() (pair<int,int> a, pair<int,int> b) {
		return a.first < b.first;
	}
};

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	int people; cin >> people;
	pair<int,int> rock[people];
	vector<pair<int,int> > pp;
	for (int i = 0; i < people; i++)
		cin >> rock[i].first;
	for (int i = 0; i < people; i++)
		cin >> rock[i].second;
	for (int i = 0; i < people; i++)
		pp.push_back(rock[i]);
	sort(pp.begin(), pp.end(), cmp());
	
	double mid, tleft, tright;
	tleft = 0; tright = 1;
	double left = pp[0].first;
	double right = pp[people-1].first;
	while (abs(tleft + tright) > 0.00000001) {
	//for (int t = 0; t < 10000000; t++) {
		mid = (right+left)/2;
		tleft = tright = 0;
		for (int i = 0; i < people; i++) {
			if ((mid - pp[i].first) / pp[i].second > tleft)
				tleft = (mid - pp[i].first) / pp[i].second;
			if ((mid - pp[i].first) / pp[i].second < tright)
				tright = (mid - pp[i].first) / pp[i].second;
		}
		if (tleft + tright > 0)
			right = mid;
		else if (tleft + tright < 0)
			left = mid;
		else 
			break;
	}
	tleft = tright = 0;
	for (int i = 0; pp[i].first < mid; i++) {
		if ((mid - pp[i].first) / pp[i].second > tleft)
			tleft = (mid - pp[i].first) / pp[i].second;
		if ((mid - pp[i].first) / pp[i].second < tright)
			tright = (mid - pp[i].first) / pp[i].second;
	}
	tright = -tright;

	cout << setprecision(10) << ((tleft > tright) ? tleft : tright) << endl;
	
	return 0;
}