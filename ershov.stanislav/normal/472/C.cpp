#include <iostream>
#include <iomanip>
#include <algorithm>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stack>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
#include <cassert>
#include <ctime>

using namespace std;

vector<pair<string, int> > ss;
int n, p[222222], pr[222222], sn[222222];

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	cin >> n;
	for (int i=0; i<n; i++) {
		string s1, s2;
		cin >> s1 >> s2;
		ss.push_back(make_pair(s1, i*2));
		ss.push_back(make_pair(s2, i*2+1));
	}
	sort(ss.begin(), ss.end());
	for (int i=0; i<ss.size(); i++) sn[ss[i].second]=i;
	for (int i=0; i<n; i++) cin >> p[i];
	for (int i=0, m=-1; i<n; i++) {
		int sn1=sn[p[i]*2-2], sn2=sn[p[i]*2-1];
		if(sn1>sn2) swap(sn1, sn2);
		if (sn1>m) m=sn1;
		else if (sn2>m) m=sn2;
		else {
			cout << "NO" << endl;
			return 0;
		}
	}
	cout << "YES";
	return 0;
}