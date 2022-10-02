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

int d[3000];

int main() {
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> d[i];
	}
	int a = 1;
	bool b = false;
	sort(d, d + m);
	for (int i = 0; i < m; i++) {
		if (i > 0 && d[i] == d[i - 1] + 1) {
			a++;
		} else {
			if(a > 2){
				b = true;
			}
			a = 1;
		} 
		if (d[i] == 1 || d[i] == n) {
			b = true;
		}
	}
	if(a > 2){
		b = true;
	}
	if (b) {
		cout << "NO" << endl;
	} else { 
		cout << "YES" << endl;
	}
	return 0;
}