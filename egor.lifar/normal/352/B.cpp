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

int main() {
	int n, a[100001];
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	vector<int> s, v[100001];
	for (int i = 0; i < n; i++) {
		s.push_back(a[i]);
	}
	sort(s.begin(), s.end());
	vector<int>::iterator it;
    it = unique(s.begin(), s.end());
    s.resize(distance(s.begin(), it));
    for (int i = 0; i < n; i++) {
    	v[a[i]].push_back(i + 1);
    }
    int k  = s.size();
    vector< pair<int, int> > b;
    for (int i = 0; i < k; i++) {
    	bool c = true;
        int l = 0;
        for (int j = 1; j < (int)v[s[i]].size(); j++) {
        	if(abs(v[s[i]][j] - v[s[i]][j - 1]) != l && j > 1) {
        		c = false;
        	}
        	l = abs(v[s[i]][j] - v[s[i]][j - 1]);
        }
        if(c) {
        	b.push_back(make_pair(s[i], l));
        }
    }
    cout << b.size() << endl;
    for (int i = 0; i < (int)b.size(); i++){
    	cout << b[i].first << ' ' << b[i].second << endl;
    }
	return 0;
}