#include <iostream>
#include <sstream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <unordered_map>


using namespace std;


#define M 1000000007;


int n, m;
string s[101];
set<int> ss[101];


int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s[i];
		for (int j = 0; j < m; j++) {
			ss[j].insert(s[i][j]);
		}
	}
	int k = (int)ss[0].size();
	for (int i = 1; i < m; i++) {
		k = (1LL * k * (int)ss[i].size()) % M;
	}
	cout << k << endl;
    return 0;   
}