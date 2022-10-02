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


using namespace std;


int n;
int a[100000];
int b[100000];
int c[100000];
map<int, int> m, m1, m2;


int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		m[a[i]]++;
	}
	for (int i = 0; i < n - 1; i++) {
		cin >> b[i];
		m1[b[i]]++;
	}
	for (int i = 0; i < n - 2; i++) {
		cin >> c[i];
		m2[c[i]]++;
	} 
	for (map<int, int>::iterator it = m.begin(); it != m.end(); it++) {
		pair<int, int> p = *it;
		if (m[p.first] != m1[p.first]) {
			cout << p.first << endl;
			break;
		}
	}
	for (map<int, int>::iterator it = m1.begin(); it != m1.end(); it++) {
		pair<int, int> p = *it;
		if (m2[p.first] != m1[p.first]) {
			cout << p.first << endl;
			break;
		}
	}
    return 0;
}