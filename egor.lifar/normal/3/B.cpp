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

using namespace std;


struct boat{
	long long type, mass, number;
};


boat a[100000];
vector<boat> v[2];


bool les(const boat a, const boat b) {
	return (a.mass > b.mass); 
}

int main() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
    	cin >> a[i].type >> a[i].mass;
    	a[i].number = i + 1;
    	v[a[i].type - 1].push_back(a[i]);
    }
    sort(v[0].begin(), v[0].end(), les);
    sort(v[1].begin(), v[1].end(), les);
    long long s = 0; 
    int d[2][100000];
    if (v[0].size() >= 1){
    	d[0][0] = v[0][0].mass;
	}
	if (v[1].size() >= 1) {
    	d[1][0] = v[1][0].mass;
	}
    for (int i = 1; i < v[0].size(); i++) {
    	d[0][i] = d[0][i - 1] + v[0][i].mass;
    }
    for (int i = 1; i < v[1].size(); i++) {
    	d[1][i] = d[1][i - 1] + v[1][i].mass;
    }
    int j = -1;
    if (m >= 2) {
    	s = d[1][min(m / 2, (int)v[1].size()) - 1];
	}
    for (int i = 0; i < min((int)v[0].size(), m); i++) {
    	int k1 = i + 1;
    	int k2 = min((m - k1) / 2, (int)v[1].size());
    	long long s1 = 0;
    	if (k2 - 1 >= 0){
        	s1 = d[0][k1 - 1] + d[1][k2 - 1];
    	}else {
    		s1 = d[0][k1 - 1];
    	}
    	if (s < s1) {
    		j = i;
    		s = s1;
    	}
    }
    int k1 = j + 1;
   	int k2 = min((m - k1) / 2, (int)v[1].size());
   	cout << s << endl;
   	for (int i = 0; i < k1; i++) {
   		cout << v[0][i].number << ' ';
   	}
   	for (int i = 0; i < k2; i++) {
   		cout << v[1][i].number;
   		if (i < k2 - 1){
   			cout << ' ';
   		}
   	}
   	cout << endl;
	return 0;
}