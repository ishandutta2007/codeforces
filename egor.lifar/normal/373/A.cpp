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

int main(){
	int k;
	cin >> k;
	vector<int> v, a;
	for (int i = 0; i < 16; i++) {
		char a;
		cin >> a;
		if(a != '.'){
			v.push_back(a - '0');
		}
	}
	sort(v.begin(), v.end());
	int m = 0;
	for (int i = 0; i <= v.size(); i++){
		if((i != v.size() && i > 0 && v[i] == v[i - 1]) || i == 0){
			m++;
		}else{
			a.push_back(m);
			m = 1;
		}
	}
	bool b = true;
	for (int i = 0; i < a.size(); i++){
		if(a[i] > 2 * k){
			b = false;
		}
	}
	if(b){
		cout << "YES" << endl;
	}else{
		cout << "NO" << endl;
	}
	return 0;
}