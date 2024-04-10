#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <map>
#include <set>
#include <assert.h>


using namespace std;


int n;
int l[100000], r[100000];
vector<int> v, v1, v2;
double sum;
int t = 0;


void get(int i, int b) {
	if (i == n) { 
	//	t++;
		for (int j = 0; j < (int)v.size(); j++) {
			if (l[v[j]] > b || b > r[v[j]]) {
				return;
			}
		} 
		if (v.size() == 0) {
			return;
		}
		for (int j = 0; j < (int)v1.size(); j++) {
			if (b + 1 > r[v1[j]]) {
				return;
			}
		}
		for (int j = 0; j < (int)v2.size(); j++) {
			if (l[v2[j]] >= b) {
				return;
			}
		}
		if ((int)v1.size() >= 2) {
			return;
		}
		if ((int)v1.size() == 0 && (int)v.size() < 2) {
			return;
		}
		for (int j = 0; j < (int)v1.size(); j++) {
			if (b + 1 > r[v1[j]]) {
				return;
			}
		}
		double ans = 1.0;
		for (int j = 0; j < (int)v1.size(); j++) {
			ans *= double(r[v1[j]] - max(b + 1, l[v1[j]]) + 1) / double(r[v1[j]] - l[v1[j]] + 1);
				//	cout << "opana" << endl;
		}
		for (int j = 0; j < (int)v2.size(); j++) {
			ans *= double(min(b - 1, r[v2[j]]) - l[v2[j]] + 1) / double(r[v2[j]] - l[v2[j]] + 1);
		//	cout << "opa" << endl;
		}
		for (int j = 0; j < (int)v.size(); j++) {
			ans *= double(1) / double(r[v[j]] - l[v[j]] + 1);
				//	cout << "opana" << endl;
		}
		sum += ans;
		return;
	}
	v.push_back(i);
	get(i + 1, b);
	v.pop_back();
	v1.push_back(i);
	get(i + 1, b);
	v1.pop_back();
	v2.push_back(i);
	get(i + 1, b);
	v2.pop_back();	
}


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> l[i] >> r[i];
	}
	double ans = 0;
	for (int i = 1; i <= 10000; i++) {
		double p = 0.0;
		get(0, i);
		p = sum;
		//cout << t << endl;z
		sum = 0.0;
		//cout << p << endl;
		ans += p * i;
	}
	printf("%.10lf\n", ans);
  	return 0;  
}