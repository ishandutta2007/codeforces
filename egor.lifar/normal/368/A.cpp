#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
 
using namespace std;

int main() {
	int n, d, a[1000], m;
	cin >> n >> d;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> m;
	int s = 0;
	sort(a, a + n);
	if(m > n){
		s -= d * (m - n);
	}
	for(int i = 0; i < min(n, m); i++){
		s += a[i];
	}
	cout << s << endl;
	return 0;
}