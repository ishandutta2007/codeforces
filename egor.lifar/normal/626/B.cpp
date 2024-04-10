#include <iostream>
#include <sstream>
#include <cmath>
#include <algorithm>
#include <string>
#include <string.h>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <bitset>
#include <queue>
#include <unordered_map>
#include <vector>

using namespace std;


int n;
map<char, int> cnt;



int main() {
	cin >> n;
	string s;
	cin >> s;
	for (int i = 0; i < n; i++) {
		cnt[s[i]]++;
	}
	if (cnt['G'] == 0 && cnt['B'] == 0) {
		cout << "R" << endl;
		return 0;
	}
	if (cnt['G'] == 0 && cnt['R'] == 0) {
		cout << "B" << endl;
		return 0;
	}
	if (cnt['R'] == 0 && cnt['B'] == 0) {
		cout << "G" << endl;
		return 0;
	}
	if (cnt['G'] != 0 && cnt['B'] != 0 && cnt['R'] != 0) {
		cout << "BGR" << endl;
		return 0;
	}
	vector<char> v;
	if (cnt['B'] == 0 || (cnt['B'] >= 1 && max(cnt['G'], cnt['R']) >= 2)) {
		v.push_back('B');
	} 
	if (cnt['G'] == 0 || (cnt['G'] >= 1 && max(cnt['B'], cnt['R']) >= 2)) {
		v.push_back('G');
	} 
	if (cnt['R'] == 0 || (cnt['R'] >= 1 && max(cnt['G'], cnt['B']) >= 2)) {
		v.push_back('R');
	} 
	for (int i = 0; i < (int)v.size(); i++) {
		cout << v[i];
	}
	cout << endl;
	return 0;
}