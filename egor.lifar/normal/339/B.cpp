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
	int n, m;
	cin >> n >> m;
	int a[100001];
	for(int i = 1; i <= m; i++){
		cin >> a[i];
	}
	int k = 1;
	long long s = 0;
	for(int i = 1; i <= m; i++){
		if(a[i] >= k){
        	s += a[i] - k;
        	k = a[i];
		} else {
			s += n - k + a[i];
			k = a[i];
		}
	}
	cout << s << "\n";
	return 0;
}