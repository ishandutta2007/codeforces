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


int n, m;
int a[100];
int s = 0;
int ans = 1;


int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (s + a[i] <= m) {
			s += a[i];
		} else {
			s = a[i];
			ans++;
		}
	}
	cout << ans << endl;
    return 0;
}