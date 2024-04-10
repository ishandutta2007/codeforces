#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
#include <queue>
#include <set>

using namespace std;

int n, a[100002], m, b[100002], c[100002];

int main(){
	cin >> n;
	cin >> m;
	set<int> s;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	for(int i = n - 1; i >= 0; i--){
		if(s.find(a[i]) == s.end()){
			c[i] += 1;
		}
		if(i < n - 1){
			c[i] += c[i + 1];
		}
		s.insert(a[i]);
	}
	for(int i = 0; i < m; i++){
		cin >> b[i];
	}
	for(int i = 0; i < m; i++){
		cout << c[b[i] - 1] << endl;
	}
	return 0;
}