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


int n, k;
int p[1000000];
double ans = 0.0;
vector<pair<int, int> > v;
double k1;


void get(int s) {
	if (s == k) {
		int p1[10];
		for (int i = 0; i < n; i++) {
			p1[i] = p[i];
		}
		for (int i = 0; i < (int)v.size(); i++) {
			for (int j = v[i].first; j <= (v[i].second + v[i].first) / 2; j++) {
				swap(p1[j], p1[v[i].second - v[i].first - (j - v[i].first) + v[i].first]);
			}
		}
		int s1 = 0;
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				if (p1[i] > p1[j]) {
					s1++;
				}
			}
		}
		//cout << s1 << endl;
		ans += s1;
		k1+= 1.0;
		//cout << k1 << endl;
		return;
	}
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			v.push_back(make_pair(i, j));
			get(s + 1);
			v.pop_back();
		}
	}
}


int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> p[i];
	}
	get(0);
	printf("%.10lf\n", ans / k1);
  	return 0;  
}