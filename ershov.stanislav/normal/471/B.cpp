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

int n, c[3000], h[3000];
vector<int> t[3000];

int main() {
#ifndef ONLINE_JUDGE
	//freopen("in.txt", "r", stdin);
#endif
	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> h[i];
		c[h[i]]++;
		t[h[i]].push_back(i+1);
	}
	for (int i=1; i<=2000; i++) {
		if (c[i]>=3) {
			cout << "YES" << endl;
			for (int j=0; j<3000; j++) for (int k=0; k<t[j].size(); k++) cout << t[j][k] << ' ';
			cout << endl;
			for (int j=0; j<3000; j++) {
				if (j!=i) for (int k=0; k<t[j].size(); k++) cout << t[j][k] << ' ';
				else {
					cout << t[j][1] << ' ' << t[j][0] << ' ';
					for (int k=2; k<t[j].size(); k++) cout << t[j][k] << ' ';
				}
			}
			cout << endl;
			for (int j=0; j<3000; j++) {
				if (j!=i) for (int k=0; k<t[j].size(); k++) cout << t[j][k] << ' ';
				else {
					cout << t[j][2] << ' ' << t[j][1] << ' ' << t[j][0] << ' ';
					for (int k=3; k<t[j].size(); k++) cout << t[j][k] << ' ';
				}
			}
			return 0;
		}
	}
	int t1=0, t2=0;
	for (int i=1; i<2000; i++) {
		if (t1&&c[i]>=2) {
			t2=i;
			cout << "YES" << endl;
			for (int j=0; j<3000; j++) for (int k=0; k<t[j].size(); k++) cout << t[j][k] << ' ';
			cout << endl;
			for (int j=0; j<3000; j++) {
				if (j!=t1) for (int k=0; k<t[j].size(); k++) cout << t[j][k] << ' ';
				else {
					cout << t[j][1] << ' ' << t[j][0] << ' ';
					for (int k=2; k<t[j].size(); k++) cout << t[j][k] << ' ';
				}
			}
			cout << endl;
			for (int j=0; j<3000; j++) {
				if (j!=t2) for (int k=0; k<t[j].size(); k++) cout << t[j][k] << ' ';
				else {
					cout << t[j][1] << ' ' << t[j][0] << ' ';
					for (int k=3; k<t[j].size(); k++) cout << t[j][k] << ' ';
				}
			}
			return 0;
		}
		if (!t1&&c[i]>=2) t1=i;
	}
	cout << "NO";
	return 0;
}