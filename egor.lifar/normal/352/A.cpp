#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <algorithm>
#include <string>
#include <string.h>
#include <sstream>
 

using namespace std;

int main(){
	int n, a[10000];
	cin >> n;
	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	sort(a, a + n);
	int k = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == 5){
			k++;
		}
	}
	k = k - k % 9;
	bool b = false;
	vector<int> v;
	for(int i = 0; i < k; i++){
		b = true;
		v.push_back(a[n - 1]);
	}
	int i = 0;
	bool t = false;
	while(a[i] != 5){
		v.push_back(a[i]);
		t = true;
		if(b == false){
			break;
		}
		b = true;
		i++;
	}
	if((b == false && t == false) || t == false){
		cout << "-1\n";
		return 0;
	}
	for(int i = 0; i < (int)v.size(); i++){
		cout << v[i];
	}
	cout << "\n";
	return 0;
}